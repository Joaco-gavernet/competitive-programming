#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

vi min_prime; // min_prime[i] contiene el menor primo que divide a i, util para factorizar en log(i)

vi criba(ll n) {
    vb prime(n+1,true);
    min_prime.resize(n+1,INF);
    vi primos;
    for(ll p=2; p*p<=n; p++){
        if(!prime[p]) continue;
        for(ll i=p*p; i<=n; i += p) {
            prime[i] = false;
            min_prime[i] = min(min_prime[i],p);
        }
    }
    forr(i, 2, n+1){
        if(prime[i]) primos.pb(i), min_prime[i] = i;
    }
    return primos; // lista de primos hasta n
}

vi find_divisors(ll n, vi &primos) {
	vector <pair<ll,ll>> factor; 
	for(ll prime : primos) {
		int cont = 0;
		while(n % prime == 0) {
			cont++;
			n /= prime;
		}
		if(cont > 0) factor.pb({prime,cont});
	}
	
	if(n > 1) factor.pb({n,1});
	
	vi divisores = {1};
	for(auto [p,exp] : factor) {
		int tam = SZ(divisores);
		forn(i,exp) {
			forn(j,tam) {
				int pos = SZ(divisores)-tam;
				divisores.pb(divisores[pos] * p);
			}
		}
	}
		
	sort(all(divisores));
	return divisores;
}

int main(){  
  FIN;
  vi prim = criba(200000);
  int t;
  cin >> t;
  while(t--){
    int n; cin>>n;
    vector<int> bitpos(30,0);
    //vi num(n); 
    ll num; 
    forn(i,n){
      cin>>num;
      if(num!=0){
	for(int j=0;j<30;j++){
	  if(num&(1<<j)){bitpos[j]++;}
	}
      }
    }
    int mcd=-1;
    forn(i,30){
      if(bitpos[i]!=0){
	if(mcd==-1){mcd=bitpos[i];}
	else{mcd=gcd(mcd,bitpos[i]);}
      }
    }
    if(mcd==-1){
      forn(i,n){
	cout<<i+1<<" ";
      }
      cout<<"\n";
    }else{
      vi res=find_divisors(mcd,prim);
      for(auto u:res){cout<<u<<" ";} cout<<"\n";
    }
  }
  return 0;
}

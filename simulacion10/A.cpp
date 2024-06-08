/*   AUTHOR: Estufa en Piloto   */
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

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  ll d = gcd(b, a%b);
  return d;
}

vi find_divisors(ll n, vi &primos) {
  vector<pair<ll,ll>> factor;
  for (ll prime: primos) {
    int cont = 0;
    while (n%prime == 0) {
      cont++;
      n /= prime;
    }
    if (cont > 0) factor.pb({prime,cont});
  }

  if (n>1) factor.pb({n,1});

  vi divisores = {1};

  for (auto [p,exp] : factor) {
    int tam = SZ(divisores);
    forn(i,exp) {
      forn(j,tam) {
       int pos = SZ(divisores) -tam;
       divisores.pb(divisores[pos] *p);
      }
    }
  }
  sort(all(divisores));
  return divisores;
}

vi criba(ll n) {
  vb prime(n+1, true);
  vi primos;

  for (ll p=2; p*p <= n; p++) {
    if (!prime[p]) continue;
    for (ll i = p*p; i <= n; i+= p) {
       prime[i] = false;
    }
  }
  forr(i,2,n+1) {
    if (prime[i]) primos.pb(i);
  }
  return primos;
}


int main(){  
  FIN;
  int a, b;
  cin >> a >> b;
  a--; b--;
  int c=gcd(a,b);
  //cout << c << endl;
  vi primos=criba(1e7);
  vi divisores=find_divisors(c,primos);
  //cout << c << endl;
  //for(auto u : divisores) cout << u << " ";
  int ans=2;
  for(auto u : divisores){
    forr(i,1,u){
      if(i*i>=u) break;
      int k=u-i*i;
      int x=0,y=k;
      while(y-x>1){
	int med=(x+y)/2;
	if(med*med<k) x=med;
	else y=med;
      }
      if(y*y==k and gcd(y,i)==1 and y!=i){cout << y << " " << i << " " << u << endl; ans+=2;}
    }
    
  }
  if(a==b) ans/=2;
  cout << ans << "\n";
  return 0;
}

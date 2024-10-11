#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"

const ll INF = 1LL<<60; 

// Criba lineal, obtiene los primos menores al parametro
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
  while (n > 1) {
    ll prime = min_prime[n]; 
    int cont = 0; 
    while (n %prime == 0) {
      cont++; 
      n /= prime; 
    }
    factor.pb({prime,cont}); 
  }

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

const int MAXN = 1e7+5; 

int main() {
  FIN; 

  vi prims = criba(MAXN); 

  int n; cin >> n; 
  vi v(n); forn(i,n) cin >> v[i]; 
  sort(all(v)); 
  unordered_map<ll,ll> mp; 

  ll top = -1; 
  forn(i,n) {
    vi divs = find_divisors(v[i], prims); 
    for (ll d : divs) { 
      mp[d]++; 
      if (mp[d] == 2) top = max(d,top); 
    }
  }

  forn(i,n) if (v[i] %top != 0) {
    cout << "NO\n";
    return 0;
  }


  cout << "YES\n";
  return 0;
}

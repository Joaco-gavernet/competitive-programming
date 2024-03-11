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
  forr(i, 2, n+1) if(prime[i]) primos.pb(i), min_prime[i] = i;
  return primos; // lista de primos hasta n
}

int main(){  
  FIN;

  vi primos = criba(1e6+5);
  int n; cin >> n;
  vector<int> v(n);
  forn(i,n) cin >> v[i];
  unordered_map<int,int> cont;
  ll ans = 0;

  forn(i,n) {
    int x = v[i];
    set<int> s;
    while (x > 1) {
      s.insert(min_prime[x]);
      x /= min_prime[x];
    }
    if (v[i] == 1) {
      ans += i;
      continue;
    }
    vector<int> primos_que_aparecen;
    for (int u : s) primos_que_aparecen.pb(u);
    int cant_primos = SZ(s);
    int total = i;
    for (int mask = 1; mask < (1<<cant_primos); mask++) {
      int bits_prendidos = 0;
      int numero = 1;
      for (int bit = 0; bit < cant_primos; bit++) {
        if (mask & (1<<bit)) {
          bits_prendidos++;
          numero *= primos_que_aparecen[bit];
        }
      }
      if (bits_prendidos%2 == 1) total -= cont[numero];
      else total += cont[numero];
      cont[numero]++;
    }
    ans += total;
  }
  cout << ans << '\n';;


  return 0;
}

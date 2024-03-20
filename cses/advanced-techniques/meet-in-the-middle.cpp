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

int main(){  
  FIN;
  
  int n; ll x;
  cin >> n >> x;
  vector<ll> v(n);
  forn(i,n) cin >> v[i];
  if (n==1) {
    cout << (v[0]==x) << '\n';
    return 0;
  }

  int tam = n/2;
  vector<ll> l,r;
  forn(i,tam) l.pb(v[i]);
  forr(i,tam,n) r.pb(v[i]);

  vector<ll> sumas_l, sumas_r;
  int tam2 = n-tam;
  for (int mask = 0; mask < (1<<tam2); mask++) {
    ll suma = 0;
    forn(i,tam2) if (mask&(1<<i)) suma += r[i];
    sumas_r.pb(suma);
  }

  ll ans = 0;
  for (int mask = 0; mask < (1<<tam); mask++) {
    ll suma = 0;
    forn(i,tam2) if (mask&(1<<i)) suma += l[i];
    sumas_l.pb(suma);
  }

  sort(all(sumas_r));
  for (ll u: sumas_l) ans += upper_bound(all(sumas_r),x-u) - lower_bound(all(sumas_r),x-u);

  cout << ans << '\n';
  
  return 0;
}

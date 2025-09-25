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
const ll MAXL  = 2*1e12;
 
struct laptop {
  int i; ll a, b;
  bool operator<(const laptop &rhs) const {
    return a*rhs.b > b*rhs.a;
  }
};

int n, k; 
vector<laptop> L;
priority_queue<laptop> Q;

bool test(ll x) {
  // chequeo completo
  forn(t, k) {
    laptop l = Q.top(); Q.pop();
    if (l.a < t*l.b) return false;
    l.a += x; Q.push(l);
  }
  return true;
}
 
int main(){  
  FIN;
  cin >> n >> k;
  vi a(n), b(n);
  forn(i, n) cin >> a[i];
  forn(i, n) cin >> b[i];
  ll hi = 2e12+2, lo = 0;
  while (lo + 1 < hi) {
    L.clear();
    Q = priority_queue<laptop>;
    forn(i, n) {
      laptop l; l.i = i; l.a = a[i]; l.b = b[i];
      L.pb(l); Q.push(l);
    }
    ll mid = (lo + hi) / 2;
    if (test(mid-1)) hi = mid;
    else lo = mid;
  }
  if (lo > 2*mb*n) cout << -1 << endl;
  else cout << lo << endl;
  return 0;
}

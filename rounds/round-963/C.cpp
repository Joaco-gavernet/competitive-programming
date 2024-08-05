#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


void solve() {
  int n,k; cin >> n >> k;
  int mx = -1;
  vector<int> v(n); forn(i,n) cin >> v[i], mx = max(mx,v[i]);

  int a = mx;

  vector<pair<int,int>> db;
  int ons = 0;
  int ans = -1;
  for (int i: v) {
    pair<int,int> act = {0,0};
    int aux = (mx-i)/k;
    act.first = (i + (aux +1)*k) %mx;

    if (aux %2 == 0) ons++, act.second = -1;
    else act.second = 1;
    db.push_back(act);
  }

  if (ons == n) ans = mx;

  // check db sequentially
  sort(all(db));
  auto i = db.begin();
  while (ons < n and i < db.end()) {
    ons += (*i).second;
    if (ons < n) i++;
  }

  if (ans == -1 and ons == n) ans = mx + (*i).first;
  cout << ans << '\n';
}

int main(){
  FIN;

  int t; cin >> t;
  while (t--) solve();

  return 0;
}

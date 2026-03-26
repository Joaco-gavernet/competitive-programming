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

typedef pair<int,int> ii;
#define fs first
#define ss second


struct cmp {
  bool operator() (ii a, ii b) const {
    if (a.fs > b.fs or (a.fs == b.fs and a.ss < b.ss)) return true;
    else return false;
  }
};

void dbgs(multiset<ii,cmp> s) {
  for (auto i: s) dbg(i);
  RAYA;
}

void solve() {
  int n,k; cin >> n >> k;
  vector<int> a(n), b(n);
  multiset<pair<int,int>,cmp> s;
  forn(i,n) cin >> a[i];
  forn(i,n) {
    cin >> b[i];
    s.insert({a[i],b[i]});
  }
  // dbgs(s);

  ll ans = 0;
  while (k--) {
    int act = (*s.begin()).first;
    ans += act;
    auto p = *s.begin();
    s.erase(s.lower_bound(p));
    p.first = max(0, p.first -p.second);

    while (k and (p.fs > (*s.begin()).fs or (p.fs == (*s.begin()).fs and p.ss < (*s.begin()).ss))) {
      ans += p.fs;
      p.first = max(0, p.first -p.second);
      k--;
    }
    s.insert(p);
  }

  cout << ans << '\n';
}

int main(){
  FIN;

  int t; cin >> t;
  while (t--) {
    solve();
    RAYA;
  }


  return 0;
}

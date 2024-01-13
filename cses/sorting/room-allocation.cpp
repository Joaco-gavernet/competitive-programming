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

#define f first
#define s second

int main(){
  FIN;
  
  int n; cin >> n;
  vector<pair<ll,ll>> v(n); forn(i,n) cin >> v[i].f >> v[i].s;
  vector<pair<ll,ll>> s;
  forn(i,n) {
    s.pb(mp(v[i].first,-(i+1)));
    s.pb(mp(v[i].second,i+1));
  }
  sort(all(s));
  
  stack<int> q;
  int last = 0;
  vector<int> r(n);
  #define idx (abs(p.s)-1)
  
  for (auto p : s) {
    if (p.s < 0) {
      if (q.size() == 0) {
	last++;
	r[idx] = last;
      } else r[idx] = q.top(), q.pop();
    } else q.push(r[idx]);
  }
  
  cout << last << '\n';
  forn(i,n) cout << r[i] << ' ';
  
  return 0;
}






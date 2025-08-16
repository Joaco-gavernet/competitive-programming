#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const int INF = 1<<30; 

struct event {
  ll x, y, id; 
  bool operator < (struct event &b) const {
    if (x == b.x) return y < b.y;
    return x < b.x;
  } 
}; 

bool cmp(ii &a, ii &b) {
  if (a.ff == b.ff) return a.ss > b.ss;
  return a.ff < b.ff;
}

int ret() {
  cout << "syntax error\n"; 
  return 0;
} 

int main() {
  FIN;

  int n; cin >> n;  
  const int N = 2*n; 
  vector<ii> coords(N); 
  vector<event> x; 
  forn(i,N) {
    cin >> coords[i].ff >> coords[i].ss; 
    x.pb({coords[i].ss, coords[i].ff, i}); 
  }
  sort(all(x)); 

  vi ans(n, -1), ansi(n, -1); 
  set<ii> st; 
  for (auto [xi, yi, id]: x) {
    if (id < n) { // upper left corner 
      // check syntax error
      auto it = st.lower_bound({yi, 0}); 
      if (it != st.end() and (*it).ff == yi) return ret(); 

      st.insert({yi, id}); 
    } else { // lower right corner 
      // check if upper left corner available to match
      auto it = st.upper_bound({yi, INF}); 
      if (it == st.begin()) return ret(); 
      it--; 
      ans[(*it).ss] = id -n;
      ansi[id -n] = (*it).ss;
      st.erase(it); 
    }
  } 

  // check if no intersection between fixed rectangles 
  const int DB = 11; 
  st.clear(); 
  unordered_map<int, int> limits; 
  for (auto [xi, yi, id]: x) {
    if (id < n) { // upper left corner 
      // check possible intersections 
      auto it = st.lower_bound({yi, 0}); 
      if (it != st.end()) { // check after 
        int cid = ans[id] +n;
        if (coords[cid].ff >= (*it).ff) return ret(); 
      } 
      if (it != st.begin()) { // check before 
        --it; 
        auto [by, bx] = coords[(*it).ss]; 
        auto [bby, bbx] = coords[ans[(*it).ss] +n]; 
        auto [yii, xii] = coords[ans[id] +n]; 
        bool ok = false; 
        if (bbx < xi or bby < yi) ok = true; 
        if (by < yi and bx < xi and xii < bbx and yii < bby) ok = true; 
        if (ok == false) return ret(); 
      } 

      // check edge cases with past limits 
      // if (limits[xi] > 0 and limits[xi] >= coords[ans[id] +n].ss) return ret(); 
      st.insert({yi, id}); 
    } else { // lower right corner 
      auto itc = st.upper_bound({yi, INF}); 
      st.erase(--itc); 
      limits[xi] = coords[ansi[id -n]].ss; 
    }
  } 

  for (auto &x: ans) cout << x +1 << '\n'; 

  return 0;
}

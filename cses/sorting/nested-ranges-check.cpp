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
typedef array<int,3> triple;

#define f first
#define s second
#define endl '\n'

bool inc(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
  if (a.f.f == b.f.f) return a.f.s > b.f.s;
  return a.f.f < b.f.f; 
}

bool dec(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
  if (a.f.f == b.f.f) return a.f.s < b.f.s;
  return a.f.f > b.f.f; 
}

int main(){
  FIN;
  
  int n; cin >> n;
  vector<pair<pair<int,int>,int>> v(n); 
  forn(i,n) {
    cin >> v[i].f.f >> v[i].f.s;
    v[i].s = i;
  }
  
  vector<int> a(n);
  vector<int> b(n);
  
  // solving for b
  sort(all(v),inc); // sort: a.first < b.first and a.second > b.second
  int top = 0;
  for (auto p : v) {
    if (p.f.s <= top) b[p.s]++; // increment contained ranges
    top = max(p.f.s,top);
  }
  
  // solving for a
  sort(all(v),[](pair<pair<int,int>,int> x, pair<pair<int,int>,int> y) {
    if (x.f.f == y.f.f) return x.f.s < y.f.s;
    return x.f.f > y.f.f; 
  }); // sort: a.first > b.first and a.second < b.second
  int down = INF;
  for (auto p : v) {
    if (p.f.s >= down) a[p.s]++; // increment container ranges
    down = min(p.f.s,down);
  }
  
  forn(i,n) cout << a[i] << ' ';
  cout << endl;
  forn(i,n) cout << b[i] << ' ';
  
  return 0;
}

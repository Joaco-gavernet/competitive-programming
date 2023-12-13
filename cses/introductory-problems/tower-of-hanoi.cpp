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

vector<pair<int,int>> r;
void f(int o, int d, int z);

void calls(int o, int d, int z, int x) {
  f(o,x,z-1);
  r.pb({o,d});
  f(x,d,z-1);
}

// o - origin
// d - destiny
// z - disks to top
void f(int o, int d, int z) {
  if (z != 1) {
    if (o == 1) {
      if (d == 2) calls(o,d,z,3);
      if (d == 3) calls(o,d,z,2);
    }
    if (o == 2) {
      if (d == 1) calls(o,d,z,3);
      if (d == 3) calls(o,d,z,1);
    }
    if (o == 3) {
      if (d == 1) calls(o,d,z,2);
      if (d == 2) calls(o,d,z,1);
    }
    
  } else r.pb({o,d}); // base case
}

int main(){
  FIN;
  
  int n; cin >> n;
  
  int tot = (1 << n) - 1; // pow(two,n)
  cout << tot << '\n';
  
  f(1,3,n);
  for (auto p : r)
    cout << p.first << " " << p.second << '\n';
  
  return 0;
}






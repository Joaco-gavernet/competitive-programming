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
const int MAXN = (int)(1e9+5);


int main(){
  FIN;

  int t; cin >> t;
  while (t--) {
    int n,c,d; cin >> n >> c >> d;

    map<int,int> vals;
    int minval = MAXN;
    forn(i,n) forn(j,n) {
      int act; cin >> act;
      minval = min(minval,act);
      vals[act]++;
    }

    vector<vector<int>> m(n, vector<int>(n,0));
    m[0][0] = minval;
    vals[minval]--;

    bool result = true;
    forn(i,n-1) {
      forn(j,n-1) {
        if (m[i+1][j] != m[i][j] +c) {
          if (vals[m[i][j] +c]) {
            vals[m[i][j] +c]--; 
            m[i+1][j] = m[i][j] +c;
          } else result = false;
        }

        if (m[i][j+1] != m[i][j] +d) {
          if (vals[m[i][j] +d]) {
            vals[m[i][j] +d]--; 
            m[i][j+1] = m[i][j] +d;
          } else result = false;
        }

        if (result == false) break;
      }
      if (result == false) break;
    }

    if (vals[m[n-1][n-2] +d] == 0) result = false;
    else if (vals[m[n-2][n-1] +c] == 0) result = false;

    if (result == true) cout << "YES\n";
    else cout << "NO\n";
  }
  
  
  return 0;
}

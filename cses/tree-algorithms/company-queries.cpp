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
const ll INF = -1; // (1LL<<60)
const int MAXN = 3e5+5;
const int LOG = 30;


int main(){
  FIN;

  int n,q; cin >> n >> q;
  vector<vector<int>> t(MAXN,vector<int>(LOG,INF));

  int act; 
  forr(i,1,n) {
    cin >> act;
    t[i][0] = (--act); // direct boss of ith employee
  }

  // preprocessing sparse table
  forr(i,1,LOG) {
    forn(x,MAXN) {
      if (t[x][i-1] == INF) t[x][i] = INF;
      else t[x][i] = t[t[x][i-1]][i-1];
    }
  }
  
  // binary lifting
  while (q--) {
    int x,k; cin >> x >> k; x--;

    int ans = -1;
    for (int i = LOG-1; i >= 0; i--) {
      if (k == (1<<i)) {
        ans = t[x][i]; 
        if (ans != INF) ans++;
        break;
      } else if (k > (1<<i) and t[x][i] != INF) x = t[x][i], k -= (1<<i); 
    }

    cout << ans << '\n';
  }
  
  
  return 0;
}

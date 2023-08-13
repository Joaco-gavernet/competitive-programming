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


int main(){
  FIN;
  
  int t; cin >> t;
  
  forn(h,t) {
    
    int k,n,m; cin >> k >> n >> m;
    vector<int> j1(n);
    vector<int> j2(m);
    vector<int> res;
    bool ok = true;
    
    forn(i,n) cin >> j1[i];
    forn(i,m) cin >> j2[i];
    
    int i_j1 = 0, i_j2 = 0;
    
    while (i_j1 < n or i_j2 < m) {

      while (i_j1 < n and j1[i_j1] <= k) {
	if (j1[i_j1] == 0) k++;
	res.pb(j1[i_j1]);
	i_j1++;
      }
      
      if (i_j2 < m and j2[i_j2] > k) {
	ok = false;
	break;
      }

      while (i_j2 < m and j2[i_j2] <= k) {
	if (j2[i_j2] == 0) k++;
	res.pb(j2[i_j2]);
	i_j2++;
      }
      
      if (i_j1 < n and j1[i_j1] > k) {
	ok = false;
	break;
      }
    }
    
    if (ok == false) cout << "-1";
    else forn(i,(n+m)) cout << res[i] << " ";
    cout << "\n";
  }
  
  
  
  return 0;
}

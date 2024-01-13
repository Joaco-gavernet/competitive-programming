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
  
  int n,x; cin >> n >> x;
  vector<pair<int,int>> v(n); 
  forn(i,n) {
    cin >> v[i].f;
    v[i].s = (i+1);
  }
  sort(all(v));
  
  forn(j,n) {
    forr(i,j+1,n) {
      if (v[j].f + v[i].f >= x) break;
      
      int l = i;
      int r = n;
      
      while (l < r-1) {
	int m = l + (r-l)/2;
	
	if (v[j].f + v[i].f + v[m].f > x) r = m;
	else l = m;
      }
      
      if (l != i and v[j].f + v[i].f + v[l].f == x) { 
	cout << v[j].s << " " << v[i].s << " " << v[l].s << '\n';
	goto endLoops;
      }
    }
  }
  
  cout << "IMPOSSIBLE";
  
  endLoops:
  
  return 0;
}









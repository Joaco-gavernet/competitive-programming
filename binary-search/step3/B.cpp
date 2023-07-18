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
  
  int n, k; cin >> n >> k;
  vector<int> nums(n,0); forn(i,n) cin >> nums[i];
  
  int l = 0;
  int r = MAXN;  
  int minMaxSum = MAXN;
  
  while (r > l + 1) {
    int m = (l+r)/2;
    int segments = 1;
    int maxSum = 0;
    dbg(l,m,r);
    
    int actSum = 0;
    forn (i,n) {
      if (nums[i] >= m) {
	minMaxSum = nums[i];
	segments = k;
	dbg(i,nums[i],m);
	break;
      }
      if (actSum + nums[i] <= m) {
	actSum += nums[i];
      } else {
	segments++;
	if (i + 1 < n) i--;
	maxSum = max(actSum,maxSum);
	actSum = 0;
      }
    }
    
    if (segments == k && maxSum < minMaxSum) l = m, minMaxSum = maxSum;
    else r = m;
  }
  cout << l << "\n";
  
  return 0;
}

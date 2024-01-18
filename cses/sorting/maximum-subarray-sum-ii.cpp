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
#define pi pair<ll,ll>
#define f first
#define s second
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main(){
  FIN;
  
  int n,a,b; cin >> n >> a >> b;
  vector<int> v(n); forn(i,n) cin >> v[i];
  vector<ll> pSum(n+1);
  pSum[1] = v[0];
  forr(i,1,n+1) pSum[i] = pSum[i-1] + v[i-1];
  dbg(pSum);
  
  ll l = 0;
  ll r = 1;
  ll ans = -INF;
  indexed_set mins;
  mins.insert({pSum[1],1});
  while (r<n+1) {
    if (a > r-l) {
      r++;
      mins.insert({pSum[r],r});
    }
    else if (r-l > b) {
      l++;
      mins.erase({pSum[l],l});
    }
    else {
      pi min = *mins.find_by_order(0);
      
      // update l intelligently
      if (a <= r-min.s) {
	while (pSum[l] > min.f and l < r-1) {
	  l++;
	  mins.erase({pSum[l],l});
	}
      }
      
      ans = max(pSum[r]-pSum[l],ans);
      r++;
    }
  }
  
  cout << ans << '\n';
  
  return 0;
}





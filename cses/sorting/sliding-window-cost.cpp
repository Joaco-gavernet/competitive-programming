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
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define pi pair<ll,ll>
#define f first
#define s second
#define sz s.size()

 
using namespace __gnu_pbds;
using namespace std;
typedef tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


ll n, k; 
indexed_set s; // ordered_set
// x is low if pos(x) <= pos(median)
// x is up if pos(x) > pos(median)
ll sLow = 0, sUp = 0; // group sums
ll contLow = 0, contUp = 0; // group size 
ll idx_m = 0; // find fixed index of median in s

indexed_set::iterator med() { return (k % 2) ? (s.find_by_order(sz>>1)) : (s.find_by_order((sz>>1)-1)); }

void er(ll val, ll i) {
  if ((ll)s.order_of_key({val,i}) <= idx_m) sLow -= val, contLow--;
  else sUp -= val, contUp--;
  s.erase({val,i});
}

void ins(ll val, ll i) {
  s.insert({val,i});
  if ((ll)s.order_of_key({val,i}) <= idx_m) { // check group of inserted element
    sLow += val, contLow++;
    if (contLow > (k+1)/2) { // rebalance groups from low --> up
      contLow--, contUp++;
      ll aux = (*(++med())).f;
      sLow -= aux, sUp += aux;
    }
  } else {
    sUp += val, contUp++;
    if (contUp > k/2) { // rebalance groups from up --> low
      contUp--, contLow++;
      ll aux = (*med()).f;
      sUp -= aux, sLow += aux;
    }
  }
}

int main(){
  FIN;
  
  cin >> n >> k;
  vector<ll> v(n); forn(i,n) cin >> v[i];
  ll tot = n-k+1; // total windows to cost
  
  forn(i,k) s.insert({v[i],i}); // init first window with k elements
  idx_m = k/2 -!(k&1); // bit operators
  
  ll pos = 0;
  for (pi p : s) {
    if (pos <= idx_m) sLow += p.f, contLow++;
    else sUp += p.f, contUp++;
    pos++;
  }

  forn(i,tot) {
    ll extra = 0;
    if (k%2 == 1) extra = (*med()).f; // if imparity, don't consider the median in the sums
    cout << sUp - sLow + extra << ' '; // total cost as difference of sums
    
    er(v[i],i); // erase first element in window
    if (i+k < n) ins(v[i+k],i+k); // insert new element in window
  }
  
  return 0;
}

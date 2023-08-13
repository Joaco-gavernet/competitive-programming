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


// The function returns maximum
// circular contiguous sum in a[]
ll maxCircularSum(vector<ll> &a, int n)
{
    // Corner Case
    if (n == 1)
        return a[0];
 
    // Initialize sum variable which store total sum of the array.
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
 
    // Initialize every variable with first value of array.
    ll curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];
 
    // Concept of Kadane's Algorithm
    for (int i = 1; i < n; i++) {
        // Kadane's Algorithm to find Maximum subarray sum.
        curr_max = max(curr_max + a[i], a[i]);
        max_so_far = max(max_so_far, curr_max);
 
        // Kadane's Algorithm to find Minimum subarray sum.
        curr_min = min(curr_min + a[i], a[i]);
        min_so_far = min(min_so_far, curr_min);
    }
 
    if (min_so_far == sum)
        return max_so_far;
 
    // returning the maximum value
    return max(max_so_far, sum - min_so_far);
}


int main(){
  FIN;
  
  int t; cin >> t;
  
  forn(i,t) {
    ll n; cin >> n;
    vector<ll> a(n); forn(j,n) cin >> a[j];
    vector<ll> b(n); forn(j,n) cin >> b[j];
    vector<ll> mixed(2*n); forn(j,n) mixed[j] = a[j]; forn(j,n) mixed[j+n] = b[j];
    ll firstResult = maxCircularSum(mixed,(int)(2*n));
    
    vector<ll> prefa(n); prefa[0] = a[0];
    for (ll j = 1; j < n; j++) prefa[j] = prefa[j-1] + a[j];
    
    vector<ll> prefb(n); prefb[0] = b[0]; 
    for (ll j = 1; j < n; j++) prefb[j] = prefb[j-1] + b[j];
    //~ dbg(prefa,prefb);
    
    vector<ll> dif(n);
    forn(j,n) dif[j] = prefa[j] - prefb[j];
    auto it = max_element(dif.begin(),dif.end());
    ll index = (ll)distance(dif.begin(),it);
    ll k;
    k = index + 1;
    //~ if (dif[index] <= 0) k = 0;
    //~ else k = index + 1;
    //~ dbg(dif,k);
    
    vector<ll> last(4*n, 0);
    forn(j,k) last[j] = b[j];
    for (ll j = k; j < n; j++) last[j] = a[j];
    forn(j,k) last[n + j] = a[j];
    for (ll j = k; j < n; j++) last[n + j] = b[j];
    for (ll j = 0; j < 2*n; j++) last[j + 2*n] = last[j];
    //~ dbg(last);
    //~ RAYA;
    
    
    //~ ll max_so_far = INT_MIN, max_ending_here = 0;
    //~ ll cont =0;
    //~ for (ll j = 0; j < (4*n); j++) {
      //~ max_ending_here = max_ending_here + last[j];
      //~ if (cont < (2*n) and max_so_far < max_ending_here) {
	  //~ max_so_far = max_ending_here;
	  //~ cont++;
      //~ }

      //~ if (max_ending_here < 0) {
	  //~ max_ending_here = 0;
	  //~ cont = 0;
      //~ }
    //~ }
    //~ cout << max_so_far << "\n";
    
    ll secondResult = maxCircularSum(last,(int)(2*n));
    if (firstResult > secondResult) cout << firstResult << "\n";
    else cout << secondResult << "\n";
    
  }
  
  
  
  return 0;
}

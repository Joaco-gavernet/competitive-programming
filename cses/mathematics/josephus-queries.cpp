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

#define a v[i].first
#define b v[i].second


int solve(int n, int k, bool one) {
  int res = 0;
  
  if (one == true and 2*k <= n) // check base case for even
    res = 2*k; 
  else if (one == false and 2*k-1 <= n) // check base case for odd
    res = 2*k-1;
  else {
    // set newN and newK next step in recursion
    int newN = n/2+(n&1);
    if (n%2 == 1 and one == false) newN -= 1;
    int newK = k-(n-newN);
    
    // consider n even (keep order) or odd (alternate order)
    if (n%2==0) {
      if (one == true) res = 2*solve(newN,newK,one)-1;
      else res = 2*solve(newN,newK,one);
    } else {
      if (one == true) res = 2*solve(newN,newK,!one)-1;
      else res = 2*solve(newN,newK,!one);
    }
  }
  return res;
}


int main(){
  FIN;
  
  int t; cin >> t;
  vector<pair<int,int>> v(t); 

  forn(i,t) {
    cin >> a >> b;
    
    cout << solve(a,b,true) << '\n';
  }
  
  return 0;
}






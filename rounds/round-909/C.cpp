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

bool f(int a, int b) {
  return abs(b-a) % 2 == 1;
}

int main(){
  FIN;
  int t; cin >> t;
  
  forn(_,t) {
    int n; cin >> n;
    vector<int> v(n+1); forr(i,1,n+1) cin >> v[i];
    vector<int> pSum(n+1); // prefix sum array considering parity
    
    int ans = -MAXN;
    
    pSum[1] = v[1];
    forr(i,2,n+1) {
      if (f(v[i],v[i-1])) pSum[i] = pSum[i-1] + v[i];
      else pSum[i] = v[i];
    }
    //~ dbg(v);
    //~ dbg(pSum);
    
    // two pointers
    int l = 0;
    int r = 1;
    
    do {
      if (f(v[r-1],v[r]) == 0) l = 0;
      //~ dbg(l,r,ans,pSum[r]-pSum[l]);
      ans = max(ans,pSum[r]-pSum[l]);
      if (pSum[r]-pSum[l] < 0) l = r;
      r++;
    } while (r < n + 1);
  
    cout << ans << '\n';
  }
  
  
  return 0;
}















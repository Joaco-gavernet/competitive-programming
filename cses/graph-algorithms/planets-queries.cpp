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
const ll LOG = 30; // check ???????????????????????????
const int MAXN = (int)(2e5+5);


int log2(int x) {
  return sizeof(int)*8 -1 -__builtin_clz(x);
}

int main(){
  FIN;

  vector<int> t(MAXN*LOG, INF); // sparse table in 1D to void double indirection
  int n,q; cin >> n >> q;
  forr(i,1,n+1) cin >> t[i*LOG];
  
  // preprocessing sparse table
  for(int j = 1; j < LOG; j++) {
    forn(i,MAXN) { // check if (MAXN or N) ???
      if (t[i*LOG + j-1] == INF) t[i*LOG + j] = INF;
      else t[i*LOG + j] = t[t[i*LOG + j-1]*LOG + j-1];
    }
  }
    
  // solving queries online in O(log2(n)) 
  forn(i,q) {
    int x,k; cin >> x >> k;
    
    if (k == 0) cout << x << '\n';
    else {
      int j = log2(k);
      k -= (1<<j);
      while (k > 0) {  
        x = t[x*LOG + j];
        j = log2(k);
        k -= (1<<j);
      }
      cout << t[x*LOG + j] << '\n';
    }
  }
  
  return 0;
}











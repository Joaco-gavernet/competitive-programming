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

//rotate Left
void r_left(int *a,int n) 
{ 
  int tmp=a[0];
  memmove(a,a+1,sizeof(int)*(n-1));
  a[n-1]=tmp;
} 
//rotate right
void r_right(int *a,int n) 
{ 
    int tmp=a[n-1];
    memmove(a+1,a,sizeof(int)*(n-1));
    a[0]=tmp;
 } 

int main(){
  FIN;
  int t; cin >> t;
  
  forn(_,t) {
    int n, k; cin >> n >> k;
    vector<int> v(n); forn(i,n) cin >> v[i];
    int ops = 0; // total available ops 
    int rots = 0; // current rotations to right
    
    //~ DBG("pre");
    r_left(&v[0],n); rots++;
    while (rots < n) {
      DBG(rots);
      if (v[rots] == rots) ops++,rots=0;
      
      r_left(&v[0],n); rots++;
    }
    
    
    if (ops == k) cout << "YES\n";
    else cout << "NO\n";
    
  }
  
  return 0;
}













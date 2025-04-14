#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

// Idea: use centroid decomposition carrying "how many nodes at depth x" and add posible combinations 

const int MAXN = 10; 
struct centroid {
  vector<vector<int>> g; int n;
  vector<vector<int>> c_tree;
  bool tk[MAXN];
  int fat[MAXN]; // father in centroid decomposition
  int szt[MAXN]; // size of subtree
  int centro = -1;
  ll ans = 0; 

  int calcsz(int x, int f){
    szt[x] = 1;
    for (auto y: g[x]) if(y != f and tk[y]) szt[x] += calcsz(y,x);
    return szt[x];
  }

  void cdfs(int x=0, int f=-1, int sz=-1){ // O(nlogn)
    if (sz < 0) sz = calcsz(x,-1);
    for(auto y: g[x]) if (!tk[y] and szt[y]*2 >= sz) {
      szt[x] = 0;
      cdfs(y,f,sz);
      return;
    }
    tk[x] = true;
    fat[x] = f;
    for(auto y: g[x]) if (!tk[y]) cdfs(y,x);
  }

  centroid(vector<vector<int>> gg, int nn) {
    g = gg; n = nn; 
    memset(tk,false,sizeof(tk));
    cdfs();
    c_tree.resize(n);
    forn(i,n) {
      if(fat[i] == -1) centro = i;
      else c_tree[fat[i]].pb(i);
    }
  }
};


int main(){
  FIN;

  int n, k; cin >> n >> k; 
  vector<vector<int>> g(n); 
  forn(_,n-1) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
  } 

  centroid ds(g, n); 
  dbg(ds.centro); 
  forn(i,n) dbg(i, ds.c_tree[i]); 
  cout << ds.ans << '\n'; 


  return 0;
}

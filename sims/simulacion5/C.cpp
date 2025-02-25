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

int n,m;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int dfs(int y, int x, vector<string> &g, int cont) {
  int ans = 0;
  g[y][x] = '#';
  forn(i,4) {
    if ((y+dy[i]>0)&&(x+dx[i]>0)&&(y+dy[i]<n)&&(x+dx[i]<m)&&(g[y+dy[i]][x+dx[i]] == '.')) {
      ans = dfs(y+dy[i],x+dx[i],g,cont+1); 
      if((ans%2)!=(cont%2)){
	g[y][x] = '.'; return (cont+1)%2;
      }
    }
  }
  g[y][x] = '.';
  return cont%2;
}

int main(){
  FIN;

  cin >> n >> m;

  vector<string> g(n);
  forn(i,n) cin >> g[i];
  ll ans=0;
  forn(i,n){
    forn(j,m){
      if (g[i][j] == '.'){ans+=dfs(i,j,g,1); cout<<i<<j<<ans<<endl;}
    }
  }
  cout<<ans<<"\n";
  return 0;
}

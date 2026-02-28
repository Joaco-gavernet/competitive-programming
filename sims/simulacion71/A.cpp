#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define ff first
#define ss second

int dx[4]={0,0,-1,1}, dy[4]={-1,1,0,0};
int n, m;
vector <string> s(1000);
vector <vi> comp(1000,vi(1000,-1));

void dfs(int x, int y, int c){
  comp[x][y]=c;
  forn(i,4) if(x+dx[i]>=0 and x+dx[i]<n and y+dy[i]>=0 and y+dy[i]<m and comp[x+dx[i]][y+dy[i]]!=c and s[x+dx[i]][y+dy[i]]=='.') dfs(x+dx[i],y+dy[i],c);
}

void solve(){
  cin >> n >> m;
  forn(i,n) cin >> s[i];
  int c=0;
  forn(i,n) forn(j,m) comp[i][j]=-1;
  forn(i,n) forn(j,m) if(comp[i][j]==-1 and s[i][j]=='.'){
    dfs(i,j,c);
    c++;
  }
  vector <vii> g(c);
  forn(i,n) forn(j,m) if(s[i][j]=='.') g[comp[i][j]].pb({i,j});
  ll ans=0;
  forn(i,c){
    bool anda=true;
      forn(x,n) forn(y,m) if(s[x][y]=='.' and (x!=g[i][0].ff or y!=g[i][0].ss)){
      bool rompe=true;
      forn(t,SZ(g[i])) if(x+g[i][t].ff-g[i][0].ff<0 or x+g[i][t].ff-g[i][0].ff>=n or y+g[i][t].ss-g[i][0].ss<0 or y+g[i][t].ss-g[i][0].ss>=m or comp[x][y]!=comp[x+g[i][t].ff-g[i][0].ff][y+g[i][t].ss-g[i][0].ss]) rompe=false;
      if(rompe) anda=false;
    }
    if(anda) ans+=SZ(g[i]);
  }
  cout << ans << "\n";
}

int main() {
  NaN;
  int t; cin >> t;
  while(t--) solve();
  return 0;
}
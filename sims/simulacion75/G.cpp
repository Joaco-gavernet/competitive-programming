#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================\n"


const int MAXN = 250005; 
vector<vi> succ(MAXN, vi(32)); 
vb vis(MAXN, false); 
vi len(MAXN);

void dfs_topo(int v) {
  vis[v] = true; 
  int u = succ[v][0]; 
  if (!vis[u]) dfs_topo(u); 
  len[v] = len[u] + 1; 
}

int go(int x, int d) {
  if (d <= 0) return x; 
  int i = 0; 
  while (d) {
    if (d&1) x = succ[x][i]; 
    d >>= 1; 
    i++; 
  }
  return x; 
}

vector <vb> visto(500,vb(500,false));
vector <string> s(500);
vi dx={-1,1,0,0}, dy={0,0,-1,1};
void dfs(int i, int j, int n, int m, vector <vi> &ans){
  visto[i][j]=true;
  if(s[i][j]=='^' and i!=0 and s[i-1][j]!='#' and s[i-1][j]!='.'){
    if(!visto[i-1][j]) dfs(i-1,j,n,m,ans);
    ans[i][j]+=ans[i-1][j];
  }
  if(s[i][j]=='<' and j!=0 and s[i][j-1]!='#' and s[i][j-1]!='.'){
    if(!visto[i][j-1]) dfs(i,j-1,n,m,ans);
    ans[i][j]+=ans[i][j-1];
  }
  if(s[i][j]=='>' and j!=m-1 and s[i][j+1]!='#' and s[i][j+1]!='.'){
    if(!visto[i][j+1]) dfs(i,j+1,n,m,ans);
    ans[i][j]+=ans[i][j+1];
  }
  if(s[i][j]=='v' and i!=n-1 and s[i+1][j]!='#' and s[i+1][j]!='.'){
    if(!visto[i+1][j]) dfs(i+1,j,n,m,ans);
    ans[i][j]+=ans[i+1][j];
  }
}

vector <pair<ll,ll>> ciclo;
void dfs_ciclo(int i, int j, int n, int m){
  visto[i][j]=true;
  ciclo.pb({i,j});
  if(s[i][j]=='^' and i!=0 and s[i-1][j]!='#' and s[i-1][j]!='.') if(!visto[i-1][j]) dfs_ciclo(i-1,j,n,m);
  if(s[i][j]=='<' and j!=0 and s[i][j-1]!='#' and s[i][j-1]!='.') if(!visto[i][j-1]) dfs_ciclo(i,j-1,n,m);
  if(s[i][j]=='>' and j!=m-1 and s[i][j+1]!='#' and s[i][j+1]!='.') if(!visto[i][j+1]) dfs_ciclo(i,j+1,n,m);
  if(s[i][j]=='v' and i!=n-1 and s[i+1][j]!='#' and s[i+1][j]!='.') if(!visto[i+1][j]) dfs_ciclo(i+1,j,n,m);
}

int main() {
  FIN;
  int n, m; cin >> n >> m;
  forn(i,n) cin >> s[i];
  forn(i,n*m) succ[i][0]=i;
  forn(i,n) forn(j,m){
    if(s[i][j]=='^' and i!=0) succ[i*m+j][0]=(i-1)*m+j;
    if(s[i][j]=='<' and j!=0) succ[i*m+j][0]=i*m+j-1;
    if(s[i][j]=='>' and j!=m-1) succ[i*m+j][0]=i*m+j+1;
    if(s[i][j]=='v' and i!=n-1) succ[i*m+j][0]=(i+1)*m+j;
  }
  forr(j,1,32) forn(i,n*m) succ[i][j]=succ[succ[i][j-1]][j-1];
  forn(i,n*m) if(!vis[i]) dfs_topo(i);
  vector <vi> color(n,vi(m));
  int cnt=1;
  forn(i,n) forn(j,m) if(!visto[i][j] and s[i][j]!='#' and s[i][j]!='.' and i*m+j==go(i*n+j,len[i*n+j])){
    dfs_ciclo(i,j,n,m);
    for(auto [x,y] : ciclo) color[x][y]=cnt;
    cnt++;
    ciclo.clear();
  }
  forn(i,n) forn(j,m) visto[i][j]=false;
  vector <vi> ans(n,vi(m));
  forn(i,n) forn(j,m) if(s[i][j]=='#'){
    forn(k,4){
      int ni=i+dx[k], nj=j+dy[k];
      if(ni<0 or ni>=n or nj<0 or nj>=m) continue;
      if(s[ni][nj]=='#' or s[ni][nj]=='.') continue;
      bool anda=true;
      if(color[ni][nj]==0){
        int z=go(ni*m+nj,len[ni*m+nj]);
        forn(t,4) if(t!=k){
          int x=i+dx[t], y=j+dy[t];
          if(x<0 or x>=n or y<0 or y>=m) continue;
          if(go(ni*m+nj,len[ni*m+nj]-len[x*m+y])==x*m+y or go(z,len[z]-len[x*m+y])==x*m+y) anda=false;
        }
      }
      else{
        forr(t,k+1,4){
          int x=i+dx[t], y=j+dy[t];
          if(x<0 or x>=n or y<0 or y>=m) continue;
          if(color[x][y]==color[ni][nj]) anda=false;
        }
      }
      if(anda) ans[ni][nj]++;
    }
  }
  // forn(i,n){
  //   forn(j,m) cout << ans[i][j] << " ";
  //   cout << endl;
  // }
  forn(i,n) forn(j,m) if(!visto[i][j] and i*m+j==go(i*n+j,len[i*n+j])){
    dfs_ciclo(i,j,n,m);
    ll sum=0;
    for(auto [x,y] : ciclo) sum+=ans[x][y];
    for(auto [x,y] : ciclo) ans[x][y]=sum;
    ciclo.clear();
  }
  forn(i,n) forn(j,m) if(!visto[i][j]) dfs(i,j,n,m,ans);
  ll res=0;
  forn(i,n) forn(j,m) res=max(res,ans[i][j]);
  cout << res << "\n";
  return 0;
}
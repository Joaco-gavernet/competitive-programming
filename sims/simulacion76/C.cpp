#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cout << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

int n, m;
vi dx={1,-1,0,0}, dy={0,0,1,-1};

bool check(int x, int y){
  if(x<0 or y<0 or x>=n or y>=m) return false;
  return true;
}

void dfs(int x, int y, vector <vi> &g, vector<vb> &visto){
  visto[x][y]=true;
  forn(t,4) if(check(x+dx[t],y+dy[t]) and !visto[x+dx[t]][y+dy[t]] and g[x+dx[t]][y+dy[t]]==1) dfs(x+dx[t],y+dy[t],g,visto);
}

int main() {
  FIN;
  int o; cin >> n >> m >> o;
  vector <vi> v(n,vi(m));
  forn(i,o){
    int a, b; cin >> a >> b;
    a--; b--;
    v[a][b]=1;
  }
  if(o==n*m) {cout << "-1\n"; return 0;}
  vector <vi> s(n+1,vi(m+1));
  forn(i,n) forn(j,m) s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+v[i][j];
  int l=0, r=min(n,m)+1;
  while(r-l>1){
    int med=(r+l)/2;
    vector <vi> p(n,vi(m));
    forn(i,n-med+1) forn(j,m-med+1) if(s[i+med][j+med]+s[i][j]-s[i+med][j]-s[i][j+med]==0) p[i][j]=1;
    vector <vi> S(n+1,vi(m+1));
    forn(i,n) forn(j,m) S[i+1][j+1]=S[i][j+1]+S[i+1][j]-S[i][j]+p[i][j];
    bool anda=true;
    ll cont=0;
    vector <vb> visto(n,vb(m));
    forn(i,n) forn(j,m) if(!visto[i][j] and p[i][j]==1) {dfs(i,j,p,visto); cont++;}
    if(cont!=1) anda=false;
    forn(i,n) forn(j,m) if(v[i][j]==0 and S[i+1][j+1]+S[max(0LL,i-med)][max(0LL,j-med)]-S[i+1][max(0LL,j-med)]-S[max(0LL,i-med)][j+1]==0) anda=false;
    if(anda) l=med;
    else r=med;
  }
  if(l>0) cout << l << "\n";
  else cout << "-1\n";
  return 0; 
}
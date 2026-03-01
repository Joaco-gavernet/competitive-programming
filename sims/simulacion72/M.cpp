#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"


struct vertex {
  map<char, int> next, go;
  int p, link, nextleaf;
  char pch;
  vi leaf;
  vertex(int p = -1, char pch = -1, int nextleaf = -1) : p(p), pch(pch), link(-1), nextleaf(nextleaf) {}
};

vector<vertex> t;
vector<vi> g(3e5); 

void aho_init() {
  t.clear(); t.pb(vertex());
}

void add_string(string s, int id) {
  int v = 0;
  for (char c: s) {
    if (!t[v].next.count(c)) {
      t[v].next[c] = SZ(t); 
      t.pb(vertex(v, c)); 
    }
    v = t[v].next[c]; 
  }
  t[v].leaf.pb(id); 
}
int go (int v, char c);
int get_link(int v) {
  if (t[v].link < 0) {
    if (v == 0 or t[v].p == 0) t[v].link = 0; 
    else t[v].link = go(get_link(t[v].p), t[v].pch); 
    g[t[v].link].pb(v); 
  }
  return t[v].link; 
}
int go(int v, char c) {
  if (!t[v].go.count(c)) {
    if (t[v].next.count(c)) t[v].go[c] = t[v].next[c]; 
    else t[v].go[c] = v == 0 ? 0 : go(get_link(v), c); 
  }
  return t[v].go[c]; 
}
int init_next_leaf(int v) {
  if (v == 0) t[v].nextleaf = 0;
  if (t[get_link(v)].leaf.size()) return t[v].nextleaf = get_link(v); 
  else return t[v].nextleaf = t[get_link(v)].nextleaf != -1 ? t[get_link(v)].nextleaf : init_next_leaf(get_link(v)); 
}
void construct_links() {
  forn(i,t.size()) get_link(i); 
}

struct ter{
  int x, y, z;
};

const int INF=1e9;

int main() {
  NaN;
  int n, m, k; cin >> n >> m >> k;
  vector <vector<char>> v(n,vector<char>(m));
  forn(i,n) forn(j,m) cin >> v[i][j];
  aho_init();
  forn(i,k){
    string s; cin >> s;
    add_string(s,i);
  }
  k=SZ(t);
  vector <vector<vi>> dp(n,vector<vi>(m,vi(k,INF)));
  queue <ter> q;
  forn(j,m) if(t[0].next.count(v[0][j])){
    dp[0][j][t[0].next[v[0][j]]]=1;
    q.push({0,j,t[0].next[v[0][j]]});
  }
  int dx[3]={0,0,1}, dy[3]={-1,1,0};
  while(SZ(q)>0){
    auto [x,y,z]=q.front(); q.pop();
    forn(i,3) if(x+dx[i]>=0 and x+dx[i]<n and y+dy[i]>=0 and y+dy[i]<m){
      if(t[z].next.count(v[x+dx[i]][y+dy[i]]) and dp[x+dx[i]][y+dy[i]][t[z].next[v[x+dx[i]][y+dy[i]]]]==INF){
        dp[x+dx[i]][y+dy[i]][t[z].next[v[x+dx[i]][y+dy[i]]]]=dp[x][y][z]+1;
        q.push({x+dx[i],y+dy[i],t[z].next[v[x+dx[i]][y+dy[i]]]});
      }
      if(SZ(t[z].leaf)>0 and t[0].next.count(v[x+dx[i]][y+dy[i]]) and dp[x+dx[i]][y+dy[i]][t[0].next[v[x+dx[i]][y+dy[i]]]]==INF){
        dp[x+dx[i]][y+dy[i]][t[0].next[v[x+dx[i]][y+dy[i]]]]=dp[x][y][z]+1;
        q.push({x+dx[i],y+dy[i],t[0].next[v[x+dx[i]][y+dy[i]]]});
      }
    }
  }
  ll ans=INF;
  forn(j,m) forn(z,k) if(SZ(t[z].leaf)>0) ans=min(ans,dp[n-1][j][z]);
  if(ans==INF) cout << "impossible\n";
  else cout << ans << "\n";
  return 0; 
}
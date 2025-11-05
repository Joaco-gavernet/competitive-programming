#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "==============================\n"

int merge(int v, int u, vector<vi> &g, vi &ca, vi &cb, vector<unordered_map<ll,ll>> &cnta, vector<unordered_map<ll,ll>> &cntb, vb &ans, vi &sa, vi&sb) {
  if (SZ(cnta[v])+SZ(cntb[v]) < SZ(cnta[u])+SZ(cntb[u])) swap(u, v);
  for (auto [x, y]: cnta[u]){
    if(x!=0){
      sa[v]-=max(0,cntb[v][x]-cnta[v][x]);
      sb[v]-=max(0,cnta[v][x]-cntb[v][x]);
    }
    cnta[v][x] += y;
    if(x!=0){
      sa[v]+=max(0,cntb[v][x]-cnta[v][x]);
      sb[v]+=max(0,cnta[v][x]-cntb[v][x]);
    }
  }
  for (auto [x, y]: cntb[u]){
    if(x!=0){
      sa[v]-=max(0,cntb[v][x]-cnta[v][x]);
      sb[v]-=max(0,cnta[v][x]-cntb[v][x]);
    }
    cntb[v][x] += y;
    if(x!=0){
      sa[v]+=max(0,cntb[v][x]-cnta[v][x]);
      sb[v]+=max(0,cnta[v][x]-cntb[v][x]);
    }
  }
  cnta[u].clear(); cntb[u].clear();
  return v;
}

int dfs(int v, int p, vector<vi> &g, vi &ca, vi &cb, vector<unordered_map<ll,ll>> &cnta, vector<unordered_map<ll,ll>> &cntb, vb &ans, vi &sa, vi&sb) {
  int v_repr = v;
  cnta[v][ca[v]]++;
  cntb[v][cb[v]]++;
  if(ca[v]!=cb[v]){
    if(ca[v]!=0) sb[v]++;
    if(cb[v]!=0) sa[v]++;
  }
  for (auto u: g[v]) {
    if (u == p) continue;
    int u_repr = dfs(u,v,g,ca,cb,cnta,cntb,ans,sa,sb);
    v_repr = merge(v_repr,u_repr,g,ca,cb,cnta,cntb,ans,sa,sb);
  }
  //solve
  //DBG(v); DBG(sa[v_repr]); DBG(sb[v_repr]); DBG(cnta[v_repr][0]); DBG(cntb[v_repr][0]);
  if(sa[v_repr]<=cnta[v_repr][0] and sb[v_repr]<=cntb[v_repr][0]) ans[v]=true;
  else ans[v]=false;
  return v_repr;
}


void solve() {
  int n; cin >> n;
  vector<vi> g(n);
  vi ca(n), cb(n);
  forn(i,n) cin >> ca[i];
  forn(i,n) cin >> cb[i];
  forn(i,n-1){
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }
  vector<unordered_map<ll,ll>> cnta(n), cntb(n);
  vb ans(n,false);
  vi sa(n), sb(n);
  dfs(0,-1,g,ca,cb,cnta,cntb,ans,sa,sb);
  forn(i,n){
    if(ans[i]) cout << 1;
    else cout << 0;
  }
  cout << "\n";
  //RAYA;
}

int main() {
  FIN;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}
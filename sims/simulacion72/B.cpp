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

const ll INF=1e9;

int main() {
  NaN;
  int n, m; cin >> n >> m;
  vi v(n);
  forn(i,n) cin >> v[i];
  vector <vi> g(n);
  vector <ii> p(n,{INF,INF});
  vi gr(n,-1);
  forn(i,m){
    int x, y; cin >> x >> y;
    x--; y--;
    g[x].pb(y);
    gr[y]=x;
  }
  vi a(n);
  forn(i,n) a[i]=SZ(g[i]);
  ll ans=2*INF, best=INF;
  queue <int> q;
  forn(i,n) if(a[i]==0) q.push(i);
  while(SZ(q)>0){
    int x=q.front(); q.pop();
    //DBG(x);
    if(SZ(g[x])==0) p[x].ff=v[x];
    else{
      ll mini=INF;
      for(auto y : g[x]){
        p[x].ff=min(p[x].ff,p[y].ff+v[x]);
        p[x].ss=min(p[x].ss,p[y].ss+v[x]);
        p[x].ss=min(p[x].ss,p[y].ff+mini+v[x]);
        mini=min(mini,p[y].ff);
      }
    }
    if(gr[x]==-1){
      ans=min(ans,p[x].ss);
      ans=min(ans,p[x].ff+best);
      best=min(best,p[x].ff);
    }
    else{
      a[gr[x]]--;
      if(a[gr[x]]==0) q.push(gr[x]);
    }
  }
  cout << ans << "\n";
  return 0; 
}
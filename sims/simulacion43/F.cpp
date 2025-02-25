#include <bits/stdc++.h>
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size)
#define all(v) (v).begin(), (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '

struct DSU {
  vi link, sz; 

  DSU (int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    forn(i,tam+5) link[i] = i, sz[i] = i;
  }

  ll find(ll x) { return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }
  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a; 
  }
};

struct edge{
  int i, j; ll w;
};

int main() {
  FIN;
  int n; cin >> n;
  map <ll,int> mapa;
  DSU d(n);
  vector <edge> ans;
  forn(i,n){
    int m; cin >> m;
    forn(j,m){
      ll a; cin >> a;
      if(mapa[a]!=0 and !d.same(i,mapa[a]-1)){
        d.join(i,mapa[a]-1); ans.pb({i+1,mapa[a],a});
      }
      mapa[a]=i+1;
    }
  }
  if(ans.size()<n-1) cout << "impossible\n";
  else forn(i,n-1) cout << ans[i].i << " " << ans[i].j << " " << ans[i].w << "\n";
  return 0;
} 

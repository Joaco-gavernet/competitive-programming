#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

const long double EPS = 1.0e-6;
typedef ll tipo; 
const int MAXN = 2e5+5; 

struct arista {
  int x; long double w;
}; 

struct nodo {
  long double d;
  tipo v, a;
  bool operator < (const nodo &x) const { return d > x.d; }
}; 

vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
  vector<nodo> ans(n);
  vb visto(n,false); 
  priority_queue<nodo> p; p.push({0,start,-1}); 
  while (!p.empty()) {
    nodo it = p.top(); p.pop();
    if (visto[it.v]) continue;
    else {
      ans[it.v] = it; visto[it.v] = true;
      for (arista u : g[it.v]) {
	if (!visto[u.x]) 
	  p.push({it.d + u.w, u.x, it.v});
      }
    }
  }
  
  return ans; 
}


int main() {
  FIN;
  
  int n, m, k; cin >> n >> m >> k;
  vector<vector<arista>> g(n); 
  
  forn(_,m) {
    int i, j, l; cin >> i >> j >> l;
    i--; j--; 
    g[i].pb({j, l});
    g[j].pb({i, l});
  }
  vector <nodo> inicio=Dijkstra(0,n,g), finish = Dijkstra(n-1,n,g);
  
  vector<long double> p(n, -1); 
  bool ok = false; 
  
  forn(i,k){
    int v; cin >> v; v--; 
    string s; cin >> s;
    p[v] = stold(s);
    if (abs(p[v] - 1.0) < EPS) ok = true; 
  }
  
  if (ok == false) {
    cout << "impossible\n";
    return 0;
  }
  
  vector <pair<ll,long double>> v;
  forn(i,n) if(p[i]!=-1) {
    //~ cout << finish[i].d+inicio[i].d << " " << p[i] << endl;
    v.pb({finish[i].d+inicio[i].d,p[i]});
  }
  sort(all(v));
  long double r=1, ans=0;
  forn(i,k){
    ans+=v[i].first*v[i].second*r;
    r*=(1-v[i].second);
  }
  cout << setprecision(10) << fixed << ans << "\n";
  return 0;
}




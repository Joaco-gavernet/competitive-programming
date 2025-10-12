#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=============================\n"


struct compresion {
  vector <string> todos;
  compresion(vector <string> v) {
    todos = v; sort(all(todos)); 
    todos.erase(unique(all(todos)), todos.end());
  } 
  int obtener(string x) {
    return (int)(lower_bound(all(todos), x) -todos.begin()); 
  } 
}; 

struct DSU {
  vi link, sz; 

  DSU (int tam) {
    link.resize(tam+5), sz.resize(tam+5); 
    forn(i,tam+5) link[i] = i, sz[i] = 1; 
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


int main() {
  FIN;
  int n; cin >> n;
  vector <string> t;
  vector <pair<string,string>> p(n);
  forn(i,n){
    string s; cin >> s;
    s.pop_back();
    t.pb(s);
    p[i].first=s;
    cin >> s >> s >> s;
    t.pb(s);
    p[i].second=s;
  }
  compresion c(t);
  DSU d(n);
  vector <vi> v(SZ(c.todos));
  forn(i,n) v[c.obtener(p[i].second)].pb(i);
  forn(i,SZ(v)) forr(j,1,SZ(v[i])) d.join(v[i][j],v[i][j-1]);
  forn(i,n) if(SZ(v[c.obtener(p[i].first)])>0) d.join(i,v[c.obtener(p[i].first)][0]);
  if(d.sz[d.find(0)]==n) cout << "possible\n";
  else cout << "impossible\n";
  return 0; 
}

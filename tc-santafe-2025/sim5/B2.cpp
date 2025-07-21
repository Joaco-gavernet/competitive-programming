#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


typedef double tipo; 

void dfs(int v, vector<vi> &g, vector<tipo> &p, vi &fat, vector<tipo> &sum_childs, int prev = -1) {
  for (auto u: g[v]) if (u != prev) {
    fat[u] = v;
    sum_childs[v] += p[u]; 
    dfs(u, g, p, fat, sum_childs, v); 
  } 
} 

int main(){
  FIN;
  cout << fixed << setprecision(5); 

  int n; cin >> n; 
  vector<tipo> p(n); 
  forn(i,n) {
    string aux; cin >> aux; 
    p[i] = 1.0 -stod(aux);
  }

  vector<vi> g(n); 
  forn(_,n-1) {
    int a, b; cin >> a >> b; 
    g[a].pb(b); 
    g[b].pb(a); 
  } 

  vi fat(n, -1); // root arbitrarily in node 0 and save father
  vector<tipo> sum_childs(n); 
  dfs(0, g, p, fat, sum_childs); 

  // initializing esp
  tipo esp = 0; 
  forn(v,n) esp += p[v]; 
  forn(v,n) esp -= p[v] *sum_childs[v]; 


  int q; cin >> q; 
  forn(_,q) {
      int v; cin >> v; 
      string aux; cin >> aux; 
      tipo prob = 1.0 -stod(aux); 

      esp -= p[v];
      esp += p[v] * sum_childs[v];

      esp += prob; 
      esp -= prob * sum_childs[v];

      // actualizo padre
      if (fat[v] != -1) {
          esp += p[fat[v]] * sum_childs[fat[v]];
          sum_childs[fat[v]] -= p[v]; 
          sum_childs[fat[v]] += prob; 
          esp -= p[fat[v]] * sum_childs[fat[v]];
      } 
      p[v] = prob; 

      cout << esp << '\n'; 
  } 



  return 0;
}


/*
   1.68040
   1.48440
   1.61740
   */ 

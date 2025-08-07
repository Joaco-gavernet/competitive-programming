#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '

const ll INF = 1LL<<60; 

unordered_map<char,int> steps;
vector<char> rgb={'R','G','B'};

void move(char &c, ll step){
  int i=0;
  if(c=='G') i=1; else if(c=='B') i=2;
  i+=step;
  i%=3;
  c=rgb[i];
  return;
}

int ret() {
  cout<<"impossible\n";
  return 0;
} 

void dfs(int v, vector<vector<ii>> &g, unordered_map<int,int> &clicks, string &s, ll &ans) {
  ans += clicks[v] %3; 
  for (auto [u, x]: g[v]) {
    if (clicks[u] == 0) {
      clicks[u] = (steps[s[x]] -(clicks[v] %3) +3) %3; 
      if (clicks[u] == 0) clicks[u] = 3; 
      dfs(u, g, clicks, s, ans); 
    } else if (steps[s[x]] != (clicks[v] + clicks[u]) %3) {
      ans = INF; 
      return; 
    } 
  } 
} 


int main() {
  FIN;
  steps['R'] = 0;
  steps['G'] = 2;
  steps['B'] = 1;

  int l, b; cin >> l >> b; 
  string s; cin >> s; 
  vector<vi> but(b), mybut(l); 
  vi clicks(b, -1); 
  forn(i,b) {
    int k; cin >> k;
    but[i] = vi(k); 
    while (k--) {
      int a; cin >> a; 
      but[i][k] = --a; 
      mybut[a].pb(i); 
    }
  }

  vb visto(l,false);

  // Chequeo grado 0
  queue<ll> q;
  forn(i,l) {
    if(SZ(mybut[i]) == 0) {
      if (s[i]!='R') return ret(); 
      visto[i] = true; 
    } else if (SZ(mybut[i]) == 1) q.push(i), visto[i] = true;
  }

  // Fijo grado 1
  while (SZ(q)) {
    ll act = q.front(); q.pop();
    int mb = mybut[act][0]; 
    if (clicks[mb] == -1) clicks[mb] = steps[s[act]], s[act] = 'R';
    else {
      move(s[act], clicks[mb]);
      if (s[act] != 'R') return ret(); 
    }

    for (auto u: but[mb]) if (visto[u] == false) {
      if (mybut[u].back() != mb) reverse(all(mybut[u]));
      move(s[u], clicks[mb]);
      mybut[u].pop_back();
      q.push(u);
      visto[u] = true; 
    }
  }

  ll ans = 0;
  vb vistob(b, false); 

  // armo el grafo de botones 
  vector<vector<ii>> g(b);
  forn(bi,b) {
    for (auto x: but[bi]) {
      if (SZ(mybut[x]) != 2) continue; 
      if (mybut[x].back() == bi) reverse(all(mybut[x])); 
      int u = mybut[x].back(); 
      g[bi].pb({u, x}); // con que boton u me conecta, cada lampara x 
    } 
  } 
  forn(i,b) if (clicks[i] != -1) vistob[i] = true, ans += clicks[i];

  forn(bi,b) if (vistob[bi] == false) { 
    // opcion 1
    unordered_map<int, int> ciclo, vis; 
    ll best = INF, aux = 0;
    vis[bi] = 3;
    dfs(bi, g, vis, s, aux); 
    if (aux < best) best = aux, ciclo = vis; 

    // opcion 2
    vis.clear(); 
    aux = 0; 
    vis[bi] = 1;
    dfs(bi, g, vis, s, aux); 
    if (aux < best) best = aux, ciclo = vis; 

    // opcion 3
    vis.clear(); 
    aux = 0; 
    vis[bi] = 2;
    dfs(bi, g, vis, s, aux); 
    if (aux < best) best = aux, ciclo = vis; 

    // no existe respuesta valida para el ciclo procesado  
    if (best == INF) return ret(); 

    // marcar vistos del ciclo actual
    for (auto &[x, v]: ciclo) vistob[x] = true;  
    ans += best; 
  } 
  cout << ans << '\n'; 

  return 0;
}


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"
#define ff first
#define ss second 

struct arista {
  int dest; 
  ll id; 
};

int main() {
  FIN;

  int n, m; cin >> n >> m;
  vi in(n);
  vector<vector<arista>> g(n); 
  forn(i,m) {
    int u, v; cin >> u >> v; 
    g[--u].pb({--v, i}); 
    in[v]++;
  }

  queue<int> next; 
  forn(i,n) if (in[i] == 0) next.push(i);
  
  vi p(n);
  int pos = 0;
  while (SZ(next)) {
    int a = next.front(); next.pop();
    p[a] = pos++; 
    
    for (auto [b, id]: g[a]) {
      if (--in[b] == 0) next.push(b);
    }
  }

  vector<char> ans(m, 'q'); 
  forn(a,n) {
    for (auto [b, id]: g[a]) {
      if (p[a] /43 == p[b] /43) ans[id] = 'R';
      else if (p[a] /1849 == p[b] /1849) ans[id] = 'G';
      else ans[id] = 'B';
    }
  }

  for (char c: ans) cout << c << '\n'; 
  
  return 0; 
}

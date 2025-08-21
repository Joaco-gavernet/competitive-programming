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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
int my_random(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng); 
}

struct arista {
  int dest; 
  ll id; 
};

int main() {
  FIN;

  int n, m; cin >> n >> m;
  vector<vector<arista>> g(n); 
  forn(i,m) {
    int u, v; cin >> u >> v; 
    g[--u].pb({--v, i}); 
  }

  char ops[] = {'R', 'G', 'B'};
  forn(i,m) cout << ops[my_random(0,2)] << '\n';
  
  return 0; 
}

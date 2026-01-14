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
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)


int main() {
  FIN;

  int n, m; cin >> n >> m; 
  
  vector<vi> dir(n);
  vector<vi> inv(n);
  forn(i,m) {
    int a, b; cin >> a >> b;
    --a, --b;
    dir[a].pb(b);
    inv[b].pb(a);
  }

  int id = 0, tot = -1;
  forn(v,n) {
    int aux = 0;
    unordered_map<int,bool> visto; 
    for(auto u: dir[v]) visto[u] = true;
    for(auto u: inv[v]) if (visto[u] == false) aux++;

    if (aux > tot) id = v, tot = aux;
  }
  cout << id + 1 << ' ' << tot << '\n';

  return 0;
}
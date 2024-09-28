/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

int main(){  
  FIN;

  int t; cin >> t;
  while (t--) {
    int n,m; cin >> n >> m;
    // n = number of friends
    // m = total days
    
    vector<vector<int>> v(m); // input
    vector<vector<int>> puedo(n); // dias disponibles de cada persona
    vector<int> histo(n); // cuenta cuantos dias juega cada uno
    vector<int> ocupado(m,-1); 
    queue<int> q;

    forn(i,m) {
      int act; cin >> act; 

      while (act--) {
        int aux; cin >> aux;
        puedo[--aux].pb(i);
        v[i].pb(aux);
      }
    }

    forn(i,n) {
      histo[i] = puedo[i].size();
      if (histo[i] <= ceil(m/2)) q.push(i);
    }

    int tot = 0;
    while (SZ(q) > 0) {
      int e = q.front(); q.pop();
      for (int d: puedo[e]) if (ocupado[d] == -1) {
        for (int h: v[d]) if (--histo[h] <= ceil(m/2)) q.push(h);
        tot++;
        ocupado[d] = e;
      }
    }

    if (tot == m) {
      cout << "YES\n";
      forn(i,m) cout << ocupado[i] +1 << ' ';
      cout << '\n';
    } else cout << "NO\n";
  }
  
  return 0;
}

// 1 2 1 1 2 3 


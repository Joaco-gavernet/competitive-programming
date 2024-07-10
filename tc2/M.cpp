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
    
    vector<int> diasPersona(m,0); // cuantas personas pueden en el dia
    vector<vector<int>> puedo(n);
    vector<vector<int>> v(n);

    RAYA;
    int tot;
    forn(i,n) {
      cin >> tot; 

      int aux;
      forn(j,tot) {
        cin >> aux;
        aux--;
        puedo[aux].pb(j);
        diasPersona[aux]++;
        v[i].pb(aux);
      }
    }

    vector<int> ocupado(m,-1);
    vector<int> especiales;
    forn(i,n) {
      if (puedo[i].size() <= ceil(m/2)) {
        for (int d: puedo[i]) ocupado[d] = i;
      } else especiales.pb(i);
    }

    RAYA;
    DBG(m);
    bool ans = true;
    forn(i,m) {
      if (ocupado[i] == -1) {
        ans = false;
        DBG(i);
      }
    }
    if (ans == false) {
      cout << "YES\n";
      forn(i,m) cout << ocupado[i] << ' ';
    } else {
      cout << "NO\n";
    }
  }
  
  return 0;
}

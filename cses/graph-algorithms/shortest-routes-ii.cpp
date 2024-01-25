#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(1e9+5);

//~ Minino camino entre todos los nodos
//~ O(n^3) - Tambien detecta ciclos negativos
void floyd(vector<vector<ll>>&matriz, ll n) {
  forn(k,n) forn(i,n) forn(j,n) {
    matriz[i][j]=min(matriz[i][j],matriz[i][k]+matriz[k][j]);
  }
}

int main(){
  FIN;
  
  int n,m,q; cin >> n >> m >> q;
  vector<vector<ll>> matriz(n, vector<ll>(n,INF));
  forn(i,n) matriz[i][i] = 0;
  ll a,b,c;
  while (m--) {
    cin >> a >> b >> c; a--; b--;
    matriz[a][b] = min(c,matriz[a][b]);
    matriz[b][a] = min(c,matriz[a][b]);
  }
  
  floyd(matriz,n);
  
  while (q--) {
    cin >> a >> b; a--; b--;
    if (matriz[a][b] == INF) matriz[a][b] = -1;
    cout << matriz[a][b] << '\n';
  } 
  
  return 0;
}




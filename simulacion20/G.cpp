#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(c) int((c).size())
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define DBG(v) cerr << #v << " = " << v << endl;
#define RAYA cerr << "==========================" << endl;

const int MAXN = 1e6+5;
const int LOG = 21;
//~ const int MAXN = 1e3;
//~ const int LOG = 8;
const ll INF = 1ll<<62;

vi min_prime;

vi criba(ll n) {
  vb prime(n+1, true);
  min_prime.resize(n+1, INF);
  vi primos;
  for (ll p = 2; p*p <= n; p++) {
    if (!prime[p]) continue;
    for (ll i = p*p; i <= n; i += p) {
      prime[i] = false;
      min_prime[i] = min(min_prime[i], p);
    }
  }
  forr(i, 2, n+1) {
    if (prime[i]) primos.pb(i), min_prime[i] = i;
  }
  return primos;
}

vi find_divisors(ll n) {
  vector<ii> factor;
  while(n!=1) {
    int p=min_prime[n], cont = 0;
    while (n % p == 0) {
      cont++;
      n /= p;
    }
    factor.pb({p, cont});
  }
  
  
  vi divisores = {1};
  for (auto [p,exp] : factor) {
    int tam = SZ(divisores);
    forn(i,exp) {
      forn(j,tam) {
	int pos = SZ(divisores)-tam;
	divisores.pb(divisores[pos]*p);
      }
    }
  }
  
  sort(all(divisores));
  return divisores;
}

ll path[MAXN][LOG];
vi len(MAXN);
vb vis(MAXN, false);
void dfs_topo(int v) {
  vis[v] = true;
  int u = path[v][0];
  if (!vis[u]) dfs_topo(u);
  len[v] = len[u] +1;
}


int main() {
  FIN; 
  
  int n, k; cin >> n >> k;
  criba(n+1);
  ll sum[MAXN][LOG]; // TODO: revisar sizes
  path[0][0] = 0;
  forr(i,1,n) {
    vi v=find_divisors(i);
    ll aux = i + SZ(v);
    //cout << aux << endl;
    if (aux >= n) aux %= n;
    path[i][0] = aux;
  }
  forr(j,1,LOG) forn(i,n) path[i][j]=path[path[i][j-1]][j-1];
  forn(i,n) if(!vis[i]) dfs_topo(i);
  forn(i,n) sum[i][0]=i;
  forr(j,1,LOG) forn(i,n) sum[i][j]=sum[i][j-1]+sum[path[i][j-1]][j-1];
  ll ans=INF; int inicio=-1;
  forn(i,n) if(len[i]>=k){
    int d=k;
    ll aux=0,act=i; int j=0;
    while(d){
      if(d%1){
	aux+=sum[act][j];
	act=path[act][j];
      }
      d>>=1;
      j++;
    }
    if(aux<ans){
      ans=aux;
      inicio=i;
    }
  }
  
  //~ DBG(n);
  //~ DBG(k);
  //~ RAYA;
  //~ forn(i,n) {
    //~ forn(j,LOG) cerr << sum[i][j] << " ";
    //~ cerr << endl;
  //~ }
  //~ RAYA; 
  //~ forn(i,n) {
    //~ forn(j,LOG) cerr << path[i][j] << " ";
    //~ cerr << endl;
  //~ }
  //~ RAYA; 
  
  if(inicio==-1) cout << inicio;
  else forn(i,k){
    cout << inicio << " ";
    inicio=path[inicio][0];
  }
  cout << "\n";
  return 0;
}

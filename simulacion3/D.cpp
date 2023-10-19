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

  ll n,m; cin >> n >> m;

  vector<ll> p(n); forn(i,n) cin >> p[i];
  vector<ll> d(m+1); forr(i,1,m+1) cin >> d[i];
  sort(d.begin(),d.end());
  
  ll k = 0; 
  multiset<ll> multi;
  forn (i,n) {
    multi.insert(k);
    if (k < m+1 and d[k] < (i+1)*100) k++;
  }
  
  ll maxTot = 0;
  
  forn(l,(m+1)) { // se recorren los intervalos buscando resultado optimo      
    ll a = l;
    ll b = a+1;
    //~ DBG(a);
    
    ll dif = 0;
    if (b == 1) dif = d[1];
    else if (a == m) dif = 100*(n-1) - d[m];
    else dif = (d[(b<m) ? b : m] - d[a] + 1) / 2;
    //~ DBG(dif);
    
    ll tot = (ll)(dif+99)/100;
    ll maxAct = 0;
    //~ DBG(tot);
    
    if (a != 0 and d[a] % 100 == 0) a++;
    forn(i,(a + tot < n) ? tot : n-a) maxAct += p[a+i];
    
    if (tot < b-a) {
      ll act = 0;
      forn(i,b-a) {
	act -= p[a+i];
	act += p[a+tot+i];
	maxAct = (maxAct < act) ? act : maxAct;
      }
    }
    
    maxTot = (maxTot < maxAct) ? maxAct : maxTot;
    //~ DBG(maxAct);
  }
  cout << maxTot << "\n";
  //~ DBG(maxTot);
  

  return 0;
}







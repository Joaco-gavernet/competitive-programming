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
  
  int n,m; cin >> n >> m;

  vector<int> p(n); forn(i,n) cin >> p[i];
  vector<bool> v(n);
  vector<int> d(m); 
  forn(i,m) {
    cin >> d[i];
    if (d[i] % 100 == 0 and d[i]/100 < n) v[d[i]/100] = true;
  }
  sort(d.begin(),d.end());
  
  int act = 0;
  int ans = 0;
  
  // primer intervalo
  for (int x=0; x<(d[0]+99)/100; x++) act += p[x];
  ans = max(ans,act); 
 
  // ultimo intervalo
  act = 0;
  for (int x=(d[m-1]+100)/100; x<n; x++) act += p[x];
  ans = max(ans,act); 
 
  // intervalos entre heladerias
  forr(i,0,(m-1)) {
    int dif = (d[i+1] - d[i]) / 2;
    int houses = (dif + 100) / 100;
    int a = (d[i]+100)/100;
    int b = (d[i+1]+100)/100;
    
    act = 0;
    forn(k,houses) {
      if (a+k < n and v[a+k] == 0) act += p[a+k];
      else break;
    }
    ans = max(act,ans);
    //~ DBG("pre");
    
    forr(k,a,b) {
      if (k+houses >= min(b,n)) break;
      act -= p[k];
      act += p[k+houses];
      ans = max(act,ans);
    }
  }
  
  cout << ans << "\n";
  
  
  return 0;
}

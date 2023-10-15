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
    vector<ll> d(m); forn(i,m) cin >> d[i];
    sort(d.begin(),d.end());
    
    vector<ll> intervals(m+1);
    ll k = 0; 
    forn (i,n) {
      intervals[k] += p[i];
      if (k < m and d[k] < (i+1)*100) k++;
    }
    forn(i,m+1) cout << intervals[i] << "\n";
    
    auto it = max_element(intervals.begin(),intervals.end());
    //~ // cout << (it - intervals.begin()) << "\n";
    
    ll point = (it - intervals.begin());
    ll x = (point == 0) ? 0 : point-1;
    ll y = point;
    ll coorX = d[x];
    ll coorY = d[y];
    double dif = double(coorY - coorX)/200;
    ll tot = dif + 1;
    //~ // cout << dif << " " << tot << "\n";
    
    ll dX = (coorX+99)/100; // 1
    ll dY = (coorY+99)/100; // 3
    if (dY > m) dY = m;
    cout << dX << dY;
    
    ll act = 0;
    
    forn(i,tot) act += p[dX+i];
    ll best = act;
    
    forn(i,(m-tot)) {
      act -= p[i];
      act += p[i+tot];
      if (act > best) best = act;
    }
    cout << best << "\n";
    
    

    return 0;
}







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

  ll t; cin >> t;
  ll x,y;
  cout << fixed << setprecision(20);
  
  forn(_,t) {
    cin >> y >> x;
    ll tot = 0;
    tot += (y < x) ? ((x-1)*(x-1)) : ((y-1)*(y-1));
    if (x == 1 and y == 1) tot = 1;
    //~ DBG(tot);
    
    if (y <= x) {
      if (x % 2 == 0) tot += y;
      else tot += x*x - (x-1)*(x-1) +1 -y;
    }
    
    if (x < y) {
      if (y % 2 == 1) tot += x;
      else tot += y*y - (y-1)*(y-1) +1 -x;
    }
    
    cout << tot << "\n";
  }


  return 0;
}



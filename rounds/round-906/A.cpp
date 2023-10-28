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
  
  forn(_,t) {
    int n; cin >> n;
    int a; int x = -1, y = -1;
    multiset<int> m;
    vector<int> v;
    
    forn(i,n) {
      cin >> a;
      m.insert(a);
      
      if (x == -1) x = a;
      else if (y == -1 and a != x) y = a;
    }
    
    //~ DBG(x);
    //~ DBG(y);
    //~ DBG(m.size()); 
    //~ DBG(m.count(x));
    //~ DBG(m.count(y));
    
    if (m.size() - m.count(x) - m.count(y) >= 1) cout << "No\n";
    else if (y != -1 and max(m.count(x),m.count(y)) - min(m.count(x),m.count(y)) > 1) cout << "NO\n";
    else cout << "YES\n";
  }
  
  return 0;
}










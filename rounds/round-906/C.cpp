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
    int k; cin >> k;
    string s; cin >> s;
    RAYA;
    
    int res = 0;
    vector<int> v;
    
    forn(i,SZ(s)/2) {
      if (res > 300) {
	res = -1;
	break;
      }
      
      if (s[i] == s[SZ(s)-i-1]) {
	if (s[i] == 0) {
	  s.insert(SZ(s)-i+1,"01");
	  v.pb(SZ(s)-i+1);
	} else {
	  s.insert(SZ(s)-i,"01");
	  v.pb(SZ(s)-i);
	}
	//~ DBG(s);
	//~ DBG(v[SZ(v)-1]);
	i--;
	res++;
      };
    }
    
    if (SZ(s)%2 == 1) cout << -1 << endl;
    else cout << res << endl;
    
    if (res > 0) {
      for(int i : v) cout << i << "\n";
    }
  }
  
  
  
  
  
  
  return 0;
}






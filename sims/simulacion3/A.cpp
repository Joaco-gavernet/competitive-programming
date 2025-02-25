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

bool comparator(pair<int,int> a, pair<int,int> b) {
  if (a.first < b.first) return true;
  else if (a.first == b.first and a.second > b.second) return true;
  else return false;
}

int main(){  
    FIN;

    int t; cin >> t;
    
    forn(_,t) {
      int n; cin >> n;
      vector<pair<int,int>> v(n); 
      forn(i,n) cin >> v[i].second >> v[i].first;
      sort(v.begin(),v.end(),comparator);
      
      int beauty = 0;
      int i = 0;
      int difficulty = 1;
      while (i < n) {
	if (v[i].first == difficulty) {
	  difficulty++;
	  beauty += v[i].second;
	}
	i++;
      }
      if (difficulty == 11) cout << beauty << "\n";
      else cout << "MOREPROBLEMS\n";
    }

    return 0;
}







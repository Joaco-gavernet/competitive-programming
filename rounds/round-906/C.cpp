/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

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
    string s; cin >> s;

    int cnt[2]; 
    cnt[0] = cnt[1] = 0; 
    for (char c: s) cnt[c - '0']++; 
    if (cnt[0] != cnt[1]) {
      cout << "-1\n";
      continue; 
    } 

    deque<int> dq; 
    for (char c: s) dq.push_back(c - '0'); 

    int lef = 0; 
    vi ops; 
    while (SZ(dq)) {
      if (dq.front() == dq.back()) {
        if (dq.front() == 0) {
          ops.pb(lef + SZ(dq)); 
          dq.pop_front(); 
          dq.push_back(0); 
          lef++; 
        } else {
          ops.pb(lef); 
          dq.pop_back(); 
          dq.push_front(1); 
          lef++; 
        } 
      } else lef++, dq.pop_front(), dq.pop_back(); 
    } 

    cout << SZ(ops) << '\n'; 
    for (auto &x: ops) cout << x << ' '; 
    cout << '\n'; 
  }


  return 0;
}






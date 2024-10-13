#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n" 

bool check(int x, int start, int tot, vi &income) {
  ll savings = 0; 
  for (ll i = start; i < start +tot; i++) {
    if (income[i] +savings < x) return false; 
    else savings += income[i] -x;
  }
  return true; 
}

int main() {
  FIN; 

  int n, m; cin >> n >> m;
  vi income(n); forn(i,n) cin >> income[i]; 

  forn(_,m) {
    int start, tot; cin >> start >> tot; 
    ll l = -1, r = 1e9+1; 
    start--; 
    while (r-l > 1) {
      // cerr << l << ' ' << r << endl; 
      ll mid = (r+l)/2; 
      if (check(mid,start,tot,income)) l = mid; 
      else r = mid; 
    }

    if (l == -1) cout << "stay with parents\n"; 
    else cout << l << '\n'; 
  }



  return 0;
}

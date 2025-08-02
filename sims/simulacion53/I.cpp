#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '


int main() {
  FIN;

  ll n, m; cin >> n >> m; 

  ll tot = 0;
  forn(i,n) {
    forn(j,m) {
      ll a; cin >> a;
      tot += a; 
    }
  }

  cout << fixed << setprecision(13); 
  long double ans =  ((long double)tot) / (n * m); 
  cout << ans << '\n'; 

  return 0;
}
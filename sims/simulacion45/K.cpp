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
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define RAYA cerr << "===========================\n"
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << '\n'



int main() {
  FIN;

  int n, m; cin >> n >> m;
  string a, b; cin >> a >> b;

  string ans(m, '?');
  forn(i,n) ans[m -1 -i] = a[n-1-i];

  int i = m-1;
  while (i >= n) {
    ans[i -n] = 'a' +(26 +b[i] -ans[i]) %26;
    i--;
  }
  cout << ans << '\n';

  return 0;
}

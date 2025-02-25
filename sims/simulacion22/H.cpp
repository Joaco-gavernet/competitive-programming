#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << c << endl
#define RAYA cerr << "========================= \n"

const ll MAXN = -1;
const ll MOD = -1;
const ll INF = -1;


int main() {
  FIN;

  int n; cin >> n;
  vi v(n); forn(i,n) cin >> v[i];
  sort(all(v));

  vi ans;
  for (int i = 0, j = n-1; i <= j; i++, j--) {
    ans.pb(v[i]);
    if (i < j) ans.pb(v[j]);
  }
  reverse(all(ans));

  for (auto x : ans) cout << x << ' '; 
  cout << endl;


  return 0;
}

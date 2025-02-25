#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << " ======================= \n"

const int MAXN = -1;
const int MOD = -1;
const int INF = -1;


int main() {
  FIN;

  ll X, Y; cin >> X >> Y;
  ll n; cin >> n;

  vector<vi> v(X);
  forn(i,n) {
    int a, b; cin >> a >> b;
    v[a].pb(b);
  }

  //~ forn(i,X) {
  //~ DBG(i);
  //~ for (auto u: v[i]) cerr << u << ' ';
  //~ cerr << endl;
  //~ }

  //~ RAYA;

  vi comp;
  forn(i,X) {
    if (SZ(v[i]) == 1) comp.pb(v[i][0]), comp.pb(v[i][0]);
    else if (SZ(v[i]) > 1) {
      sort(all(v[i]));
      ll mi = v[i][0];
      ll mx = v[i][SZ(v[i])-1];
      comp.pb(mi);
      comp.pb(mx);
      v[i].clear();
      v[i].pb(mi);
      v[i].pb(mx);
    }
  }
  sort(all(comp));
  //~ for (auto i: comp) cerr << i << " ";
  //~ RAYA;

  ll best = comp[SZ(comp)/2];
  //~ DBG(best);
  ll tot = 0;
  forn(i,X) {
    //~ cerr << i << " = " << tot << endl;
    if (SZ(v[i]) == 1) tot += 2*abs(v[i][0]-best);
    else if (SZ(v[i]) > 1) {
      ll mi = v[i][0];
      ll mx = v[i][1];
      if (mi > best) tot += 2*abs(mx-best);
      else if (mx < best) tot += 2*abs(mi-best);
      else {
	tot += 2*abs(best-mx);
	tot += 2*abs(best-mi);
      }
    }
  }

  cout << tot +X -1 << endl;


  return 0;
}

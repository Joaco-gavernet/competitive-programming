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

const int MAXN = 1e5+5;
const int MOD = -1;
const int INF = -1;


ll check(ll x, vector<vi> &v) {
  //~ DBG(x);
  int X = SZ(v);
  ll tot = 0;
  forn(i,X) {
    //~ cerr << i << " = " << tot << endl;
    if (SZ(v[i]) == 1) tot += 2*abs(v[i][0]-x);
    else if (SZ(v[i]) > 1) {
      ll mi = v[i][0];
      ll mx = v[i][1];
      if (mi > x) tot += 2*abs(mx-x);
      else if (mx < x) tot += 2*abs(mi-x);
      else {
	tot += 2*abs(x-mx);
	tot += 2*abs(x-mi);
      }
    }
  }
  
  return tot;
}

int main() {
  FIN;
  
  ll X, Y; cin >> X >> Y;
  ll n; cin >> n;
  
  vector<vi> v(X);
  forn(i,n) {
    int a, b; cin >> a >> b;
    v[a].pb(b);
  }
  
  //~ RAYA;
  //~ DBG(SZ(v));
  
  forn(i,X) {
    //~ DBG(i);
    sort(all(v[i]));
    //~ v.erase(unique(all(v)), v.end());
    
    //~ DBG(i);
    if (SZ(v[i]) > 1) {
      ll mi = v[i][0];
      ll mx = v[i][SZ(v[i])-1];
      v[i].clear();
      v[i].pb(mi);
      v[i].pb(mx);
    }
  }
  
  //~ RAYA; 
  ll l = -1, r = MAXN; 
  while (r-l > 1) {
    ll mid_left = l+(r-l)/3;
    if (mid_left == l) break;
    ll mid_right = l+2*(r-l)/3;
    if (mid_right == r) break;
    ll tot_left = check(mid_left, v);
    ll tot_right = check(mid_right, v);
    //~ cerr << l << " " << r << endl;
    //~ cerr << mid_left << " " << mid_right << endl;
    //~ RAYA;
    
    if (tot_left > tot_right) l = mid_left;
    else r = mid_right;
  }

  ll best = 1LL<<60;
  forr(i,l,r+1) best = min(best, check(i,v));
  //~ DBG(best);
  
  cout << best +X -1 << endl;
  
  
  return 0;
}

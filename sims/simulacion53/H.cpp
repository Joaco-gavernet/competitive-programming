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
  int n; cin >> n;
  vi l(n), r(n);
  forn(i,n) cin >> l[i] >> r[i];
  reverse(all(r)); reverse(all(l));
  r.pb(0);
  ll last=r[0];
  vector<ii> ans;
  forn(i,n){
    ll t=l[i]-r[i+1];
    if(r[i+1]+3*t>=last){
      ans.pb({r[i+1],r[i+1]+(last-r[i+1]+2)/3});
      last=r[i+1];
    }
  }
  if(last!=0) cout << "impossible\n";
  else{
    cout << SZ(ans) << "\n";
    forn(i,SZ(ans)) cout << ans[SZ(ans)-1-i].first << " " << ans[SZ(ans)-1-i].second << "\n";
  }
  return 0;
}
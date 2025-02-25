#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
#define DBGV(v) cerr << #v << " = "; forn(_,SZ(v)) cerr << v[_] << ' '; cerr << '\n'


int main() {
  FIN; 
  ll il,ir,dl,dr,pl,pr; cin>>il>>ir>>dl>>dr>>pl>>pr;
  vii ans;
  if(pl>il){ans.pb({il-1e5,ir}); il=il-1e5;}
  else{ans.pb({il+1e5,ir}); il=il+1e5;}

  if(pr>dr){ans.pb({il,ir-1e5}); ir=ir-1e5;}
  else {ans.pb({il,ir+1e5}); ir=ir+1e5;}

  ans.pb({dl,ir});

  cout<<SZ(ans)<<"\n";
  forn(i,SZ(ans)) cout<<ans[i].first<<" "<<ans[i].second<<"\n";

  return 0; 
}

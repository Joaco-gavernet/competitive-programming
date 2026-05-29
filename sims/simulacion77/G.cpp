#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

const ll INF = 1e9 + 7;

int main() {
  FIN;
  ll n, p, q, s; cin >> n >> p >> q >> s;
  vi x(p), y(q);
  forn(i,p) cin >> x[i];
  forn(i,q) cin >> y[i];
  x.pb(INF); y.pb(INF);
  sort(all(x)); sort(all(y));

  ll l=-1, r=s+1;
  while(r-l>1){
    ll med=(r+l)/2;
    // DBG(med);
    // ll px=0,py=0;
    ll contpairs=0;
    multiset<ll> elemx,elemy;
    for(auto u:x) elemx.insert(u);
    for(auto u:y) elemy.insert(u);
    forn(i,2*n){
      ll fx=*(elemx.begin());
      ll fy=*(elemy.begin());
      if(fx == INF or fy == INF) break;
      // DBG(fx);
      // DBG(fy);
      if(fx<fy){
        ll maxelem=min(s-fx,fx+med);
        auto it = elemy.lower_bound(maxelem+1);
        if(it!=elemy.begin()){
          it--;
          elemy.erase(it);
          elemx.erase(elemx.begin());
          contpairs++;
          if(contpairs==n) break;
        }else{
          if(fx < INF) elemx.erase(elemx.begin());
        }
      }else{
        ll maxelem=min(s-fy,fy+med);
        auto it = elemx.lower_bound(maxelem+1);
        if(it!=elemx.begin()){
          it--;
          elemx.erase(it);
          elemy.erase(elemy.begin());
          contpairs++;
          if(contpairs==n) break;
        }else{
          if(fy < INF) elemy.erase(elemy.begin());
        }
      }
      if(SZ(elemx)==1 or SZ(elemy)==1) break;
      // RAYA;
    }
    // DBG(contpairs);
    if(contpairs<n) l=med;
    else r=med;
  }
  if(r==s+1) cout << "-1\n";
  else cout << r << "\n";
  return 0;
}
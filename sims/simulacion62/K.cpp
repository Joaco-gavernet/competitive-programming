#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

void solve(){
  ll n; cin>>n; 
  vi coordx,coordy,coordz;
  multiset<ll> x,y,z;
  ll tam=0;
  forn(i,n){
    string s; cin>>s;
    if(s=="ADD"){
      tam++;
      ll a,b,c; cin>>a>>b>>c;
      x.insert(a); coordx.pb(a);
      y.insert(b); coordy.pb(b);
      z.insert(c); coordz.pb(c);
      ll difx=(*(--x.end())-*(x.begin()));
      ll dify=(*(--y.end())-*(y.begin()));
      ll difz=(*(--z.end())-*(z.begin()));
      ll ans=2*(difx*dify+dify*difz+difz*difx);
      cout<<ans<<"\n";
    }else{
      ll pos; cin>>pos;
      pos--;
      auto itx=x.lower_bound(coordx[pos]); x.erase(itx);
      auto ity=y.lower_bound(coordy[pos]); y.erase(ity);
      auto itz=z.lower_bound(coordz[pos]); z.erase(itz);
      tam--;
      if(tam==0) cout<<0<<"\n";
      else{
        ll difx=(*(--x.end())-*(x.begin()));
        ll dify=(*(--y.end())-*(y.begin()));
        ll difz=(*(--z.end())-*(z.begin()));
        ll ans=2*(difx*dify+dify*difz+difz*difx);
        cout<<ans<<"\n";
      }
    }
  }
}

int main() {
  FIN; 
  ll t; cin >> t;
  while(t--) solve();
  return 0; 
} 

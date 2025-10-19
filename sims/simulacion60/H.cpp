#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=======================" << endl 
#define ff first
#define ss second


int main() {
  FIN;
  int n; cin >> n;
  vi z(n);
  forn(i,n) cin >> z[i];
  int md=0;
  forn(i,n) if(z[i]>z[md]) md=i;
  vi v;
  forn(i,n-1) v.pb(z[(md+i+1)%n]);
  vi s(n);
  forn(i,n-1) s[i+1]=s[i]+v[i];
  ll b=max(0LL,z[md]-s[n-1]);
  set <ll> up, dow;
  up.insert(-1); up.insert(n-1);
  dow.insert(1); dow.insert(1-n);
  vi l(n-1), r(n-1);
  vector <pair<ll,ll>> m(n-1);
  forn(i,n-1) m[i]={v[i],i};
  sort(all(m));
  reverse(all(m));
  ll ans=z[md];
  //DBG(b);
  forn(i,n-1){
    ll j=m[i].ss;
    //DBG(j);
    //DBG(v[j]);
    ll x=-*dow.lower_bound(-j), y=*up.lower_bound(j);
    dow.insert(-j); up.insert(j);
    ll nb=b;
    if(x!=-1) nb=max(nb,r[x]);
    if(y!=n-1) nb=max(nb,l[y]);
    r[j]=max(nb,v[j]-(s[y]-s[j+1]));
    l[j]=max(nb,v[j]-(s[j]-s[x+1]));
    if(x==j-1) ans=min(ans,l[j]);
    if(y==j+1) ans=min(ans,r[j]);
  }
  cout << ans << "\n";
  return 0; 
}
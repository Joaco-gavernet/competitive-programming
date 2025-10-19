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
  ll mx, Mx, my, My;
  ll ms, Ms, mr, Mr;
  cin >> mx >> my;
  Mx=mx+1; My=my+1;
  Ms=mx+my+1; ms=mx+my-1;
  Mr=mx-my+1; mr=mx-my-1;
  mx--; my--;
  forn(i,n-1){
    ll x, y; cin >> x >> y;
    Mx=max(Mx,x+1); mx=min(mx,x-1);
    My=max(My,y+1); my=min(my,y-1);
    Ms=max(Ms,x+y+1); ms=min(ms,x+y-1);
    Mr=max(Mr,x-y+1); mr=min(mr,x-y-1);
  }
  vector <ii> v;
  ll ans=0;
  v.pb({mr+My,My}); v.pb({Ms-My,My});
  v.pb({Mx,Ms-Mx}); v.pb({Mx,Mx-Mr});
  v.pb({Mr+my,my}); v.pb({ms-my,my});
  v.pb({mx,ms-mx}); v.pb({mx,mx-mr});
  forn(i,8){
    ll j=(i+1)%8;
    ans+=max(abs(v[i].ff-v[j].ff),abs(v[i].ss-v[j].ss));
  }
  if(n>1 and (Ms-ms==2 or Mr-mr==2)) ans++;
  cout << ans << "\n";
  return 0; 
}
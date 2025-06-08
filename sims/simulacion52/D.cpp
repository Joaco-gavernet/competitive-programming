#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"

const ll MOD=1e9+7;

int main() {
  FIN;
  ll n; cin>>n;
  ll ans=0;
  ll l=1;
  while(3*l<=n){
    DBG(l);
    ll cantpares=(n-3*l)/2;
    DBG(cantpares);
    ll aux=(cantpares*(n-3*l+1))%MOD;
    aux=(aux+MOD-((cantpares*(cantpares+1))%MOD))%MOD;
    DBG(aux);
    aux=(aux+n-3*l+1)%MOD;
    DBG(aux);
    ans=(ans+aux)%MOD;
    l++;
  }
  cout<<ans<<"\n";

  return 0; 
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"
ll MOD=1e9+7;

ll be(ll b, ll e){
  ll r=1; b%=MOD;
  while(e){if(e&1LL)r=r*b%MOD;b=b*b%MOD;e/=2;}
  return r;
}

int main() {
  FIN;
  ll n; cin >> n;
  ll ans=0;
  forr(i,1,n+1) ans=(ans+be(i,MOD-2))%MOD;
  ans=(ans*n)%MOD;
  cout << ans << "\n";
  return 0;
}
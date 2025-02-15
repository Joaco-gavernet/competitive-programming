#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++) 
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '
#define RAYA cerr << "==============================\n"

ll hah(ll i, ll j, ll k){
  return i+505*j+505*505*k;
}
unordered_map<ll, ll> mapa;
ll m;
ll solve(ll i, ll j, ll k){
  //~ cout << i << " " << j << " " << k << endl;
  if(i==0 and k==0) return 1;
  if(i==0) return 0;
  if(j==0) return 0;
  if(mapa[hah(i,j,k)]==0){
    ll ans=0;
    if(j>0) ans=solve(i,j-1,k);
    if(i-j>=0) ans=(solve(i-j,min(j,i-j),k^j)+ans)%m;
    mapa[hah(i,j,k)]=ans+1;
  }
  return mapa[hah(i,j,k)]-1;
}

int main() {
  FIN; 
  ll n, p;
  cin >> n >> p >> m;
  //~ forn(i,5) forn(j,5) forn(k,5) cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
  cout << solve(n-p,n-p,p) << "\n";
  return 0; 
} 

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
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===========================\n"
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << '\n'

const long double eps = 1e-14;

int main() {
  FIN;
  cout<<fixed<<setprecision(7);
  ll n; cin>>n;
  vi gas(n); forn(i,n) cin>>gas[i];
  sort(all(gas));
  long double ans=1;
  // DBG(n);
  // RAYA;
  forn(i,n){
    // RAYA;
    // DBG(i); DBG(gas[i]);
    if(gas[i]>(i+1)){
      cout<<"-1\n";
      return 0;
    }
    long double frac=(long double)(gas[i])/(i+1);
    if(frac-eps < ans) ans=frac;
  }
  cout<<ans<<"\n";
  
  return 0;
}

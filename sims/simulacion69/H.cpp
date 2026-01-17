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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "===========================\n"

int main() {
  FIN;
  ll n, k; cin >> n >> k;
  ll m=0;
  vi maxi(k), mini(k);
  forr(i,2,k+2){
    m+=(1LL<<i)*(i-1);
    maxi[i-2]=(1LL<<i)*(i-1)-4;
    mini[i-2]=(1LL<<i)*(i-2);
  }
  m-=4*k;
  while(n--){
    ll p; cin >> p;
    if(p%4!=0 or p>m) {cout << "-1\n"; continue;}
    vi ans;
    for(int i=k-1; i>=0; i--){
      while(SZ(ans)+i<k-1 and p>maxi[i]){
        ans.pb(1LL<<(i+2));
        p-=maxi[i]+4;
      }
      if(p<=maxi[i] and p>=mini[i]){
        ans.pb(1LL<<(i+2));
        p=0;
      }
      else if(p>maxi[i]){
        ans.pb(1LL<<(i+2));
        p-=maxi[i];
      }
    }
    cout << SZ(ans) << " ";
    for(auto u : ans) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
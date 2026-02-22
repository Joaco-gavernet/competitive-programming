#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "======================\n"

int main() {
  FIN;
  int n; string s;
  cin >> n >> s;
  vi v(3);
  forn(i,n){
    if(s[i]=='r') v[0]++;
    else if(s[i]=='g') v[1]++;
    else v[2]++;
  }
  sort(all(v));
  ld ans=1.5*v[0];
  forn(i,v[0]+1){
    ld p=1;
    //DBG(i);
    forn(j,v[0]){
      p/=2;
      if(v[0]-i+j+1<=v[0]){
        p*=(v[0]-i+j+1);
        //DBG(v[0]-i+j+1);
      }
      if(j+1<=i){
        p/=j+1;
        //DBG(j+1);
      }
    }
    //RAYA;
    ans+=p*3*min(v[1]+i,v[2]+v[0]-i);
  }
  cout << setprecision(10) << fixed << ans << "\n";
  return 0; 
}
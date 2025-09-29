#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"



int main() {
  FIN;
  ll l, h; cin >> l >> h;
  ll A, B, C; cin >> A >> B >> C;
  ll a, b, c; cin >> a >> b >> c;
  ld ans=0;
  ld pa=1;
  ll tot=(a+b+c);
  cout << setprecision(10) << fixed;
  forn(x,a+1){
    if(x>0) pa=pa*(a-x+1)/(tot-x+1);
    ld pb=pa;
    forn(y,b+1){
      if(y>0) pb=pb*(b-y+1)/y*(x+y)/(tot-x-y+1);
      ld pc=pb;
      forn(z,c+1){
        if(z>0) pc=pc*(c-z+1)/z*(x+y+z)/(tot-x-y-z+1);
        ll g=x*A+y*B+z*C;
        if(g<l){
          if(l<=g+A and g+A<=h and x<a) ans+=pc*(a-x)/(tot-x-y-z);
          if(l<=g+B and g+B<=h and y<b) ans+=pc*(b-y)/(tot-x-y-z);
          if(l<=g+C and g+C<=h and z<c) ans+=pc*(c-z)/(tot-x-y-z);
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
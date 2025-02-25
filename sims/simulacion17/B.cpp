#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i< (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())

const int MAXN = -1;
const int INF = -1;
const int MOD = -1;




int main() {
  FIN;
  long double h,r,da,dw; cin>>h>>r>>da>>dw;
  dw-=da;
  cout << fixed << setprecision(9);
  long double a,b,c,d;
  a=dw/2;
  b=((h*h)*da)/2;
  c=h*da;
  d=dw;
  double ans=((-2*a*c)+sqrt(4*a*a*c*c+4*d*d*a*b))/(2*d*a);
  cout<<ans<<"\n";
  return 0;
}

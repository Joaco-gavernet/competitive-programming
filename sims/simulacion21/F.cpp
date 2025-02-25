#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef long double ld; 
typedef vector<ll> vi;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << " ======================= \n"

const int MAXN = -1;
const int MOD = -1;
const ll INF = 1LL<<60;

// Angular sort
struct frac {
  ll num, den;
  frac() {}
  frac(ll x, ll y) {
    ll m = __gcd(abs(x), abs(y));
    num = x / m; den = y / m;
  }
  int cuad(ll n, ll d) {
    if (n >= 0 and d >= 0) return 1;
    if (n >= 0 and d < 0) return 2;
    if (n < 0 and d < 0) return 3;
    if (n < 0 and d >= 0) return 4;
  }
  bool operator < (frac &p) {
    if (cuad(num,den) != cuad(p.num,p.den)) {
      return cuad(num,den) < cuad(p.num,p.den); 
    }
    return num*p.den < p.num*den;
  }
  bool operator == (frac &p) {
    return (num *p.den == den *p.num) and (cuad(num,den) == cuad(p.num,p.den));
  }
};


struct punto {
  ll x, y;
  bool s=true;
  frac pend;
  ll val;
  punto() {}
  punto(ll a, ll _b, ll z) {
    x = a, y = _b, val = z, pend = frac(_b,a);
  }
  bool operator < (punto p) {
    return pend < p.pend;
  }
};


int main() {
  FIN;
  int n;
  cin >> n;
  vector <punto> v(n);
  forn(i,n) cin >> v[i].x >> v[i].y >> v[i].val; 
  ll ans=INF;
  forn(i,n){
    cout << i << endl;
    vector <punto> g;
    ll arriba=0, abajo=0;
    forn(j,n) if(j!=i){
      punto p(v[j].x-v[i].x,v[j].y-v[i].y,v[j].val);
      if(p.y>0 or(p.x>=0 and p.y==0)) arriba+=p.val; 
      else {abajo+=p.val; p.s=false;}
      g.pb(p);
    }
    sort(all(g));
    forn(j,n-1){
      cout << arriba << " " << abajo << endl;
      if(g[j].s){
	arriba-=g[j].val; ans=min(ans,abs(arriba-abajo));
	abajo+=g[j].val;
      }
      else{
	abajo-=g[j].val; ans=min(ans,abs(arriba-abajo));
	arriba+=g[j].val;
      }
      if(ans==0) cout << i << " " << g[j].x+v[i].x << " " << g[j].y+v[i].y << " " << arriba <<  " " << abajo << endl;
    }
    cout << arriba << " " << abajo << endl;
    if(ans==1) cout << i << endl;
  }
  cout << ans << "\n";
  return 0;
}

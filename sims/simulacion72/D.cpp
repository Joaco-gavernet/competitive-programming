#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"


typedef long double tipo;
typedef long double ld;
long double EPS = (long double)(1e-10);
struct punto {
  tipo x, y;
  punto const operator - (const punto &p) const { return {x - p.x, y - p.y}; }
  punto const operator + (const punto &p) const { return {x + p.x, y + p.y}; }
  tipo operator * (const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^ (const punto &p) const { return x*p.y - y*p.x; }
  bool operator == (const punto &p) const { return (abs(x-p.x) < EPS and abs(y-p.y) < EPS); }
  bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; }
  tipo arg() { return atan2(y, x); }
  tipo mod() { return sqrtl(x*x + y*y); }
  tipo mod2() { return (x*x + y*y); }
};

punto operator * (tipo k, const punto &p) { 
  return {k*p.x, k*p.y}; 
}

tipo area(vector<punto> &v) {
  tipo ans = 0.0; int n = SZ(v); 
  forn(i,n) ans += v[i] ^ v[(i+1)%n]; 
  return -ans/2.0;
}

int main() {
  NaN;
  ld x0, y0, r; cin >> x0 >> y0 >> r;
  int n; cin >> n;
  vector <punto> p(n), q(n);
  forn(i,n){
    int x, y; cin >> x >> y;
    p[i]={x-x0,y-y0};
    q[i]=(r*r/p[i].mod()/p[i].mod())*p[i];
  }
  ld ans=area(q);
  forn(i,n){
    if(fabs((p[(i+1)%n]-p[i])^p[i])<EPS) continue;
    vector <punto> t;
    t.pb({0,0}); t.pb(q[(i+1)%n]); t.pb(q[i]);
    if(fabs(area(t))<EPS) continue;
    punto aux=q[(i+1)%n]-q[i];
    ld R=(q[i].mod()*q[(i+1)%n].mod()*aux.mod()/fabs(area(t)))/4;
    if(fabs(R)<EPS) continue;
    ld l=aux.mod()/2;
    ld ar=R*R*asin(l/R)-l*sqrtl(R*R-l*l);
    if(((p[(i+1)%n]-p[i])^p[i])<-EPS) ans-=ar;
    else ans+=ar;
  }
  cout << setprecision(10) << ans << "\n";
  return 0; 
}

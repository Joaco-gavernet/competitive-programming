#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i <(ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "============================\n"
#define ff first
#define ss second

// template punto
typedef long double ld; 
typedef ll tipo;
ll EPS = 0;

struct punto {
  tipo x, y;
  punto const operator -(const punto &p) const { return {x-p.x, y-p.y}; }
  punto const operator +(const punto &p) const { return {x+p.x, y+p.y}; }
  tipo operator *(const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^(const punto &p) const { return x*p.y - y*p.x; }
  bool operator ==(const punto &p) const {
    return (abs(x-p.x) < EPS and abs(y-p.y) < EPS);
  }
  bool operator <(punto p) const { return x != p.x ? x < p.x : y < p.y; }
  tipo arg() { return atan2(y,x); }
  ld mod() { return sqrtl(x*x + y*y); }
  tipo mod2() { return x*x + y*y; }
};

punto operator * (tipo k, const punto &p) { return {k*p.x, k*p.y}; }

// chull
void convex_hull(vector<punto> &a) {
  if (SZ(a) == 1) return;
  sort(all(a));
  punto p1 = a[0];
  vector<punto> up, down;
  up.pb(p1), down.pb(p1);
  forr(i,1,SZ(a)) {
    int n = SZ(up), m = SZ(down);
    while (n > 1 and ((up[n-1]-up[n-2])^(a[i]-up[n-1])) >= -EPS) {
      up.pop_back(); n--;
    }
    up.pb(a[i]);
    while (m > 1 and ((down[m-1]-down[m-2])^(a[i]-down[m-1])) <= EPS) {
      down.pop_back(); m--;
    }
    down.pb(a[i]);
  }
  a.clear();
  for(punto u: up) a.pb(u);
  for(int i = SZ(down)-2; i > 0; i--) a.pb(down[i]); 
}

// dist point-line
ld dist_point_line(punto &p, punto rv, punto &rp) {
  punto p1 = rp, p2 = rp + rv;
  return (ld)fabs((p1-p)^(p2-p)) /rv.mod();
}

int main() {
  FIN;
  int n;ld r; cin >> n >> r;
  vector <punto> p(n);
  forn(i,n) cin >> p[i].x >> p[i].y;
  convex_hull(p);
  ld ans=2*r;
  int j=1;
  n=SZ(p);
  forn(i,n){
    if(i==j) j=(j+1)%n;
    while((((p[(j+1)%n]-p[j])^(p[i]-p[(i+n-1)%n]))>0 and ((p[(j+n-1)%n]-p[j])^(p[i]-p[(i+n-1)%n]))<0) or (((p[(j+1)%n]-p[j])^(p[i]-p[(i+n-1)%n]))>0 and ((p[(j+n-1)%n]-p[j])^(p[i]-p[(i+n-1)%n]))<0)) j=(j+1)%n;
    ans=min(ans,dist_point_line(p[j],p[i]-p[(i+n-1)%n],p[i]));
  }
  cout << setprecision(10) << fixed << ans << "\n";
  return 0; 
}
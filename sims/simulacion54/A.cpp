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
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '
const ll INF=1000000;

typedef long long tipo;
typedef long double ld;
double EPS = (double)(1e-10);
struct punto {
  tipo x, y;
  punto const operator -(const punto &p) const { return { x-p.x, y-p.y}; }
  punto const operator +(const punto &p) const { return { x+p.x, y+p.y}; }
  tipo operator *(const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^(const punto &p) const { return x*p.y - y*p.x; }
  bool operator == (const punto &p) const {
    return (abs(x-p.x) < EPS and abs(y-p.y) < EPS); 
  }
  bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; }
  tipo arg() { return atan2(y, x); }
  ld mod() { return sqrtl(x*x + y*y); }
  tipo mod2() { return (x*x + y*y); }
};

punto operator*(tipo k, const punto &p) {
  return { k*p.x, k*p.y }; 
}

struct recta {
  punto v, p; 
  recta(punto p1, punto p2) { v = (p2 -p1); p = p1; }
  recta() {}
  recta(tipo A, tipo B, tipo C) {
    v = {-B, A}; A != 0 ? p = {-C / A, 0} : p = {0, -C / B}; 
  }
  bool is_in(punto q) { return fabs((q.x-p.x) *v.y -(q.y -p.y)*v.x) < EPS; }
  punto eval(double x) { return x *v + p; }
};

bool inter_seg(recta &r1, recta &r2, ld &ans) {
  if (r1.p == r2.p or r1.p == r2.p + r2.v) {
    ans = 0; return true; 
  }
  if (r1.p + r1.v == r2.p or r1.p + r1.v == r2.p + r2.v) {
    ans = 1; return true; // Casos que coincidan extremos
  }
  if (abs(r1.v ^ r2.v) < EPS) return false; 
  ld alpha = ld((r2.p - r1.p) ^r2.v) / ld(r1.v^r2.v); 
  ld beta = ld((r1.p - r2.p) ^r1.v) / ld(r2.v^r1.v); 
  if (alpha < -EPS or beta < -EPS) return false;
  if (alpha > 1.0+EPS or beta > 1.0+EPS) return false; 
  ans = alpha; return true; 
}

int main() {
  FIN;
  int n; cin >> n;
  vector <punto> p(n);
  forn(i,n) cin >> p[i].x >> p[i].y;
  vector <recta> rs(n);
  forn(i,n) rs[i]=recta(p[i],p[(i+1)%n]);
  ld ans=0;
  forn(i,n) forr(j,i+1,n){
    recta r(p[i],p[j]);
    if(((p[(i+1)%n]-p[i])^(p[(i+n-1)%n]-p[i]))>0){
      if(((p[j]-p[i])^(p[(i+1)%n]-p[i]))>0 or ((p[j]-p[i])^(p[(i+n-1)%n]-p[i]))<0) continue;
    }
    else{
      if(((p[j]-p[i])^(p[(i+1)%n]-p[i]))>0 and ((p[j]-p[i])^(p[(i+n-1)%n]-p[i]))<0) continue;
    }
    if(((p[(j+1)%n]-p[j])^(p[(j+n-1)%n]-p[j]))>0){
      if(((p[i]-p[j])^(p[(j+1)%n]-p[j]))>0 or ((p[i]-p[j])^(p[(j+n-1)%n]-p[j]))<0) continue;
    }
    else{
      if(((p[i]-p[j])^(p[(j+1)%n]-p[j]))>0 and ((p[i]-p[j])^(p[(j+n-1)%n]-p[j]))<0) continue;
    }
    bool choca=false;
    ld aux;
    forn(k,n) if(inter_seg(r,rs[k],aux) and aux >EPS and aux<1-EPS) choca=true;
    if(choca) continue;
    punto q=p[i]-p[j];
    ans=max(ans,q.mod());
    recta r1, r2;
    r1.p=p[i]; r2.p=p[j];
    r1.v=INF*(p[i]-p[j]); r2.v=INF*(p[j]-p[i]);
    ld aux1=1, aux2=1;
    forn(k,n){
      if(inter_seg(r1,rs[k],aux) and aux>EPS) aux1=min(aux1,aux);
      if(inter_seg(r2,rs[k],aux) and aux>EPS) aux2=min(aux2,aux);
    }
    if(aux1>1-EPS and aux2>1-EPS) continue;
    if(aux1>1-EPS){
      ans=max(ans,sqrtl(((ld)(p[i].x)-p[j].x-aux2*r2.v.x)*((ld)(p[i].x)-p[j].x-aux2*r2.v.x)+((ld)(p[i].y)-p[j].y-aux2*r2.v.y)*((ld)(p[i].y)-p[j].y-aux2*r2.v.y)));
    }
    else if(aux2>1-EPS){
      ans=max(ans,sqrtl((aux1*r1.v.x+p[i].x-p[j].x)*(aux1*r1.v.x+p[i].x-p[j].x)+(aux1*r1.v.y+p[i].y-p[j].y)*(aux1*r1.v.y+p[i].y-p[j].y)));
    }
    else{
      ans=max(ans,sqrtl((aux1*r1.v.x+p[i].x-p[j].x-aux2*r2.v.x)*(aux1*r1.v.x+p[i].x-p[j].x-aux2*r2.v.x)+(aux1*r1.v.y+p[i].y-p[j].y-aux2*r2.v.y)*(aux1*r1.v.y+p[i].y-p[j].y-aux2*r2.v.y)));
    }
  }
  cout << setprecision(10) << fixed << ans << "\n";
  return 0;
}
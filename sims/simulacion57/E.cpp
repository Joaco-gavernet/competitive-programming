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
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"

typedef ld tipo;
const ld EPS=1e-10;
const ld pi=acos(-1);
struct punto {
  tipo x, y; 
  punto const operator -(const punto &p) const { return {x -p.x, y -p.y}; }
  punto const operator +(const punto &p) const { return {x +p.x, y +p.y}; }
  tipo operator * (const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^ (const punto &p) const { return x*p.y - y*p.x; }
  bool operator == (const punto &p) const {
    return (abs(x-p.x) < EPS and abs(y-p.y) < EPS); 
  }
  bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; }
  tipo arg() { return atan2(y,x); }
  tipo mod() { return sqrtl(x*x + y*y); }
  tipo mod2() { return x*x + y*y; }
};

punto operator* (tipo k, const punto &p) { return {k*p.x, k*p.y}; }

struct recta {
  punto v, p; 
  recta(punto p1, punto p2) {
    v = (p2 -p1); p = p1; 
  }
  recta() {}
  recta(tipo A, tipo B, tipo C) {
    v = {-B, A}; A != 0 ? p = {-C / A, 0} : p = {0, -C / B};
  }
  bool is_in(punto q) { return fabs((q.x-p.x) * v.y - (q.y -p.y) *v.x) < EPS; }
  punto eval(double x) { return x*v + p; }
};

bool inter_seg(recta &r1, recta &r2, punto &ans){
  if(r1.p==r2.p || r1.p == r2.p+r2.v) {ans=r1.p; return true;}
  if(r1.p+r1.v == r2.p || r1.p+r1.v == r2.v) {ans=r1.p+r1.v; return false;}
  if(abs(r1.v ^ r2.v) < EPS) return false; //No pasa
  tipo alpha = tipo((r2.p-r1.p)^r2.v) / tipo(r1.v^r2.v);
  tipo beta = tipo((r1.p-r2.p)^r1.v) / tipo(r2.v^r1.v);
  if(alpha < -EPS || beta < -EPS) return false;
  if(alpha > 1.0+EPS || beta > 1.0+EPS) return false;
  ans=r1.p+alpha*r1.v; return true;
}

bool inter_seg_2(recta &r1, recta &r2, punto &ans){
  if(r1.p==r2.p || r1.p == r2.p+r2.v) {ans=r1.p; return true;}
  if(r1.p+r1.v == r2.p || r1.p+r1.v == r2.v) {ans=r1.p+r1.v; return true;}
  if(abs(r1.v ^ r2.v) < EPS) return false; //No pasa
  tipo alpha = tipo((r2.p-r1.p)^r2.v) / tipo(r1.v^r2.v);
  tipo beta = tipo((r1.p-r2.p)^r1.v) / tipo(r2.v^r1.v);
  if(alpha < -EPS || beta < -EPS) return false;
  if(alpha > 1.0+EPS || beta > 1.0+EPS) return false;
  ans=r1.p+alpha*r1.v; return true;
}

int main() {
  FIN;
  cout<<fixed<<setprecision(10);
  vector<punto> rect(4);
  forn(i,4) cin>>rect[i].x>>rect[i].y;
  tipo w,h; cin>>w>>h;
  tipo ratio=h/w;
  if(rect[0]==rect[1] or rect[1]==rect[2] or rect[2]==rect[3] or rect[3]==rect[0]){cout<<"0\n"; return 0;}
  if(rect[0].x == rect[1].x){
    tipo base=rect[3].x-rect[0].x;
    tipo altura=rect[1].y-rect[0].y;
    tipo ans;
    if(altura/ratio > base) ans=base*base*ratio;
    else ans=altura*altura/ratio;
    cout<<ans<<"\n";
    return 0;
  }

  punto p=rect[0]-rect[1];
  punto p2=rect[2]-rect[1];
  ld b=p.y; ld a=p.x;
  ld l=p.mod();
  ld l2=p2.mod();
  if(l2+EPS<l){forn(i,4) rect[i].x*=-1; swap(rect[1],rect[3]);}
  p=rect[0]-rect[1];
  p2=rect[2]-rect[1];
  b=p.y; a=p.x;
  l=p.mod();
  l2=p2.mod();
  ld cosp=abs(a/l);
  ld sinp=abs(b/l);
  ld lmax=l/(sinp*ratio+cosp);
  ld ladodos=l2/(cosp*ratio+sinp);
  if(ladodos+EPS<lmax) lmax=ladodos;
  // DBG(lmax);
  ld ans=lmax*lmax*ratio;
  cout<<ans<<"\n";
  return 0;
}
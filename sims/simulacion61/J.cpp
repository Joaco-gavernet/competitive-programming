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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================" << endl
#define ff first
#define ss second

typedef long double tipo; 
double EPS = (double)(1e-10); 
struct punto {
  tipo x, y; 
  punto const operator -(const punto &p) const { return {x-p.x, y-p.y}; }
  punto const operator +(const punto &p) const { return {x+p.x, y+p.y}; }
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

punto operator * (tipo k, const punto p) { return {k*p.x, k*p.y}; }

struct recta {
  punto v, p; 
  recta(punto p1, punto p2) { v = (p2-p1); p = p1; }
  recta() {}
  recta(tipo A, tipo B, tipo C) {
    v = {-B, A}; A != 0 ? p = {-C /A, 0} : p = {0, -C/B};
  }
  bool is_in(punto q) { return  fabs((q.x -p.x)*v.y - (q.y-p.y)*v.x) < EPS; }
  punto eval(double x) { return x *v +p; }
};

bool inter_seg(recta &r1, recta &r2) {
  if (abs(r1.v ^ r2.v) < EPS) return false;
  tipo alpha = tipo((r2.p -r1.p)^r2.v) / tipo(r1.v^r2.v); 
  tipo beta = tipo((r1.p -r2.p)^r1.v) / tipo(r2.v^r1.v); 
  if (alpha < EPS or beta < EPS) return false;
  if (alpha > 1.0-EPS or beta > 1.0-EPS) return false;
  return true;  
}



int main() {
  FIN;
  int w, h, sx, sy, ex, ey; cin >> w >> h >> sx >> sy >> ex >> ey;
  vector <vi> v(h/2,vi(w/2));
  forn(i,h/2) forn(j,w/2) cin>> v[i][j];
  punto s={sy,sx}, e={ey,ex}, aux=s-e;
  ld ans=aux.mod();
  if(s>e) swap(s,e);
  recta l(s,e);
  forn(i,w/2+1) forn(j,h/2){
    punto a={2*j,2*i}, b={2*j+2,2*i};
    recta r(a,b);
    if(inter_seg(l,r)) ans+=abs(v[j][i]-v[j][i-1]);
  }
  forn(j,h/2+1) forn(i,w/2){
    punto a={2*j,2*i}, b={2*j,2*i+2};
    recta r(a,b);
    if(inter_seg(l,r)) ans+=abs(v[j-1][i]-v[j][i]);
  }
  forn(i,w/2+1) forn(j,h/2+1){
    punto a={2*j,2*i};
    if(l.is_in(a and s<a and a<e)){
      punto b=s-a;
      if(b.x<0){
        ll t=min(v[j-1][i],v[i-1][j]);
        if(t>)
      }
      else{

      }
    }
  }
  return 0;
}
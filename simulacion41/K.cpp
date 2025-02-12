#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<ii> vii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"
#define DBGV(v,n) forn(_,n) cerr<< v[_]<<" "


typedef long double tipo; 
double EPS = (double)(1e-10); 

struct punto {
  tipo x, y; int id;
  punto const operator -(const punto &p) const { return {x-p.x, y-p.y,-1}; }
  punto const operator +(const punto &p) const { return {x+p.x, y+p.y,-1}; }
  tipo operator *(const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^(const punto &p) const { return x*p.y - y*p.x; }
  bool operator == (const punto &p) const {
    return (abs(x-p.x) < EPS and abs(y-p.y) < EPS); 
  } 
  bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; }
  tipo arg() { return atan2(y, x); }
  tipo mod() { return sqrtl(x*x + y*y); }
  tipo mod2() { return x*x + y*y; }
}; 

punto operator * (tipo k, const punto &p) { return {k*p.x, k*p.y,-1}; } 

struct recta {
  punto v, p; 
  recta (punto p1, punto p2) { v = (p2-p1); p = p1; } 
  recta() {}
  recta (tipo A, tipo B, tipo C) {
    v = {-B, A,-1}; A != 0 ? p = {-C /A, 0,-1} : p = {0, -C /B,-1};
  } 
  bool is_in(punto q) { return fabs((q.x-p.x)*v.y -(q.y-p.y)*v.x) < EPS; }
  punto eval(double x) { return x *v +p; } 
}; 

struct circ { punto c; tipo r; }; 

tipo dist_point_line(punto &p, recta &r) {
  punto p1 = r.p, p2 = r.p +r.v; 
  return fabs((p1-p)^(p2-p)) /r.v.mod(); 
} 

punto project(punto a, punto b) {
  return ((a*b) /a.mod2()) *a; 
} 

vector<punto> inter_circ_line(recta r, circ c) {
  vector<punto> ans; tipo dist = dist_point_line(c.c, r); 
  if (dist > c.r+EPS) return ans; 
  (c.c-r.p) *r.v != 0 ? r.p = r.p : r.p = r.p + r.v; 
  punto aux = c.c -r.p, dir = project(r.v, aux); 
  if (fabs(dist-c.r) <= EPS) { ans.pb(r.p +dir); return ans; } 
  tipo factor = sqrt(c.r*c.r - dist*dist) /dir.mod(); 
  ans.pb(r.p +dir +(factor *dir)); ans.pb(r.p +dir -(factor*dir)); 
  return ans; 
} 

vector<punto> inter_circ_circ(circ a, circ b) {
  vector<punto> ans; 
  if (a.c == b.c) {
    return abs(a.r -b.r) <= EPS ? vector<punto>{a.c, a.c, a.c} : ans; } 
  b.c = b.c -a.c; punto aux = a.c; a.c = a.c -a.c; 
  recta r(-2*b.c.x, -2*b.c.y, a.r*a.r -b.r*b.r +b.c.x*b.c.x +b.c.y*b.c.y); 
  ans = inter_circ_line(r,a); 
  forn(i,ans.size()) ans[i] = ans[i] +aux; 
  return ans; 
} 


int main() {
  FIN; 
  
  int n; cin >> n; 
  vector<circ> v(n); 
  forn(i,n) cin >> v[i].c.x >> v[i].c.y >> v[i].r; 
  vector <vector<vector<punto>>> f(n);
  int cont=0;
  forn(i,n) forr(j,i+1,n){
    vector <punto> aux=inter_circ_circ(v[i],v[j]),_aux;
    forn(k,SZ(aux)){
      bool si=true;
      forn(q,n) if(q!=i and q!=j){
	punto t=v[q].c-aux[k];
	if(t.mod()<v[q].r+EPS) {si=false; cout << i << " " << j << " " << q << endl;}
      }
      if(si) _aux.pb(aux[k]);
    }
    forn(q,SZ(_aux)){
      aux[q].id=cont;
      cont++;
    }
    DBG(i); DBG(j); DBG(SZ(_aux));
    if(SZ(_aux)>0){
      f[i].pb(_aux);
      f[j].pb(_aux);
    }
  }
  vector <vi> g(cont);
  forn(i,n){
    DBG(i);
    forn(j,SZ(f[i])){
      forn(q,SZ(f[i][j])) cout << f[i][j][q].x << " " << f[i][j][q].y << " ";
      cout << endl;
    }
    RAYA;
  }
  return 0; 
} 




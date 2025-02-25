#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

typedef long double tipo; 
tipo EPS = (tipo)1e-10; 
const tipo pi = acosl(-1);

struct punto {
  tipo x, y; int id=-1;
  punto const operator -(const punto &p) const { return {x-p.x, y-p.y}; }
  punto const operator +(const punto &p) const { return {x+p.x, y+p.y}; }
  tipo operator *(const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^(const punto &p) const { return x*p.y - y*p.x; }
  bool operator == (const punto &p) const {
    return (fabsl(x-p.x) < EPS and fabsl(y-p.y) < EPS); 
  }
  bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; }
  tipo arg() { return atan2l(y,x); }
  tipo mod() { return sqrtl(x*x + y*y); }
  tipo mod2() { return x*x + y*y; }
}; 

punto operator*(tipo k, const punto &p) { return {k*p.x, k*p.y}; }

void convex_hull(vector<punto> &a) {
  if (SZ(a) == 1) return; 
  sort(all(a)); 
  punto p1 = a[0]; 
  vector<punto> up, down; 
  up.pb(p1); down.pb(p1); 
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
  for (punto u: up) a.pb(u); 
  for (int i = SZ(down) -2; i > 0; i--) a.pb(down[i]); 
}

struct recta {
  punto v, p; 
  recta(punto p1, punto p2) {
    v = (p2-p1); 
    p = p1; 
  }
  recta() {}
  recta(tipo A, tipo B, tipo C) {
    v = {-B, A}; A != 0 ? p = {-C / A, 0} : p = {0, -C / B}; 
  }
  bool is_in(punto q) { return fabsl((q.x-p.x)*v.y -(q.y-p.y)*v.x) < EPS; }
  punto eval(double x) { return x*v + p; }
}; 

struct circ { punto c; tipo r; }; 

punto project(punto a, punto b) {
  return ((a*b)/a.mod2()) *a; 
}

tipo dist_point_line(punto &p, recta &r) {
  punto p1 = r.p, p2 = r.p + r.v; 
  return fabsl((p1-p)^(p2-p)) /r.v.mod(); 
}

vector<punto> inter_circ_line(recta r, circ c) {
  vector<punto> ans; tipo dist = dist_point_line(c.c, r); 
  if (dist > c.r +EPS) return ans; 
  (c.c -r.p) *r.v != 0 ? r.p = r.p : r.p = r.p + r.v; 
  punto aux = c.c - r.p, dir = project(r.v, aux); 
  if (fabsl(dist-c.r) <= EPS) { ans.pb(r.p +dir); return ans; }
  tipo factor = sqrtl(c.r*c.r - dist*dist) /dir.mod(); 
  ans.pb(r.p + dir + factor*dir); ans.pb(r.p + dir - factor * dir); 
  return ans; 
}

void tangent(punto c, tipo r1, tipo r2, vector<recta> &ans) {
  tipo r = r2 -r1; 
  tipo z = c.mod2(); 
  tipo d = z -r*r; 
  if (d < -EPS) return; 
  d = sqrtl(fabsl(d)); 
  recta l((c.x * r + c.y * d) / z,(c.y * r - c.x * d) / z,r1); 
  ans.pb(l); 
}

vector<recta> tangents(circ a, circ b) {
  vector<recta> ans; 
  tangent (b.c-a.c, -a.r, -b.r, ans);
  tangent (b.c-a.c, a.r, b.r, ans); 
  for (int i = 0; i < SZ(ans); ++i) {
    ans[i].p=ans[i].p+a.c;
  } 
  return ans; 
}

tipo cono(circ c, punto a, punto b){
  a=a-c.c; b=b-c.c;
  tipo ang=fabsl(a.arg()-b.arg());
  return min(ang, 2*pi-ang)*c.r;
}

int main() {
  FIN; 
  cout << fixed << setprecision(10);
  int n; cin >> n;
  vector <circ> v(n);
  forn(i,n){cin >> v[i].c.x >> v[i].c.y >> v[i].r; v[i].r+=10;}
  int vivos=n;
  vb vivo(n,true);
  forn(i,n) forn(j,n) if(i!=j and vivo[j] and vivo[i]){
    punto aux=v[i].c-v[j].c;
    if(v[j].r+aux.mod()<=EPS+v[i].r) {vivo[j]=false; vivos--;}
  }
  if(vivos==1){
    forn(i,n) if(vivo[i]){
      tipo ans=pi*2*v[i].r;
      cout << ans << "\n";
      return 0;
    }
  }
  vector <punto> p;
  forn(i,n) forr(j,i+1,n) if(vivo[i] and vivo[j]){
    vector <recta> aux=tangents(v[i],v[j]);
    forn(k,SZ(aux)){
      vector <punto> aux2=inter_circ_line(aux[k],v[i]);
      aux2[0].id=i; p.pb(aux2[0]);
      aux2=inter_circ_line(aux[k],v[j]);
      aux2[0].id=j; p.pb(aux2[0]);
    }
  }
  convex_hull(p);
  tipo ans=0;
  forn(i,SZ(p)){
    int j=(i+1)%SZ(p);
    if(p[j].id!=p[i].id){
      punto aux=p[i]-p[j];
      ans+=aux.mod();
    } else ans += cono(v[p[i].id], p[i], p[j]);
  }
  cout << ans << "\n";
  return 0;
}

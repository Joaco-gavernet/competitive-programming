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
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

typedef long double tipo; 
const tipo EPS = 1e-6; 

struct punto {
  tipo x, y; 
  punto const operator -(const punto &p) const { return {x-p.x, y-p.y}; }
  punto const operator +(const punto &p) const { return {x+p.x, y+p.y}; }
  tipo operator *(const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^(const punto &p) const { return x*p.y - y*p.x; }
  bool operator == (const punto &p) const {
    return (abs(x-p.x) < EPS and abs(y-p.y) < EPS); 
  }
  tipo arg() { return atan2(y,x); }
  tipo mod() { return sqrtl(x*x + y*y); }
  tipo mod2() { return x*x + y*y; }
};

punto operator* (tipo k, const punto &p) { return {k*p.x, k*p.y}; }

struct recta {
  punto v, p; 
  recta (punto p1, punto p2) { v = (p2-p1); p = p1; }
  recta() {}
  recta(tipo A, tipo B, tipo C) {
    v = {-B, A}; A != 0 ? p = {-C /A, 0} : p = {0, -C/B}; 
  }
  bool is_in(punto q) { return fabs((q.x-p.x)*v.y - (q.y-p.y)*v.x) < EPS; }
  punto eval(double x) { return x*v +p; }
}; 

struct circ {
  punto c; tipo r; 
};

tipo dist_point_line(punto &p, recta &r) {
  punto p1 = r.p, p2 = r.p +r.v; 
  return fabs((p1-p)^(p2-p)) /r.v.mod();
}

punto project(punto a, punto b) {
  return ((a*b) /a.mod2()) *a; 
}

vector<punto> inter_circ_line(recta r, circ c) {
  vector<punto> ans; tipo dist = dist_point_line(c.c,r);
  if (dist > c.r+EPS) return ans;
  if ((c.c-r.p) *r.v == 0) r.p = r.p + r.v; 
  punto aux = c.c -r.p, dir = project(r.v, aux);
  if (fabs(dist-c.r) <= EPS) { ans.pb(r.p + dir); return ans; }
  tipo factor = sqrt(c.r*c.r - dist*dist) /dir.mod();
  ans.pb(r.p + dir + factor*dir); ans.pb(r.p + dir -factor*dir);
  return ans; 
}


int main() {
  FIN;
  int n; cin >> n;
  vector <punto> p(n);
  forn(i,n){
    int x, y; cin >> x >> y;
    p[i]={x,y};
  }
  ld ans=0;
  cout << setprecision(10) << fixed;
  forn(i,n){
    punto l1=p[i]-p[(i+n-1)%n],l2=p[i]-p[(i+1)%n],l=p[(i+n-1)%n]-p[(i+1)%n];
    ld old=l1.mod()+l2.mod();
    recta r1(p[(i+n-1)%n],p[(i+n-2)%n]), r2(p[(i+1)%n],p[(i+2)%n]);
    swap(r1.v.x,r1.v.y); swap(r2.v.x,r2.v.y);
    r1.v.x*=-1; r2.v.x*=-1;
    circ c={0.5*(p[(i+n-1)%n]+p[(i+1)%n]),l.mod()/2};
    vector <punto> q1=inter_circ_line(r1,c),q2=inter_circ_line(r2,c);
    if(q1[0]==p[(i+n-1)%n]) swap(q1[0],q1[1]);
    if(q2[0]==p[(i+1)%n]) swap(q2[0],q2[1]);
    cout << q1[0].x << " " << q1[0].y << "\n";
    cout << q2[0].x << " " << q2[0].y << "\n";
    ld best=0;
    punto aux1=q1[0]-p[(i+n-1)%n], aux2=q1[0]-p[(i+1)%n];
    max(aux1.mod()+aux2.mod(),best);
    aux1=q2[0]-p[(i+n-1)%n], aux2=q2[0]-p[(i+1)%n];
    max(aux1.mod()+aux2.mod(),best);
    punto d=l;
    swap(d.x,d.y); d.x*=-1;
    bool b1=((d^(q1[0]-c.c))>0), b2=((d^(q2[0]-c.c))>0);
    if(b1!=b2) best=max(best,l.mod()*sqrtl(2));
    ans=max(ans,best-old);
  }
  cout << ans << "\n";
  return 0; 
}

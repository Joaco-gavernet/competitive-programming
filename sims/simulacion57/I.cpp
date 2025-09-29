#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

typedef ll tipo;

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

struct circ { punto c; tipo r; }

tipo dist_point_line(punto &p, recta &r) {
  punto p1 = r.p, p2 = r.p + r.v; 
  return fabs((p1-p) ^ (p2-p)) /r.v.mod();
}

punto project(punto a, punto b) {
  return ((a*b) / a.mod2()) *a;
}

vector<punto> inter_circ_line(recta r, circ c) {
  vector<punto> ans; tipo dist = dist_point_line(c.c, r); 
  if (dist > c.r + EPS) return ans;
  (c.c -r.p) * r.v != 0 ? r.p = r.p : r.p = r.p + r.v;
  punto aux = c.c - r.p, dir = project(r.v, aux); 
  if (fabs(dist-c.r) <= EPS) { ans.pb(r.p + dir); return ans; }
  tipo factor = sqrt(c.r * c.r -dist*dist) /dir.mod();
  ans.pb(r.p + dir + factor *dir); ans.pb(r.p + dir - factor *dir);
  return ans; 
}


int main() {
  FIN;

  return 0;
}
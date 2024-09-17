#include <bits/stdc++.h>
using namespace std;

// template punto
typedef long long ll; 
typedef long double tipo; 
double EPS = (double)(1e-10);

struct punto {
  tipo x,y;
  //~ ll brightness;
  
  // TODO ...
  punto const operator - (const punto &p) const { return {x-p.x, y-p.y}; }
  punto const operator + (const punto &p) const { return {x+p.x, y+p.y}; }
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

ostream &operator << (ostream &os, const punto &p) {
  return os << "(" << p.x << "," << p.y << ")";
}

istream &operator >> (istream &is, punto &p) {
  return is >> p.x >> p.y;
}


// struct recta
struct recta {
  punto v, p; 
  recta (punto p1, punto p2) {
    v = (p2-p1); p = p1;
  }
  recta () {}
  recta (tipo A, tipo B, tipo C) {
    v = {-B,A}; 
    A != 0 ? p = {-C / A, 0} : p = {0, -C / B};
  }
  bool is_in(punto q) { return fabs((q.x-p.x)*v.y - (q.y-p.y)*v.x) < EPS; }
  punto eval(double x) { return x*v + p; }
};

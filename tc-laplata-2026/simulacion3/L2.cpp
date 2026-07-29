#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n"
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);\
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
using ld = long double; 
using tipo = ld; 

const ld EPS = 1e-12; 
const ld EPSS = 1e-7L; 
const ld AREA = 1e-20L; 
const ld DINF = 1e200; 

struct pt {  // for 3D add z coordinate
  tipo x,y;
  pt(tipo x, tipo y):x(x),y(y){}
  pt(){}
  tipo norm2(){return *this**this;}
  tipo norm(){return sqrt(norm2());}
  bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
  pt operator+(pt p){return pt(x+p.x,y+p.y);}
  pt operator-(const pt p) const {return pt(x-p.x,y-p.y);}
  pt operator*(tipo t){return pt(x*t,y*t);}
  pt operator/(tipo t){return pt(x/t,y/t);}
  tipo operator*(pt p){return x*p.x+y*p.y;}
  //	pt operator^(pt p){ // only for 3D
  //		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
  tipo angle(pt p) {
    tipo cosine = (*this * p) / (norm() * p.norm());
    return acosl(clamp(cosine, (tipo)-1, (tipo)1));
  }
  pt unit(){return *this/norm();}
  tipo operator%(pt p){return x*p.y-y*p.x;}
  // 2D from now on
  bool operator<(pt p)const{ // for convex hull
    return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
  bool left(pt p, pt q){ // is it to the left of directed line pq?
    return (q-p)%(*this-p)>EPS;}
  pt rot(pt r){return pt(*this%r,*this*r);}
  pt rot(tipo a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);

struct Cmp {
  pt r;

  Cmp(pt r) : r(r) {}

  int cuad(const pt& a) const {
    if (a.x > 0  && a.y >= 0) return 0;
    if (a.x <= 0 && a.y > 0)  return 1;
    if (a.x < 0  && a.y <= 0) return 2;
    if (a.x >= 0 && a.y < 0)  return 3;

    assert(a.x == 0 && a.y == 0);
    return -1;
  }

  bool cmp(const pt& p1, const pt& p2) const {
    int c1 = cuad(p1);
    int c2 = cuad(p2);

    if (c1 == c2)
      return p1.y * p2.x < p1.x * p2.y;

    return c1 < c2;
  }

  bool operator()(const pt& p1, const pt& p2) const {
    return cmp(p1 - r, p2 - r);
  }
};

int sgn2(tipo x){return x<0?-1:1;}
struct ln {
  pt p,pq;
  ln(pt p, pt q):p(p),pq(q-p){}
  ln(){}
  bool has(pt r){return dist(r)<=EPS;}
  bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
  //	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
  bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
  bool operator==(ln l){return *this/l&&has(l.p);}
  pt operator^(ln l){ // intersection
    if(*this/l)return pt(DINF,DINF);
    pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
    //		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
    return r;
  }
  tipo angle(ln l){return pq.angle(l.pq);}
  int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
  pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
  pt ref(pt r){return proj(r)*2-r;}
  tipo dist(pt r){return (r-proj(r)).norm();}
  //	tipo dist(ln l){ // only 3D
  //		if(*this/l)return dist(l.p);
  //		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
  //	}
  ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(ln l, ln m){ // angle bisector
  pt p=l^m;
  return ln(p,p+l.pq.unit()+m.pq.unit());
}
ln bisector(pt p, pt q){ // segment bisector (2D)
  return ln((p+q)*.5,p).rot(ccw90);
}

struct circle {
  pt o;tipo r;
  circle(pt o, tipo r):o(o),r(r){}
  circle(pt x, pt y, pt z){o=bisector(x,y)^bisector(x,z);r=(o-x).norm();}
  bool has(pt p){return (o-p).norm()<=r+EPS;}
  vector<pt> operator^(circle c){ // ccw
    vector<pt> s;
    tipo d=(o-c.o).norm();
    if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
    tipo x=(d*d-c.r*c.r+r*r)/(2*d);
    tipo y=sqrt(r*r-x*x);
    pt v=(c.o-o)/d;
    s.pb(o+v*x-v.rot(ccw90)*y);
    if(y>EPS)s.pb(o+v*x+v.rot(ccw90)*y);
    return s;
  }
  vector<pt> operator^(ln l){
    vector<pt> s;
    pt p=l.proj(o);
    tipo d=(p-o).norm();
    if(d-EPS>r)return s;
    if(abs(d-r)<=EPS){s.pb(p);return s;}
    d=sqrt(r*r-d*d);
    s.pb(p+l.pq.unit()*d);
    s.pb(p-l.pq.unit()*d);
    return s;
  }
  vector<pt> tang(pt p){
    tipo d=sqrt((p-o).norm2()-r*r);
    return *this^circle(p,d);
  }
  bool in(circle c){ // non strict
    tipo d=(o-c.o).norm();
    return d+r<=c.r+EPS;
  }
  tipo intertriangle(pt a, pt b){ // area of intersection with oab
    if(abs((o-a)%(o-b))<=EPS)return 0.;
    vector<pt> q={a},w=*this^ln(a,b);
    if(w.size()==2)for(auto p:w)if((a-p)*(b-p)<-EPS)q.pb(p);
    q.pb(b);
    if(q.size()==4&&(q[0]-q[1])*(q[2]-q[1])>EPS)swap(q[1],q[2]);
    tipo s=0;
    fore(i,0,q.size()-1){
      if(!has(q[i])||!has(q[i+1]))s+=r*r*(q[i]-o).angle(q[i+1]-o)/2;
      else s+=abs((q[i]-o)%(q[i+1]-o)/2);
    }
    return s;
  }
};

vector<tipo> intercircles(vector<circle> c){
  vector<tipo> r(SZ(c)+1); // r[k]: area covered by at least k circles
  fore(i,0,SZ(c)){           // O(n^2 log n) (high constant)
    int k=1;Cmp s(c[i].o);
    vector<pair<pt,int> > p={
      {c[i].o+pt(1,0)*c[i].r,0},
      {c[i].o-pt(1,0)*c[i].r,0}};
    fore(j,0,SZ(c))if(j!=i){
      bool b0=c[i].in(c[j]),b1=c[j].in(c[i]);
      if(b0&&(!b1||i<j))k++;
      else if(!b0&&!b1){
        auto v=c[i]^c[j];
        if(SZ(v)==2){
          p.pb({v[0],1});p.pb({v[1],-1});
          if(s(v[1],v[0]))k++;
        }
      }
    }
    sort(p.begin(),p.end(),
        [&](pair<pt,int> a, pair<pt,int> b){return s(a.fst,b.fst);});
    fore(j,0,SZ(p)){
      pt p0=p[j?j-1:SZ(p)-1].fst,p1=p[j].fst;
      tipo a=(p0-c[i].o).angle(p1-c[i].o);
      r[k]+=(p0.x-p1.x)*(p0.y+p1.y)/2+c[i].r*c[i].r*(a-sin(a))/2;
      k+=p[j].snd;
    }
  }
  return r;
}

using tipo = ld; 


int main() {
  FIN;

  ll n; tipo r; cin >> n >> r;
  vector<pt> v(n); forn(i,n) cin >> v[i].x >> v[i].y; 
  vector<circle> c; c.reserve(n); forn(i,n) c.emplace_back(v[i], r + EPSS); 
  vector<tipo> ans = intercircles(c); 

  int i = 1; 
  while (i < SZ(ans) && fabsl(ans[i]) > AREA) i++;
  cout << i - 1 << '\n'; 

  return 0; 
}

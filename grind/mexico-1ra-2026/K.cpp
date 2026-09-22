#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long; 
using vi = vector<ll>; 
using vb = vector<bool>; 
using ii = pair<ll,ll>; 
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define fore(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first 
#define snd second 


using ld = long double; 
const ld EPS = 1e-18L; 
const ld DINF = 1e100; 

struct pt {  // for 3D add z coordinate
  double x,y;
  pt(double x, double y):x(x),y(y){}
  pt(){}
  double norm2(){return *this**this;}
  double norm(){return sqrt(norm2());}
  bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
  pt operator+(pt p) const {return pt(x+p.x,y+p.y);}
  pt operator-(pt p) const {return pt(x-p.x,y-p.y);}
  pt operator*(double t){return pt(x*t,y*t);}
  pt operator/(double t){return pt(x/t,y/t);}
  double operator*(pt p){return x*p.x+y*p.y;}
  //	pt operator^(pt p){ // only for 3D
  //		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
  double angle(pt p){ // redefine acos for values out of range
    return acos(*this*p/(norm()*p.norm()));}
  pt unit(){return *this/norm();}
  double operator%(pt p){return x*p.y-y*p.x;}
  bool operator<(pt p)const{ // for convex hull
    return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
  bool left(pt p, pt q){return (q-p)%(*this-p)>EPS;}
  pt rot(pt r){return pt(*this%r,*this*r);}
  pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0), cw90(-1,0);

struct Cmp{//IMPORTANT: add const in pt operator -
  pt r;
  Cmp(pt r):r(r){}
  int cuad(const pt &a)const {
    if(a.x>0&&a.y>=0)return 0;
    if(a.x<=0&&a.y>0)return 1;
    if(a.x<0&&a.y<=0)return 2;
    if(a.x>=0&&a.y<0)return 3;
    assert(a.x==0&&a.y==0);
    return -1;
  }
  bool cmp(const pt& p1, const pt& p2)const {
    int c1=cuad(p1),c2=cuad(p2);
    if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
    return c1<c2;
  }
  bool operator()(const pt& p1,const pt& p2)const {
    return cmp(p1-r,p2-r);
  }
};

int sgn2(double x){return x<0?-1:1;}
struct ln {
  pt p,pq;
  ln(pt p, pt q):p(p),pq(q-p){}
  ln(){}
  bool has(pt r){return dist(r)<=EPS;}
  bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
  //bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;}//3D
  bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
  bool operator==(ln l){return *this/l&&has(l.p);}
  pt operator^(ln l){ // intersection
    if(*this/l)return pt(DINF,DINF);
    pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
    //		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
    return r;
  }
  double angle(ln l){return pq.angle(l.pq);}
  int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
  pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
  pt ref(pt r){return proj(r)*2-r;}
  double dist(pt r){return (r-proj(r)).norm();}
  //	double dist(ln l){ // only 3D
  //		if(*this/l)return dist(l.p);
  //		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
  //	}
  ln rot(auto a){return ln(p,p+pq.rot(a));}//2D
};
ln bisector(ln l, ln m){ // angle bisector
  pt p=l^m; return ln(p,p+l.pq.unit()+m.pq.unit());
}
ln bisector(pt p, pt q){//segment bisector (2D)
  return ln((p+q)*.5,p).rot(ccw90);
}

struct circle {
  pt o;double r;
  circle(pt o, double r):o(o),r(r){}
  circle(pt x,pt y,pt z){o=bisector(x,y)^bisector(x,z);r=(o-x).norm();}
  bool has(pt p){return (o-p).norm()<=r+EPS;}
  vector<pt> operator^(circle c){ // ccw
    vector<pt> s; double d=(o-c.o).norm();
    if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
    double x=(d*d-c.r*c.r+r*r)/(2*d), y=sqrt(r*r-x*x);
    pt v=(c.o-o)/d; s.pb(o+v*x-v.rot(ccw90)*y);
    if(y>EPS)s.pb(o+v*x+v.rot(ccw90)*y);
    return s;
  }
  vector<pt> operator^(ln l){
    vector<pt> s; pt p=l.proj(o); double d=(p-o).norm();
    if(d-EPS>r)return s;
    if(abs(d-r)<=EPS){s.pb(p);return s;}
    d=sqrt(r*r-d*d); s.pb(p+l.pq.unit()*d); s.pb(p-l.pq.unit()*d);
    return s;
  }
  vector<pt> tang(pt p){
    double d=sqrt((p-o).norm2()-r*r); return *this^circle(p,d);
  }
  bool in(circle c){ // non strict
    double d=(o-c.o).norm(); return d+r<=c.r+EPS;
  }
  double intertriangle(pt a, pt b){ // area of intersection with oab
    if(abs((o-a)%(o-b))<=EPS)return 0.;
    vector<pt> q={a},w=*this^ln(a,b);
    if(w.size()==2)for(auto p:w)if((a-p)*(b-p)<-EPS)q.pb(p);
    q.pb(b);
    if(q.size()==4&&(q[0]-q[1])*(q[2]-q[1])>EPS)swap(q[1],q[2]);
    double s=0;
    fore(i,0,q.size()-1){
      if(!has(q[i])||!has(q[i+1]))s+=r*r*(q[i]-o).angle(q[i+1]-o)/2;
      else s+=abs((q[i]-o)%(q[i+1]-o)/2);
    }
    return s;
  }
};

vector<ld> intercircles(vector<circle> c){
  vector<ld> r(SZ(c)+1); // r[k]: area covered by at least k circles
  fore(i,0,SZ(c)){//O(n^2 log n) high constant!
    int k=1;Cmp s(c[i].o);
    vector<pair<pt,int> > p={
      {c[i].o+pt(1,0)*c[i].r,0}, {c[i].o-pt(1,0)*c[i].r,0}};
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
      ld a=(p0-c[i].o).angle(p1-c[i].o);
      r[k]+=(p0.x-p1.x)*(p0.y+p1.y)/2+c[i].r*c[i].r*(a-sin(a))/2;
      k+=p[j].snd;
    }
  }
  return r;
}

const int ITER = 100; 
const ld EPS2 = 1e-14L; 

int main(){  
  NaN;
  cout << fixed << setprecision(10); 
  cerr << fixed << setprecision(10); 

  int n; cin >> n; 
  ll x, y; cin >> x >> y;  
  pt P(x, y); 

  vector<circle> v; 
  v.reserve(n); 
  forn(i,n) {
    ll r; cin >> x >> y >> r; 
    pt C(x, y); 
    v.emplace_back(C, r + EPS2); 
  } 

  ld l = 0.0, r = 1e10; 
  forn(_,ITER) {
    dbg(l, r); 
    ld mid = (l + r) / 2; 
    circle aux(P, mid); 
    v.pb(aux); 
    vector<ld> h = intercircles(v); 
    if (h[n + 1] > 0.0) r = mid;
    else l = mid; 
    v.pop_back(); 
  } 
  cout << r << '\n';

  return 0;
}

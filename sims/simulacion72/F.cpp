#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef long double ld;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"

const ld EPS = 1e-12;

struct circle{
  ld x; ld y; ld r; ld s;
};

circle fuse(vector<circle> &v){
  circle c; c.s=0;
  c.x=0;
  c.y=0;
  c.r=0;
  for(auto u:v){
    c.s=max(c.s,u.s);
    c.r+=u.r*u.r;
    c.x+=u.x;
    c.y+=u.y;
  }
  c.r=sqrtl(c.r);
  c.x/=SZ(v);
  c.y/=SZ(v);
  return c;
}

ld dist(circle &c1,circle &c2){
  ld dx=fabs(c1.x-c2.x);
  ld dy=fabs(c1.y-c2.y);
  return sqrtl(dx*dx+dy*dy);
}

void calcdist(vector<circle> &v, multiset<pair<ld,ii>> &choques){
  ll tam=SZ(v);
  forn(i,tam) forr(j,i+1,tam){
    circle c1=v[i];
    circle c2=v[j];
    ld t=(dist(c1,c2)-(c1.r+c2.r))/(c1.s+c2.s);
    choques.insert({t,{i,j}});
  }
  return;
}

bool intersect(circle &c1,circle &c2){
  if(c1.r+c2.r + EPS < dist(c1,c2)) return false;
  else return true;
}

bool keepfusing(vector<circle> &v, vb &b,circle &c){
  ll tam=SZ(v);
  vector<circle> elems;
  elems.pb(c);
  forn(i,tam) if(!b[i] and intersect(v[i],c)){
    elems.pb(v[i]);
    b[i]=true;
  }
  if(SZ(elems)>1){
    c=fuse(elems);
    return true;
  }
  else return false;
}

void dofuse(vector<circle> &v, multiset<pair<ld,ii>> &choques){
  ll tam=SZ(v);
  auto it=choques.begin();
  ld t=(*it).ff;
  ll c1=(*it).ss.ff;
  ll c2=(*it).ss.ss;
  forn(i,tam) v[i].r+=t*v[i].s;
  vector<circle> un;
  un.pb(v[c1]); un.pb(v[c2]);
  circle nue=fuse(un);
  vb fused(tam,false);
  fused[c1]=true; fused[c2]=true;
  while(keepfusing(v,fused,nue)){}
  vector<circle> clean;
  forn(i,tam) if(!fused[i]) clean.pb(v[i]);
  clean.pb(nue);
  v=clean;
  return;
}

int main() {
  NaN;
  cout<<fixed<<setprecision(10);
  ll n; cin>>n;
  
  vector<circle> v;
  forn(i,n){
    ll x,y,r,s; cin>>x>>y>>r>>s;
    v.pb({x,y,r,s});
  }
  while(SZ(v)>1){
    multiset<pair<ld,ii>> choques;
    calcdist(v,choques);
    dofuse(v,choques);
    // DBG(SZ(v));
  }
  cout<<v[0].x<<" "<<v[0].y<<"\n";
  cout<<v[0].r<<"\n";
  return 0; 
}
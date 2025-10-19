#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=======================" << endl 
#define ff first
#define ss second

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; 
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

typedef ll tipo;

struct punto {
  tipo x, y, id=-1; 
  punto const operator -(const punto &p) const { return {x-p.x, y-p.y, id}; }
  punto const operator +(const punto &p) const { return {x+p.x, y+p.y, id}; }
  tipo operator *(const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^(const punto &p) const { return x*p.y - y*p.x; }
  bool operator == (const punto &p) const {
    return (x == p.x and y == p.y);
  }
  bool operator < (punto p) const {
    return x != p.x ? x < p.x : y < p.y; 
  }
  tipo mod(){return x*x+y*y;}
};

punto operator * (tipo k, const punto &p) { return {k*p.x, k*p.y}; }
punto origin={0LL,0LL};
bool AngularSort(const punto &A, const punto &B) {
  bool aorig = (A < origin);
  bool borig = (B < origin);
  if (aorig != borig) { return aorig > borig; }
  if((A^B)==0) return (A.x*A.x+A.y*A.y>B.x*B.x+B.y*B.y);
  return (A^B) > 0;
}

ll solve1(punto s, punto e, vector <punto> v){
  int n=SZ(v);
  forn(i,n) v[i]=v[i]-s;
  sort(all(v),AngularSort);
  reverse(all(v));
  forn(i,n) cout << v[i].x+s.x << " " << v[i].y+s.y << endl;
  forn(i,n) v[i].id=i;
  forn(i,n) v[i]=v[i]+s-e;
  sort(all(v),AngularSort);
  //reverse(all(v));
  cout << "---" << endl;
  forn(i,n) cout << v[i].x+e.x << " " << v[i].y+e.y << endl;
  ll ans=0;
  indexed_set vis;
  forn(i,n){
    vis.insert(v[i].id);
    ans+=int(vis.order_of_key(v[i].id));
  }
  DBG(ans);
  RAYA;
  return ans;
}

ll solve2(punto s, punto e, vector <punto> v){
  int n=SZ(v);
  forn(i,n) v[i]=v[i]-s;
  sort(all(v),AngularSort);
  reverse(all(v));
  forn(i,n) cout << v[i].x+s.x << " " << v[i].y+s.y << endl;
  forn(i,n) v[i].id=i;
  forn(i,n) v[i]=v[i]+s-e;
  sort(all(v),AngularSort);
  reverse(all(v));
  cout << "---" << endl;
  forn(i,n) cout << v[i].x+e.x << " " << v[i].y+e.y << endl;
  ll ans=0;
  indexed_set vis;
  forn(i,n){
    vis.insert(v[i].id);
    ans+=int(vis.order_of_key(v[i].id));
  }
  DBG(ans);
  RAYA;
  return ans;
}

int main() {
  FIN;
  punto s, e;
  cin >> s.x >> s.y >> e.x >> e.y;
  if(e<s) swap(e,s);
  vector <punto> pos, neg;
  int n; cin >> n;
  ll izq=0, der=0;
  forn(i,n){
    punto a;
    cin >> a.x >> a.y;
    if(((a-s)^(e-s))>0) pos.pb(a);
    else if(((a-s)^(e-s))<0) neg.pb(a);
    else if(a<s) izq++;
    else der++;
  }
  ll ans=der*(der-1)/2+izq*(izq-1)/2;
  ans+=solve2(s,e,pos);
  s={-s.x,-s.y};
  e={-e.x,-e.y};
  swap(s,e);
  forn(i,SZ(neg)) neg[i]={-neg[i].x,-neg[i].y};
  ans+=solve1(s,e,neg);
  cout << ans << "\n";
  return 0; 
}
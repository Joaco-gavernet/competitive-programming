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
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)

typedef long double ld;
typedef ll tipo;

struct punto {
  tipo x, y, id=-1;
  punto const operator + (const punto &p) const { return {x+p.x, y +p.y}; }
  punto const operator - (const punto &p) const { return {x-p.x, y -p.y}; }
  tipo operator ^ (const punto &p) const { return x*p.y - y*p.x; }
  bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; }
  tipo mod() { return x*x + y*y; }
  ld mod2() { return sqrtl(x*x + y*y); }
};

//const ld EPS = 1e-10;
ii callipers(vector<punto> p, int n) {
  ii r={p[0].id,p[1].id};
  punto ans=p[1]-p[0];
  for (int i = 0, j = n < 2 ? 0 : 1; i < j; ++i) {
    for(;;j = (j + 1) %n) {
      punto aux = p[i] - p[j];
      if(ans.mod()<aux.mod()){
        ans=aux;
        r={p[i].id,p[j].id};
      }
      ll auxi = (p[(i+1)%n]-p[i])^(p[(j+1)%n]-p[j]);
      if (auxi <= 0) break;
    }
  }
  return r;
}

void convex_hull(vector<punto> &a) {
  if (SZ(a) == 1) return;
  sort(all(a));
  punto p1 = a[0];
  vector<punto> up, down;
  up.pb(p1); down.pb(p1);
  forr(i,1,SZ(a)) {
    int n = SZ(up), m = SZ(down);
    while (n > 1 and ((up[n-1]-up[n-2])^(a[i]-up[n-1])) >= 0) {
      up.pop_back(); n--;
    } up.pb(a[i]);
    while (m > 1 and ((down[m-1]-down[m-2])^(a[i]-down[m-1])) <= 0) {
      down.pop_back(); m--;
    } down.pb(a[i]);
  }
  a.clear(); 
  for(punto u: up) a.pb(u);
  for(int i = SZ(down) - 2; i > 0; i--) a.pb(down[i]);
}

int main() {
  FIN;
  int n; cin >> n;
  vector <punto> p(n);
  forn(i,n) {
    cin >> p[i].x >> p[i].y;
    p[i].id=i;
  }
  vector <punto> g=p;
  convex_hull(g);
  reverse(all(g));
  auto [s,e]=callipers(g,SZ(g));
  vector <ii> v(n);
  forn(i,n){
    punto aux=p[i]-p[s];
    v[i]={aux.mod(),i};
  }
  sort(all(v));
  ld ans=0;
  forn(i,n-1){
    punto aux=p[v[i].ss]-p[v[i+1].ss];
    ans+=aux.mod2();
  }
  cout << setprecision(10) << fixed << ans << "\n";
  return 0;
}
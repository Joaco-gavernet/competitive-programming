#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(c) int((c).size())

const double EPS = 1e-5;

struct DSU {
  vi link, sz;
  DSU (int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    forn(i,tam+5) link[i] = i, sz[i] = 1;
  }
  
  ll find(ll x) { return link[x] = (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }
  void join(ll a, ll b) {
    //~ cerr << a << " " << b << endl;
    a = find(a); b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
  }
};

typedef pair<double, double> pd;
#define fs first
#define ss second

double findDistance(const pd &a, const pd &b) {
  return (double)(b.fs-a.fs)*(b.fs-a.fs) + (double)(b.ss-a.ss)*(b.ss-a.ss); 
}


int main() {
  FIN; 
  
  int x,y; cin >> x >> y;
  int n; cin >> n;
  
  vector<pair<double,double>> v(n); 
  forn(i,n) cin >> v[i].first >> v[i].second;
  
  double l = 0, r = 1e6+5;
  forn(_,64) {
    double mid = (double)(r+l)/2.0; 
    //~ cerr << l << " " << mid << " " << r << endl;
    DSU ds(n+4);
    
    // build DSU with distance mid
    forn(i,n) {
      double dist;
      forr(j,i+1,n) {
	dist = findDistance(v[i], v[j]);
	//~ cerr << dist << endl;
	if (dist <= mid*mid*4) ds.join(i,j);
      }
      
      // contectar con los limites
      auto [xi, yi] = v[i];
      dist = findDistance(v[i], {0,yi});
      if (dist <= mid*mid) ds.join(i, n);
      dist = findDistance(v[i], {x,yi});
      if (dist <= mid*mid) ds.join(i, n+1);
      dist = findDistance(v[i], {xi,0});
      if (dist <= mid*mid) ds.join(i, n+2);
      dist = findDistance(v[i], {xi,y});
      if (dist <= mid*mid) ds.join(i, n+3);
    }
    
    // chequeo si existe camino
    if (ds.same(n, n+1) or ds.same(n+2, n+3) or ds.same(n, n+2) or ds.same(n+1, n+3)) r = mid;
    else l = mid;
  }

  cout << fixed << setprecision(8);
  cout << l << endl;
  
  return 0;
}




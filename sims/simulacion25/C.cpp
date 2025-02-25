#include <bits/stdc++.h>
using namespace std; 

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef vector<long double> vd;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n" 
#define esta(v,x) (v.find(x) != v.end())

const long double EPS = 1e-6; 

struct estrella {
  ll a, b, ant_a, ant_b; 
  long double dist; 
  estrella() {}
  estrella(ll _a, ll _b, ll _ant_a, ll _ant_b, long double _dist) {
    if (_ant_a < _ant_b) {
      a = _a; b = _b; 
      ant_a = _ant_a; ant_b = _ant_b; 
      dist = _dist;
    } else {
      a = _b; b = _a; 
      ant_a = _ant_b; ant_b = _ant_a; 
      dist = _dist;
    }
  }
  bool operator < (const estrella &x) const {
    if (dist < x.dist -EPS) return true; 
    else if (abs(dist -x.dist) <= EPS) {
      return (ant_a == x.ant_a ? ant_b < x.ant_b : ant_a < x.ant_a); 
    }
    return false; 
  }
}; 

ostream &operator << (ostream &os, const estrella &x) {
  return os << '(' << x.a << ',' << x.b << ',' << x.ant_a << ',' << x.ant_b << ',' << x.dist << ')'; 
}


int main() {
  FIN; 

  int n; cin >> n; 
  vector<ii> v(n); 
  vi antig(n); 
  forn(i,n) {
    cin >> v[i].first >> v[i].second; 
    antig[i] = i; 
  }

  unordered_set<int> sigue; 
  forn(i,n) sigue.insert(i); 

  vi tam(n, 1); 
  set<estrella> dists; 
  vector<vd> _dist(n, vd(n,0)); 
  forn(i,n) forr(j,i+1,n) {
    auto [x, y] = v[i]; 
    auto [xx, yy] = v[j]; 
    double aux = (x-xx)*(x-xx) + (y-yy)*(y-yy);
    dists.insert({i,j,antig[i],antig[j],aux}); 
    _dist[i][j] = _dist[j][i] = aux; 
  }

  ll next = n; 
  while (SZ(sigue) > 1) {
    // dbg(dists); 
    estrella act = *dists.begin(); 

    // update distancias
    int a = act.a, b = act.b; 
    sigue.erase(b); 
    dists.erase(act); 
    for (auto j : sigue) {
      if (j == a) continue; 

      estrella x0(j,a,antig[j],antig[a],_dist[a][j]); // = {_a,_j,antig[_a],antig[_j],_dist[_a][_j]};
      estrella x1(j,b,antig[j],antig[b],_dist[b][j]); // = {_b,_jj,antig[_b],antig[_jj],_dist[_b][_jj]};
      dists.erase(x0); 
      dists.erase(x1); 

      _dist[a][j] = _dist[j][a] = _dist[a][j]/tam[b] + _dist[b][j]/tam[a]; 
      estrella xx(j,a,antig[j],antig[a],_dist[a][j]); 
      dists.insert(xx); 
    }
    antig[a] = next++; 
    tam[a] += tam[b]; 

    // cerr << a << ' ' << b << endl; 
    cout << tam[a] << '\n'; 
    // RAYA; 
  }


  return 0;
}

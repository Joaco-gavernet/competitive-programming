#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl


typedef ll tipo;

struct punto {
  tipo x, y;
  punto const operator -(const punto &p) const { return {x -p.x, y -p.y}; } 
  punto const operator +(const punto &p) const { return {x +p.x, y +p.y}; } 
  tipo operator *(const punto &p) const { return x * p.x + y * p.y; } 
  __int128 operator ^(const punto &p) const { 
    __int128 xi = x, yi = y; 
    __int128 pxi = p.x, pyi = p.y; 
    __int128 ans = xi * pyi - yi * pxi;
    return ans; 
  }
  bool operator == (const punto &p) const {
    return x == p.x and y == p.y; 
  } 
  bool operator < (punto p) const { return x != p.x ? x < p.x : y < p.y; } 
  tipo arg() { return atan2(y,x); } 
  tipo mod() { return sqrtl(x * x + y * y); } 
  tipo mod2() { return x * x + y * y; } 
}; 


int main() {
  FIN; 
  
  int n; cin >> n; 
  vector<punto> v(n); 
  tipo xc = 0, yc = 0; 
  forn(i,n) {
    cin >> v[i].x >> v[i].y;
    xc += v[i].x;
    yc += v[i].y;
    v[i].x *= n;
    v[i].y *= n;
  }
  cerr << "centro " << xc << ' ' << yc << '\n'; 

  vector<punto> vecs(n); // vectores desde el centro (xc, yc)


  return 0; 
} 

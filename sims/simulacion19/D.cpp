#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << (c) << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << " "; cerr << endl
#define RAYA cerr << " ============================= " << endl
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;
const int MOD = -1;
const int MAXN = -1;

typedef long long ll; 
typedef long double tipo; 
double EPS = (double)(1e-10);

struct punto {
  tipo x,y;
  ll brightness=0;
  
  punto const operator - (const punto &p) const { return {x-p.x, y-p.y,brightness}; }
  punto const operator + (const punto &p) const { return {x+p.x, y+p.y,brightness}; }
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


int main() {
  FIN;
  int n; cin >> n;
  vector <punto> v(n);
  vector <ii> brillo(n);
  forn(i,n){
    int x,y,b;
    cin >> x >> y >> b;
    v[i]={x,y,b};
     brillo[i]={b,i};
  }
  sort(all(brillo));
  
  
  return 0;
}

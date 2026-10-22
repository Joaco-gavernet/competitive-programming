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
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second 


typedef ll tipo; //Cambiar a long long para operar en enteros
double EPS = (double)(1e-10);

struct punto { // Puede usarse para vectores
  tipo x, y;
  punto const operator -(const punto &p) const {return {x-p.x,y-p.y};}
  punto const operator +(const punto &p) const {return {x+p.x,y+p.y};}
  tipo operator *(const punto &p) const {return x*p.x + y*p.y;}
  tipo operator ^(const punto &p) const {return x*p.y - y*p.x;}
  bool operator == (const punto &p) const {
    return (abs(x-p.x) < EPS && abs(y-p.y) < EPS); // Para double
  }
  bool operator <(punto p) const {return x != p.x ? x < p.x : y < p.y;}
  tipo arg() {return atan2(y,x);} 
  tipo mod() {return sqrtl(x*x + y*y);}
  tipo mod2() {return x*x + y*y;}
};

punto operator*(tipo k, const punto &p) {return {k*p.x, k*p.y};}

ostream &operator << (ostream &os, const punto &p) { //Para imprimir
  return os << "(" << p.x << "," << p.y << ")";
}

istream &operator >> (istream &is, punto &p) { //Para leer
  return is >> p.x >> p.y;
}

struct frac { // Por si es necesario trabajar con enteros
  tipo n, d;
  ll mcd(ll a, ll b) {
    a = abs(a); b = abs(b);
    while(a > 0 && b > 0) {
      if(a >= b) a %= b;
      else b %= a;
    }
    return a == 0 ? b : a;
  }
  frac(ll x, ll y) {
    ll g = mcd(x,y);
    n = x/g; d = y/g;
    if(d < 0) d *= -1, n *= -1; 
  }
  frac() {}
  bool operator ==(frac &F) const {return n*F.d == d*F.n;}
  bool operator < (frac &F) const {return n*F.d  < d*F.n;}
};

int main(){  
  NaN;

  ll n; cin >> n; 
  vector<punto> p(n); forn(i,n) cin >> p[i]; 
  vector<punto> q = p; 

  ll best = 0; 
  forn(i,n) { // analizamos centrado en i 
    map<ii,ll> h; 
    auto [x, y] = p[i]; 
    forn(j,n) if (i != j) {
      auto [xj, yj] = p[j]; 
      if (x == xj) h[make_pair(-1, -1)]++;
      else {
        frac pend((y - yj), (x - xj)); 
        h[make_pair(pend.n, pend.d)]++; 
      } 
    } 

    ll mx = 0; 
    for (auto [k, x] : h) mx = max(mx, x); 
    best = max(best, mx + 1); 
  } 
  cout << best << '\n'; 

  return 0;
}

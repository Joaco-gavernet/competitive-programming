/*   AUTHOR: Estufa en Piloto   */
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
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

// Convex Hull Trick
// O(log n) para agregar linea y consultar
// Las linease agregan en orden creciente de pendiente
typedef long long tipo;
typedef __int128 ull;

struct punto {
  tipo x, y;
  punto operator -(const punto &p) const {return {x-p.x,y-p.y};}
  punto operator +(const punto &p) const {return {x+p.x,y+p.y};}
  tipo operator *(const punto &p) const {return x*p.x + y*p.y;}
  ull operator ^(const punto &p) const { // Producto Cruz
    return (ull)x * p.y - (ull)y * p.x; } // (ull) --> __int128
};

struct chull { // Agregar siempre pendientes en orden creciente
  ll op = 1; // 1 para minimo, -1 para maximo
  vector <punto> hull;

  chull(bool maxi) { // true para maximo, false para minimo
    if(maxi) op *= -1;
    // add_line(0,0); // Push base case {0,0} if necessary
  }
  ll get(tipo x) {
    punto query = {op * x,op * 1LL};
    int a=0, b=SZ(hull);
    while(b-a > 1) {
      int med = (a+b)/2;
      if(query * hull[med-1] >= query * hull[med]) a = med;
      else b = med;
    }
    return op * (query * hull[a]);
  }

  bool check(punto aux, int last) {
    return op * ((hull[last]-hull[last-1])^(aux-hull[last])) <= 0;
  }

  void add_line(ll x, ll y) {
    if(SZ(hull)) assert(x >= hull.back().x);  // Chequeo de pendientes crecientes

    punto aux = {x,y}; int last = SZ(hull)-1;
    while(last > 0 && check(aux,last)) {
      hull.pop_back(); last--;
    }
    hull.pb(aux);
  }
};


int main(){  
  FIN;

  int n; ll x;
  cin >> n >> x;
  vi s(n); forn(i,n) cin >> s[i];
  vi f(n); forn(i,n) cin >> f[i];

  vi dp(n);
  chull ctrick(false);
  ctrick.add_line(-x, 0);
  forr(j,0,n) {
    dp[j] = ctrick.get(-s[j]); 
    ctrick.add_line(-f[j], dp[j]); 
  }

  cout << dp[n-1] << endl;


  return 0;
}

#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

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
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


// Convex Hull trick dinamico.
// O(log n) para agregar e consultar.
// Para minimo, cambiar el signo de m y b.
typedef long double tc;
const tc is_query=-(1LL<<62); // special value for query
struct Line {
  tc m,b;
  mutable multiset<Line>::iterator it,end;
  const Line* succ(multiset<Line>::iterator it) const {
    return (++it==end? NULL : &*it);}
  bool operator<(const Line& rhs) const {
    if(rhs.b!=is_query)return m<rhs.m;
    const Line *s=succ(it);
    if(!s)return 0;
    return b-s->b<(s->m-m)*rhs.m;
  }
};
struct HullDynamic : public multiset<Line> { // for maximum
  bool bad(iterator y){
    iterator z=next(y);
    if(y==begin()){
      if(z==end())return false;
      return y->m==z->m&&y->b<=z->b;
    }
    iterator x=prev(y);
    if(z==end())return y->m==x->m&&y->b<=x->b;
    return (x->b-y->b)*(z->m-y->m)>=(y->b-z->b)*(y->m-x->m);
  }
  iterator next(iterator y){return ++y;}
  iterator prev(iterator y){return --y;}
  void add(tc m, tc b){
    // m *= -1; b *= -1; --> For minumum
    iterator y=insert((Line){m,b});
    y->it=y;y->end=end();
    if(bad(y)){erase(y);return;}
    while(next(y)!=end()&&bad(next(y)))erase(next(y));
    while(y!=begin()&&bad(prev(y)))erase(prev(y));
  }
  tc eval(tc x){
    Line l=*lower_bound((Line){x,is_query});
    return l.m*x+l.b; // -1*(l.m*x + l.b) for minimum
  }
};

const long double EPS = 1e-9; 
const int LOG = 20; 

int main(){
  FIN;

  int t; cin >> t; 
  vector<ii> point(t); forn(i,t) cin >> point[i].fst >> point[i].snd; 

  int p; cin >> p; 
  vector<ii> recta(p); forn(i,p) cin >> recta[i].fst >> recta[i].snd; 

  vector<ii> range_of_query(t, {-1, p}); 
  vector<vi> used(p+1), new_used(p+1); 
  vi v(t); iota(all(v), 0); 
  used[p/2] = v; 

  forn(_, LOG) {
    HullDynamic hd; 
    forr(i,0,p) {
      auto [pend, ord] = recta[i]; 
      hd.add(pend,ord); 
      if (SZ(used[i])) {
        for (auto u : used[i]) {
          auto [x,y] = point[u]; 
          auto [l,r] = range_of_query[u]; 
          if (hd.eval(x) > y) r = i; 
          else l = i +1; 
          range_of_query[u] = {l,r}; 
          int mid = (l+r) /2; 
          new_used[mid].pb(u); 
        }
      }
    }
    used = new_used;
    new_used.clear(); 
    new_used.resize(p+1); 
  }

  // reconstruir solucion
  vector<vi> chabon(p); 
  forn(i,t) {
    auto [l, r] = range_of_query[i]; 
    if (r < p) chabon[r].pb(i+1); 
  }

  // printear solucion
  forn(i,p) {
    cout << SZ(chabon[i]) << ' '; 
    for (auto u : chabon[i]) cout << u << ' ';
    cout << '\n'; 
  }


  return 0;
}

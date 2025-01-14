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
#define fs first
#define ss second
#define SZ(x) int((x).size()) 
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = 35;


bool cmp(ii &a, ii &b) {
  if (a.fs < b.fs) return true; 
  else if (a.fs > b.fs) return false; 
  else {
    if (a.ss >= b.ss) return true; 
    else return false; 
  } 
} 

struct tup {
  int l, r, id; 
}; 

int main(){
  FIN;

  int n, k; cin >> n >> k; 
  vector<ii> v(n); 
  vector<vector<ii>> sup(MAXN, vector<ii>()); // {r, id} de los segmentos que se agregan en cada l

  forn(i,n) {
    cin >> v[i].fs >> v[i].ss; 
    sup[v[i].fs].pb({v[i].ss, i}); 
    sup[v[i].ss +1].pb({-v[i].ss, i}); 
  }

  set<int> erased; 
  set<ii, greater<ii>> q; 

  forr(i,1,MAXN) {
    for (auto x : sup[i]) {
      if (esta(x.ss, erased)) continue; 
      if (x.fs < 0) q.erase({-x.fs, x.ss}); 
      else q.insert(x); 
    }

    if (SZ(q) > k) {
      while (SZ(q) > k) {
        auto [r, id] = *q.begin(); q.erase(q.begin()); 
        erased.insert(id); 
      } 
    } 
  }

  cout << SZ(erased) << '\n'; 
  for (auto x: erased) cout << x +1 << ' '; 


  return 0;
}

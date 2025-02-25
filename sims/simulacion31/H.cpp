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


struct tup {
  ll x, left, right; 
}; 

void update(vector<tup> &rond, int pos) {
  int nleft = rond[pos].left; 
  int nright = rond[pos].right;
  rond[nleft].right = nright; 
  rond[nright].left = nleft; 
  rond[pos].x = -1; 
}

int get_left(vector<tup> &rond, int pos, int k) {
  forn(_,k) pos = rond[pos].right; 
  return pos; 
}

int get_right(vector<tup> &rond, int pos, int k) {
  forn(_,k) pos = rond[pos].left; 
  return pos; 
}

int main(){
  FIN;

  int n, r, c; cin >> n >> r >> c; 
  vector<tup> rond(n); 
  forn(i,n) rond[i] = {i, (i-1 +n) %n, (i+1) %n}; 

  int tot = n; 
  vi hires; 
  int lft = 0, rgt = n-1; 
  while (tot > 2) {
    lft = get_left(rond, lft, r-1); 
    rgt = get_right(rond, rgt, c-1); 

    if (lft == rgt) hires.pb(lft), tot--; 
    else tot -= 2; 
    update(rond, lft);    
    if (lft != rgt) update(rond, rgt); 
    lft = rond[lft].right; 
    rgt = rond[rgt].left; 
  }
  for (auto [x,l,r] : rond) if (x != -1) hires.pb(x); 

  sort(all(hires)); 
  for (auto u: hires) cout << u +1 << ' '; 
  cout << '\n'; 

  return 0;
}

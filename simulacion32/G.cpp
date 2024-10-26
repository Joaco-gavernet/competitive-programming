#pragma GCC optimize("O3")
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
  int mx, even, odd; 
}; 

typedef tup tipo;
const tup NEUT = {0,0,0}; // REMINDER !!! 

struct segtree {
  vector<tup> t; int tam;

  tup op(tup a, tup b) {
    if (b.mx > a.mx) a.mx = b.mx; 
    a.even += b.even; 
    a.odd += b.odd; 
    return a;
  }
   
  void build(vector<tipo>v, int n) {  // build the tree 
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i, n) t[tam+i] = v[i];
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  tipo query(int l, int r) {  // op on interval [l, r]
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) res = op(res, t[l++]);
      if (!(r&1)) res = op(res, t[r--]);
    }
    return res;
  }
};


int main(){
  FIN;

  int n; cin >> n; 
  vector<tipo> v(n); 
  int x; 
  forn(i,n) cin >> x, v[i] = {x, !(x&1), x&1}; 

  segtree st; 
  st.build(v, n); 

  ll ans = 0; 

  // pruneo de casos bases
  forn(i,n) ans += !(v[i].mx&1); 
  if (n >= 3) {
    int even = 0; 
    int odd = 0; 
    if (!(v[0].mx&1)) even++; 
    else odd++; 
    if (!(v[1].mx&1)) even++; 
    else odd++; 

    forr(i,1,n-1) {
      if (v[i+1].mx %2 == 0) even++; 
      else odd++; 
      if (even > odd and v[i-1].mx < v[i].mx and v[i+1].mx < v[i].mx) ans++;
      if (v[i-1].mx %2 == 0) even--; 
      else odd--; 
    }
  }

  for (int l = 5; l <= n; l += 2) {
    forn(i,n-l+1) {
      int mid = i + l/2; 
      tup left = st.query(i, mid-1); 
      tup right = st.query(mid+1, mid +l/2);
      int even = left.even + right.even + !(v[mid].mx&1);
      int odd = left.odd + right.odd + (v[mid].mx&1);
      if (left.mx < v[mid].mx and right.mx < v[mid].mx and even > odd) ans++; 
      else if (even <= odd) i += (odd -even) /2; 
    }
  }

  cout << ans << '\n'; 
  return 0;
}

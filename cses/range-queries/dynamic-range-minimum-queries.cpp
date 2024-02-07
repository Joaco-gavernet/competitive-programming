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
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef ll tipo;
struct segtree {
  vector<tipo> t; int tam;
  tipo NEUT = INF;
  tipo op(tipo a, tipo b) {return min(a,b);}

  void build(vector<tipo> v, int n) {
    tam = sizeof(int) *8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam, NEUT); forn(i,n) t[tam+i] = v[i];
    for (int i = tam -1; i >0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void update(int p, int value) {
    for (t[p += tam] = value; p>1; p>>=1) t[p>>1] = op(t[p],t[p^1]);
  }

  tipo query(int l, int r) {
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l >>=1, r >>=1) {
      if (l&1) res = op(res,t[l++]);
      if (!(r&1)) res = op(res, t[r--]);
    }
    return res;
  }
};


int main(){
  FIN;

  int n,q; cin >> n >> q;
  vector<ll> v(n); forn(i,n) cin >> v[i];

  segtree s;
  s.build(v,n);

  while (q--) {
    int t; cin >> t;
    if (t == 1) {
      int k,u; cin >> k >> u;
      k--;
      s.update(k,u);
    } else {
      int l,r; cin >> l >> r;
      l--; r--;
      cout << s.query(l,r) << '\n';
    }
  }



  return 0;
}

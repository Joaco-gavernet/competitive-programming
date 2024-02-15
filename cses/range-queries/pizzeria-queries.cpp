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
const ll INF = (ll)(1LL<<60); // (1LL<<60)

typedef ll tipo;
struct segtree {
  int tam;
  tipo NEUT = INF;
  vector<tipo> t;
  tipo op(tipo a, tipo b) { return min(a,b); }

  void build(vector<tipo> v, int n) {
    tam = sizeof(int) *8 -__builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i,n) t[tam+i] = v[i];
    for(int i = tam-1; i >0; i--) t[i] = op(t[i<<1],t[i<<1|1]);
    dbg(t);
  }

  void update(int p, tipo value) {
    for (t[p += tam] = value; p > 1; p >>=1) t[p>>1] = op(t[p], t[p^1]);
    dbg(t);
  }

  tipo query(int l, int r) {
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) res = op(res,t[l++]);
      if (!(r&1)) res = op(res,t[r--]);
    }
    return res;
  }
};

int main() {
  FIN;
  
  int n,q; cin >> n >> q;
  vector<tipo> p(n), pd(n), pu(n); 
  forn(i,n) {
    cin >> p[i];
    pd[i] = p[i] -(i+1);
    pu[i] = p[i] +(i+1);
  }

  segtree down, up;
  down.build(pd,n);
  up.build(pu,n);

  int op;
  while (q--) {
    cin >> op;
    if (op == 1) {
      int k,x; cin >> k >> x;
      k--;
      down.update(k,x -(k+1));
      up.update(k,x +(k+1));
    } else {
      int p; cin >> p;
      p--;
      cout << min(down.query(0,p) +(p+1), up.query(p,n-1) -(p+1)) << '\n';
    }
  }


  return 0;
}

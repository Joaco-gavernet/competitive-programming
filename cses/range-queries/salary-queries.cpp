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
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


struct compresion {
  vector<int> todos;
  int top;
  compresion(vector<int> v) {
    todos = v; sort(all(todos));
    top = *(--end(todos));
    todos.erase(unique(all(todos)),todos.end());
    top = obtener(top);
  }
  int obtener(int x) {
    return (int)(lower_bound(all(todos),x)-todos.begin());
  }
};

typedef int tipo;

struct segtree {
  int tam;
  tipo NEUT = 0;
  vector<tipo> t;
  tipo op(tipo a, tipo b) { return a + b; }

  void build(vector<int> v, int n, int top) {
    tam = sizeof(int) *8 -__builtin_clz(top); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i,n) t[tam+v[i]]++;
    for (int i = tam-1; i>0; i--) t[i] = op(t[i<<1],t[i<<1|1]);
  }

  void update(tipo prev, tipo post) {
    prev += tam, post += tam;

    // first t[prev]-- and percolate update up
    for (t[prev]--; prev > 0; prev>>=1) t[prev>>1]--;

    // then t[post]++ and percolate update up 
    for (t[post]++; post > 0; post>>=1) t[post>>1]++;
  }

  tipo query(int l, int r) {
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l>>=1, r>>=1) {
      if (l&1) res = op(res,t[l++]);
      if (!(r&1)) res = op(res,t[r--]);
    }
    return res;
  }
};

// wrongly spelled haha
struct queri { char op; int a,b; };

#define f c.obtener

int main() {
  FIN;

  int n,k; cin >> n >> k;
  vector<int> v(n), todos(n);
  vector<queri> q(k);
  forn(i,n) cin >> v[i];

  todos = v; // copy initial array
  forn(i,k) {
    cin >> q[i].op >> q[i].a >> q[i].b; 
    if (q[i].op == '?') todos.pb(q[i].a); 
    else q[i].a--;
    todos.pb(q[i].b);
  }

  compresion c(todos);
  forn(i,n) v[i] = f(v[i]); // transform vector v 
  int top = c.top;
  
  segtree s;
  s.build(v,n,top);

  int idx, prev, post;
  forn(i,k) {
    switch(q[i].op) {
      case '!': // update salary of employee k to x
        idx = q[i].a;
        prev = v[idx];
        post = f(q[i].b);
        v[idx] = post;
        s.update(prev, post);
        break;
      case '?': // query employees within range of salary [a,b]
        cout << s.query(f(q[i].a), f(q[i].b)) << '\n';
        break;
    }
  }

  return 0;
}

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


struct tipo {
  ll g,l,r,s;
  tipo(): g(-INF), l(-INF), r(-INF), s(0) {}
  tipo(ll x): g(max(0ll,x)), l(max(0ll,x)), r(max(0ll,x)), s(x) {}
};

ostream &operator << (ostream &os, const tipo &p) {
  return os << "(" << p.g << "," << p.l << "," << p.r << "," << p.s << ")";
}

struct segtree {
  vector <tipo> t; int tam;
  tipo op(tipo a, tipo b){
    tipo ans;
    ans.g = max(max(a.g,b.g),a.r+b.l);
    ans.l = max(a.l,a.s+b.l);
    ans.r = max(a.r+b.s,b.r);
    ans.s = a.s + b.s;
    return ans;
  } // Operation to make

  void build(vector<tipo>v, int n) {  // build the tree 
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam); forn(i, n) t[tam+i] = tipo(v[i]);
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  void update(int p, tipo value) {  // set value at position p
    t[p += tam] = tipo(value);
    p >>= 1;
    for (; p > 0; p >>= 1) t[p] = op(t[p<<1], t[p<<1|1]);
  }
};

int main(){
  FIN;

  int n,q; cin >> n >> q;
  vector<tipo> v(n);

  int k; ll x;
  forn(i,n) {
    cin >> x;
    v[i] = tipo(x);
  }
  
  segtree s;
  s.build(v,n);

  while (q--) {
    cin >> k >> x;
    s.update(--k,x);
    cout << s.t[1].g << '\n';
  }

  return 0;
}

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


#define idx first // index of element (-1 if its more than one element) 
#define tot second // tot elements in segment

typedef pair<int,int> tipo;

struct segtree {
  int tam;
  tipo NEUT = {-1,0};
  vector<tipo> t;
  tipo op (tipo a, tipo b) { 
    tipo res = NEUT;
    res.tot = a.tot + b.tot;
    if (res.tot == 1) {
      if (a.tot == 1) res.idx = a.idx;
      else res.idx = b.idx;
    }
    if (b.idx != -1) res.idx = b.idx;
    else res.idx = a.idx;
    return res;
  }

  void build(int n) { // notice how we don't need the initial vector, only the respective index
    tam = sizeof(int) *8 -__builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i,n) t[tam+i] = {i,1};
    for (int i = tam-1; i > 0; i--) t[i] = op(t[i<<1],t[i<<1|1]);
  }

  void update(int id) {
    tipo res = NEUT;
    for (id += tam; id > 0; id>>=1) {
      if (id >= tam) {
        if (t[id].tot == 1) t[id] = NEUT;
        else t[id].tot--;
      } else t[id] = op(t[id<<1],t[id<<1|1]); 
    }
    // update percolating up with op ??? 
  }

  tipo query(int p) {
    int i = 1;
    while (i < 2*tam) {
      if (p == t[i].tot) break;
      if (p <= t[i<<1].tot) i <<= 1;
      else p -= t[i<<1].tot, (i <<=1)|=1;
    }

    tipo res = t[i];
    update(t[i].idx);
    return res;
  }
};

int main(){
  FIN;

  // Solution: use segtree to store amount of elements for range [l,r] and traverse it down

  int n; cin >> n;
  vector<int> v(n); forn(i,n) cin >> v[i];
  vector<int> q(n); forn(i,n) cin >> q[i];

  segtree s;
  s.build(n);

  forn(i,n) {
    auto ans = s.query(q[i]);
    cout << v[ans.idx] << ' ';
  }
  cout << '\n';



  return 0;
}

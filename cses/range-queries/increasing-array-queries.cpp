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


typedef long long tipo;
struct segtree {
  vector <tipo> t, v; int tam;
  vector<int> rep;
  tipo NEUT = 0; // Neutral element of operation
  tipo op(int l, int r){ // rethink how to make operations ????? 
    // take rightest from left subtree
    // take leftist from right subtree
    int lmr = l, rml = r; 
    while (lmr < tam) lmr <<=1, rml <<=1;
    lmr += (r-l)/2;
    lmr -= tam; rml -= tam;
    dbg(lmr, rml);

    // if v[lmr] > v[rml], then dif = v[lmr] - v[rml]
    int dif = 0;
    if (lmr < v.size() and rml < v.size()) {
      if (v[lmr] > v[rml]) dif = v[lmr] - v[rml];
    }
    dbg(dif);

    // propagate dif according to the range represented in [l,r] (r-l/2 elements)
    return (t[l] + t[r] + dif*(r-l)/2);
  }

  void build(vector<tipo> &_v, int n) {  // build the tree 
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    v = _v; t.resize(2*tam,NEUT); 
    rep.resize(2*tam); // check ????
    for(int i = tam - 1; i > 0; i--) t[i] = op(i<<1, i<<1|1);
    dbg(t);
  }

  // check op parameters ???
  tipo query(int l, int r) {  // op on interval [l, r]
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) l++;
      if (!(r&1)) r--;
    }
    res = op(l<<1, l<<1|1);
    return res;
  }
};


int main(){
  FIN;

  int n,q; cin >> n >> q;
  vector<tipo> v(n); forn(i,n) cin >> v[i];

  segtree s;
  s.build(v,n);

  while (q--) {
    int a,b; cin >> a >> b;
    cout << s.query(--a, --b) << '\n';
  }



  return 0;
}

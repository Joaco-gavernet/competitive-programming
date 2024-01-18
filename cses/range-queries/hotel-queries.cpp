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

struct tipo {
  int value;
  int index;
};

struct segtree { 
  vector <tipo> t; int tam;
  tipo NEUT = {-INF,-1}; // Neutral element of operation
  tipo op(tipo a, tipo b){ return (a.value >= b.value) ? a : b; } // Operation to make
   
  void build(vector<tipo>v, int n) { // for vertex v, left child in 2*v and right child in 2*v+1
    // root en 1, ojas en el intervalo [tam, 2*tam-1]
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i, n) t[tam+i] = v[i];
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }

  int query(int v, int l, int r, int num) {  // op on interval [l, r]
    if (t[v].value < num) return 0;
    if (tam <= v) {
      t[v].value -= num;
      return t[v].index;
    }
    
    int mid = (l+r)/2; // binary search the appropiate index to return 
    int idx = -1;
    if (t[2*v].value >= num) idx = query(2*v,l,mid,num); // find idx in left subtree
    else idx = query(2*v+1,mid+1,r,num); // find idx in right subtree
    
    // update segtree while backtracking
    if (t[2*v].value >= t[2*v+1].value) t[v] = t[2*v]; 
    else t[v] = t[2*v+1];
    
    return idx;
  }
};

int main(){
  FIN;
  
  int n, m; cin >> n >> m;
  vector<tipo> h(n);
  forn(i,n) h[i].index = i+1, cin >> h[i].value;
  vector<ll> r(m);
  forn(i,m) cin >> r[i];

  segtree t;
  t.build(h,n);
  
  forn(i,m) cout << t.query(1,0,n-1,r[i]) << " ";
  
  return 0;
}







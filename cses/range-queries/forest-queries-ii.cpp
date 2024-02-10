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


typedef vector<int> vi;

struct st2d{ // 0 indexado, [l, r] 
  // PARA HACER BUILD HAY QUE HACER LOS N*N updates
  int n;
  vector<vi> st;
  ll NEUT=0; // NEUTRO DE LA OPERACION
  ll op(ll a, ll b){return a+b;} // OPERACION

  st2d(int _n): n(_n) { st.resize(2*n+5, vi(2*n+5, 0)); }

  void upd(int x, int y, ll v){
    st[x+n][y+n] = v;
    for(int j=y+n; j>1; j>>=1)
      st[x+n][j>>1] = op(st[x+n][j], st[x+n][j^1]);
    for(int i=x+n; i>1; i>>=1) 
      for(int j=y+n; j; j>>=1) 
        st[i>>1][j] = op(st[i][j], st[i^1][j]);
  }

  ll query(int x0, int x1, int y0, int y1){
    ll r=NEUT; x1++, y1++;
    for(int i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
      int t[4],q=0;
      if(i0&1)t[q++]=i0++;
      if(i1&1)t[q++]=--i1;
      forn(k,q) for(int j0=y0+n,j1=y1+n;j0<j1;j0>>=1,j1>>=1){
        if(j0&1)r=op(r,st[t[k]][j0++]);
        if(j1&1)r=op(r,st[t[k]][--j1]);
      }
    }
    return r;
  }
};

int shift(int y, int x, vector<string> &v) {
  if (v[y][x] == '*') {
    v[y][x] = '.';
    return 0;
  } else {
    v[y][x] = '*';
    return 1;
  }
}

int main(){
  FIN;

  int n,q; cin >> n >> q;
  vector<string> v(n); forn(i,n) cin >> v[i];

  // building 2D segtree 
  st2d s(n);
  forn(i,n) forn(j,n) if (v[i][j] == '*') s.upd(j,i,1);

  // answering queries online
  while (q--) {
    int op, yl, xl, yu, xu; cin >> op;
    switch(op) {
      case 1:
        cin >> yl >> xl;
        s.upd(xl,yl,shift(--yl,--xl,v)); 
        break;
      case 2:
        cin >> yl >> xl >> yu >> xu;
        cout << s.query(--xl,--xu,--yl,--yu) << '\n';
        break;
    }
  }


  return 0;
}

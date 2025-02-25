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
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
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

// DSU struct con path compression y union por size
// Complejidad: O(ack(n)) por operacion, donde ack(n) es la funcion inversa de Ackermann, casi O(1)
struct DSU {
    vi link, sz;

    DSU(int tam) {
        link.resize(tam+5), sz.resize(tam+5);
        forn(i, tam+5) link[i] = i, sz[i] = 1;
    }

    ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { return find(a) == find(b); }

    void join(ll a, ll b) {
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        link[b] = a;
    }
};

int main(){
  FIN;
  ll n, m; int k;
  cin >> m >> n >> k;
  vi x(k), y(k), s(k);
  forn(i,k) cin >> x[i] >> y[i] >> s[i];
  DSU d(k+2);
  forn(i,k){
    if(y[i]<=s[i] or m-x[i]<=s[i]) d.join(i,k+1);
    if(x[i]<=s[i] or n-y[i]<=s[i]) d.join(i,k);
    forn(j,k){
      ll t=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      ll p=(s[i]+s[j])*(s[i]+s[j]);
      if(t<=p) {
	d.join(i,j);
	//~ dbg(i,j);
      }
    
    }
  }
  if(d.same(k,k+1)) cout << "N\n";
  else cout << "S\n";  
  
  return 0;
}

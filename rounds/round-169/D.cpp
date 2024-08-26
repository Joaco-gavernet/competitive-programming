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
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define fs first
#define ss second
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

bool is(int x, string &s, map<char,int> &mp) {
  return (mp[s[0]] == x or mp[s[1]] == x);
}

void solve() {
  int n,q; cin >> n >> q;
  vector<string> v(n); forn(i,n) cin >> v[i];
  dbg(n,q);
  dbg(v);

  map<char,int> mp;
  mp['B'] = 0;
  mp['G'] = 1;
  mp['R'] = 2;
  mp['Y'] = 3;

  // precomputing 
  // rr[i][c] = "starting in node i and going right, nearest node that has c = B,G,R,Y "
  // ll[i][c] = "starting in node i and going left, nearest node that has c = B,G,R,Y "
  vector<vi> rr(n,vi(4,-1));
  vector<vi> ll(n,vi(4,-1));

  for (int i = 0; i < n; i++) {
    int z0 = -1, z1 = -1;
    for (int k = 0; k < 4; k++) {
      if (is(k,v[i],mp) == false) {
        if (z0 == -1) z0 = k;
        else z1 = k;
      }
    }

    // check right
    int cont = 2;
    for (int j = i+1; j < n; j++) {
      int v0 = mp[v[i][0]];
      int v1 = mp[v[i][1]];
      if (rr[i][z0] == -1 and (is(v0,v[j],mp) or is(v1,v[j],mp)) and is(z0,v[j],mp)) 
        cont--, rr[i][z0] = j;
      if (rr[i][z1] == -1 and (is(v0,v[j],mp) or is(v1,v[j],mp)) and is(z1,v[j],mp)) 
        cont--, rr[i][z1] = j;
      
      if (cont == 0) break;
    }

    // check left
    cont = 2;
    for (int j = i-1; j >= 0; j--) {
      int v0 = mp[v[i][0]];
      int v1 = mp[v[i][1]];
      if (ll[i][z0] == -1 and (is(v0,v[j],mp) or is(v1,v[j],mp)) and is(z0,v[j],mp)) 
        cont--, ll[i][z0] = j;
      if (ll[i][z1] == -1 and (is(v0,v[j],mp) or is(v1,v[j],mp)) and is(z1,v[j],mp)) 
        cont--, ll[i][z1] = j;
    }
  }
  dbg(rr);
  dbg(ll);

  // answer queries
  while (q--) {
    int x,z; cin >> x >> z;
    --x; --z;
    if (x > z) swap(x,z);

    int x0 = mp[v[x][0]];
    int x1 = mp[v[x][1]];
    int z0 = mp[v[z][0]];
    int z1 = mp[v[z][1]];

    int aux = -1;
    if (x == z or is(x0,v[z],mp) or is(x1,v[z],mp)) {
      // if direct is possible
      cout << z-x << endl;
    } else { 
      // else solve with intermidates, going from x -> z for convinience
      int ans = INF;

      // check going right
      aux = rr[x][z0];
      if (aux != -1) ans = abs(aux-x) + abs(z-aux);
      aux = rr[x][z1];
      if (aux != -1) ans = min(ans, abs(aux-x) + abs(z-aux));

      // check going left 
      aux = ll[x][z0];
      if (aux != -1) ans = min(ans, abs(x-aux) + abs(z-aux));
      aux = ll[x][z1];
      if (aux != -1) ans = min(ans, abs(x-aux) + abs(z-aux));

      cout << (ans == INF ? -1 : ans) << endl;
    }
  }
}

int main(){
  FIN;
  int t = 1; cin >> t;
  while (t--) solve();
  return 0;
} 

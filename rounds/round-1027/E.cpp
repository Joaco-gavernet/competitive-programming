#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

void dfs(int v, vector<vi> &g, vi &a, ll par = 0, ll impar = 0, int step = 0, int prev = -1) {
    ll ans = 0;

    if (step == 0) {
        par += a[v]; 
        if (par -impar < 0) par = impar = 0;
        ans = par -impar; 
    } else {
        impar += a[v]; 
    }

    if (step == 0) 
    for (auto u: g[v]) if (u != prev) {
    }
    cout << ans << ' '; 
}

void solve() {
    int n; cin >> n;
    vi a(n); forn(i,n) cin >> a[i]; 
    vector<vi> g(n); 
    forn(_, n-1) {
        int a, b; cin >> a >> b; 
        g[--a].pb(--b); 
        g[b].pb(a); 
    }
    dfs(0, g, a); 
    cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

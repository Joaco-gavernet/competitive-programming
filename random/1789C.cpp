#include <bits/stdc++.h>
using namespace std;

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
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


const ll INF = 1LL<<60; 

void solve() {
  ll n, m; cin >> n >> m; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi on(n + m + 1, INF); 
  forn(i,n) on[a[i]] = 0; 

  vi c(n + m + 1); 
  forn(j,m) {
    ll p, v; cin >> p >> v; p--; 

    // close old
    c[a[p]] += j - on[a[p]] + 1; 
    on[a[p]] = INF; 

    // open new 
    on[v] = j + 1; 
    a[p] = v; 
  } 

  forn(i,n) c[a[i]] += max(0ll, m + 1 - on[a[i]]); 

  ll tot = 0; 
  forn(x,n + m + 1) tot += m * (m + 1) / 2 - (m - c[x]) * (m - c[x] + 1) / 2; 
  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

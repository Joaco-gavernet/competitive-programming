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
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

const int MAXN = 2e5+5;
vector<vi> facts(MAXN);
void build_factors(ll n = MAXN) {
  for (int p = 2; p <= n; p++) {
    if (SZ(facts[p])) continue; 
    for (int j = p; j <= n; j += p) facts[j].pb(p); 
  } 
}

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi b(n); forn(i,n) cin >> b[i]; 

  ll ok = 2; 
  map<int,int> cnt; 
  forn(i,n) {
    for (auto x: facts[a[i]]) {
      if (cnt[x] > 0) ok = 0; 
      cnt[x]++; 
    }
  } 

  forn(i,n) {
    for (auto x: facts[a[i]]) cnt[x]--; 
    for (auto x: facts[a[i]+1]) if (cnt[x] > 0) ok = min(ok, 1LL); 
    for (auto x: facts[a[i]]) cnt[x]++; 
  } 

  cout << ok << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  build_factors(); 
  cin >> t;
  while (t--) solve();
  return 0;
}

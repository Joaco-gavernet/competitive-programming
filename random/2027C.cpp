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


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds; 

const uint64_t SEED = (uint64_t)new char ^ 133713371337ULL; 
struct chash { size_t operator()(uint64_t x) const { return x ^ SEED; } };

gp_hash_table<int, int, chash> pbds_map; 


void solve() {
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  cc_hash_table<ll, vi, chash> g; 
  forn(i,n) g[a[i] + i].pb(a[i] + i + i); 

  ll mx = 0; 
  cc_hash_table<ll, bool, chash> seen; 
  function<void(ll)> run = [&](ll x) -> void {
    seen[x] = true; 
    mx = max(mx, x); 
    for (auto u : g[x]) if (seen[u] == false) run(u); 
  }; 

  run(n); 
  cout << mx << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

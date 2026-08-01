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


void solve() {
  int n, q; cin >> n >> q; 
  string s, t; cin >> s >> t; 

  vi apref(n + 1), bpref(n + 1); 
  forn(i,n) apref[i + 1] = apref[i] + (s[i] == '1'); 
  forn(i,n) bpref[i + 1] = bpref[i] + (t[i] == '1'); 

  vi lapref(n + 1), lbpref(n + 1); 
  forn(i,n) lapref[i + 1] = lapref[i] + (s[i] != t[i] and s[i] == '1'); 
  forn(i,n) lbpref[i + 1] = lbpref[i] + (s[i] != t[i] and t[i] == '1'); 

  forn(i,q) {
    int l, r; cin >> l >> r; 
    ll ca = apref[r] - apref[l - 1]; 
    ll cb = bpref[r] - bpref[l - 1]; 
    ll lca = lapref[r] - lapref[l - 1]; 
    ll lcb = lbpref[r] - lbpref[l - 1]; 
    if (ca > cb) swap(ca, cb), swap(lca, lcb); 
    assert(lca <= lcb); 
    assert(ca <= cb); 
    ca -= lca; 
    cb -= lca; 
    if (cb <= 2 * ca) cout << "YES\n";
    else cout << "NO\n"; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

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


void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi stk; 
  set<ll> root; 
  vi out(n); 
  vector<vi> g(n); 
  ll acc = 0, sum = 0;
  forn(i,n) {
    auto x = a[i]; 
    if (SZ(stk) and a[stk.back()] + 1 == x) g[stk.back()].pb(i), stk.pb(i); 
    else {
      while (SZ(stk) and a[stk.back()] + 1 != x) {
        auto r = stk.back(); 
        out[r] = i; 
        if (SZ(stk) == 1) acc += (out[r] - r) * SZ(root), sum += out[r] - r; 
        stk.pop_back(); 
      }
      if (SZ(stk) == 0) root.insert(i); 
      else g[stk.back()].pb(i); 
      stk.pb(i); 
    }
  } 
  while (SZ(stk)) {
    auto r = stk.back(); 
    out[r] = n; 
    if (SZ(stk) == 1) acc += (out[r] - r) * SZ(root), sum += out[r] - r; 
    stk.pop_back(); 
  }

  ll tot = 0; 
  while (SZ(root)) {
    tot += acc;
    auto i = *root.begin();
    root.erase(root.begin()); 

    // erase old root and update to new ones 
    if (SZ(g[i]) == 0) acc -= sum;
    else if (SZ(g[i]) == 1) acc--; 
    else {
      acc -= n - i;
      acc += SZ(g[i]) * (n - out[i]);
    }
    sum--; 
    ll rs = 1, acci = 0;
    for (auto j: g[i]) {
      if (SZ(g[i]) > 1) acci += rs * (out[j] - j); 
      rs++; 
      root.insert(j); 
    } 
    acc += acci; 
  } 

  cout << tot << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

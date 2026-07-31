#include <bits/stdc++.h> 
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"


ll prefil(int x, vector<vi>& g, vi& toleaf) {
  if (SZ(g[x]) == 0) return toleaf[x] = 0LL; 
  for (auto y : g[x]) {
    prefil(y, g, toleaf); 
    toleaf[x] = min(toleaf[x], toleaf[y] + 1); 
  }
  return toleaf[x];
} 

int main() {
    FIN;

    int n, k; cin >> n >> k;
    vector<vi> g(n);
    forn(i,n-1){
        int p; cin >> p; p--;
        g[p].pb(i+1);
    }

    vi toleaf(n, 1LL<<60); 
    prefil(0, g, toleaf); 


    vi path, jmp(n); 
    function<void(ll)> f = [&](ll x) {
      path.pb(x); 
      int nxt = min((ll)SZ(path) - 1, max(0LL, SZ(path) - k - 1 + toleaf[x])); 
      jmp[x] = path[nxt];
      for (auto y : g[x]) f(y); 
      path.pop_back(); 
    }; 
    f(0); 

    forn(i,n) forn(_,60) jmp[i] = jmp[jmp[i]]; 

    vi dp(n); 
    function<ll(ll)> calc = [&](ll x) {
      ll best = 0;
      if (SZ(g[x]) == 0) dp[jmp[x]]++; 
      for (auto y : g[x]) {
        best = max(best, calc(y)); 
      } 
      dp[x] += best;
      return dp[x]; 
    }; 
    calc(0); 

    cout << dp[0] << "\n";
    return 0;
}

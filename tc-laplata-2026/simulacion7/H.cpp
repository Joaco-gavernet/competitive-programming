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

struct evt {
  int op;
  string name; 
};


ll f(ll on, vi& adj, map<ll,ll>& memo) {
  if (on == 0) return 0;
  if (memo.count(on)) return memo[on];
  int id = 63 - __builtin_clzll(on); 
  ll without_id = on & ~(1LL << id);
  ll a = f(without_id & ~adj[id], adj, memo) + 1; // taking id 
  ll b = f(without_id, adj, memo); // not taking id
  return memo[on] = max(a, b); 
};  

int main() {
  FIN;

  int n, m; cin >> n >> m;

  vector<evt> v(n);
  forn(i,n) {
    int op; cin >> op;
    string s = "#"; 
    if (op == 2) cin >> s;
    v[i] = {op, s};
  }

  reverse(all(v)); 
  vi comp; 
  map<string, ll> mp; 
  vector<vi> g(n); 
  vi adj(m); 
  for (auto [op, name]: v) {
    if (op == 2) {
      if (mp.count(name) == 0) mp[name] = SZ(mp); 
      comp.pb(mp[name]); 
    } else {
      sort(all(comp)); 
      comp.erase(unique(all(comp)), end(comp)); 
      forn(i, SZ(comp) - 1) {
        forr(j, i + 1, SZ(comp)) {
          int a = comp[i]; 
          int b = comp[j]; 
          adj[a] |= (1LL<<b); 
          adj[b] |= (1LL<<a); 
        } 
      } 
      comp.clear(); 
    }
  }

  map<ll, ll> memo; 
  memo[0] = 0; 
  ll on = (1LL<<m) - 1; 
  ll best = f(on, adj, memo); 

  cout << best << '\n'; 


  return 0;
}

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
  int n; cin >> n;
  string a, b; cin >> a >> b;

  // check invariants 
  // 1) same amount of leaves.  
  auto f = [](string s) -> ll {
    ll tot = 0; 
    forn(i,SZ(s) - 1) if (s[i] == '(' and s[i+1] == ')') tot++; 
    return tot; 
  }; 

  // 2) same amount of nodes in path to first branch. 
  auto g = [](string s) -> ll {
    const int n = SZ(s); 
    vi match(n, -1), stk; 

    forn(i,n) {
      auto c = s[i]; 
      if (c == '(') stk.pb(i); 
      else {
        match[i] = stk.back();
        match[stk.back()] = i; 
        stk.pop_back(); 
      } 
    } 

    ll i = 0;
    while (i < n /2 and match[i] == n - i - 1 and match[n - i - 1] == i) i++; 
    return i; 
  }; 

  if (f(a) == f(b) and g(a) == g(b)) cout << "YES\n"; 
  else cout << "NO\n"; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

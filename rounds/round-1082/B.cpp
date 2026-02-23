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
  string s; cin >> s; 

  vb dp = {true, false}; 
  forr(k,1,n+1) {
    vb ndp = {false, false}; 
    forn(p,2) if (dp[p]) {
      char left = (p == 0 ? 'a' : 'b'); 
      int ri = (n + (k - 1) + p) & 1;
      char right = (ri ? 'a' : 'b'); 

      auto ok = [&](char c) {
        return s[k-1] == '?' or s[k-1] == c; 
      };  

      if (ok(left)) ndp[p ^ 1] = true; 
      if (ok(right)) ndp[p] = true; 
    } 
    dp[0] = ndp[0]; 
    dp[1] = ndp[1]; 
  } 
  cout << (dp[0] or dp[1] ? "YES" : "NO") << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

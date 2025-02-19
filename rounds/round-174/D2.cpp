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


int check(int l, string s, int balanced, vi c) {
  int b = balanced; 
  const int n = SZ(s); 
  int r = l; 
  for (; r < n and (b or (r < n/2 and s[r] != s[n-1-r])); r++) {
    if (r < n/2 and c[s[r] -'a'] > 0) c[s[r] -'a'] -= 2, b--;
    else if (r >= n/2 and c[s[r] -'a'] < 0) c[s[r] -'a'] += 2, b--;
  }
  if (balanced) r = max(r, n/2 +balanced/2); 
  return r -l; 
} 

void solve() {
  string s; cin >> s; 
  const int n = SZ(s); 

  // check if balanced string 
  vi c(30, 0); 
  forn(i,n/2) c[s[i] -'a']++; 
  forn(i,n/2) c[s[i +n/2] -'a']--; 
  int balanced = 0; 
  forn(i,30) if (c[i] != 0) c[i], balanced += abs(c[i])/2; 

  int i = 0; 
  for (;i < n and s[i] == s[n-1-i]; i++) {} 
  int ans = check(i, s, balanced, c); 
  reverse(all(s)); 
  for(auto &x: c) x *= -1;
  ans = min(ans, check(i, s, balanced, c)); 
  cout << ans << '\n'; 
} 


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

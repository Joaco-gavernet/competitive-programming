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


void solve() {
  string p, s; cin >> p >> s; 
  const int n = SZ(p); 
  const int m = SZ(s); 

  int i = 0, j = 0; 
  vector<char> rest; 
  while (i < n and j < m) {
    if (p[i] == s[j]) {
      if (SZ(rest) and rest.back() != p[i]) rest.clear(); 
      rest.pb(p[i]); 
      i++, j++; 
    } else {
      while (SZ(rest) and s[j] == rest.back()) j++, rest.pop_back(); 
      if (p[i] == s[j]) {
        if (SZ(rest) and rest.back() != p[i]) rest.clear(); 
        rest.pb(p[i]); 
        i++, j++; 
      } else break; 
    } 
  } 

  while (j < m and SZ(rest) and s[j] == rest.back()) rest.pop_back(), j++; 

  if (i == n and j == m) cout << "YES\n"; 
  else cout << "NO\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

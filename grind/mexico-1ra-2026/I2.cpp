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
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()



int main(){  
  NaN;

  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  string s; cin >> s; 

  ll x = 1; 
  vi ans = {x}; 
  forn(i,n-1) {
    char c = s[i]; 
    if (c == '=') ans.pb(x);
    else if (c == '>') ans.pb(--x);
    else if (c == '<') ans.pb(++x); 
    else assert(false); 
  } 
  ll mn = *min_element(all(ans)); 

  forn(i,n) if (mn <= 0) ans[i] += abs(mn) + 1; 

  dbg(ans); 
  if (s[0] == '<') ans[0] = 1; 
  if (s[n - 2] == '>') ans[n - 1] = 1; 
  int i = 1;
  while (i < n - 1 and (s[i] == '<' or s[i] == '=')) ans[i] = ans[i - 1] + (s[i] == '<'), i++; 
  i = n - 2; 
  while (i >= 0 and (s[i] == '>' or s[i] == '=')) ans[i] = ans[i + 1] + (s[i] == '>'), i--; 
  dbg(ans); 

  ll tot = 0; 
  forn(i,n) tot += a[i] * ans[i]; 

  cout << tot << '\n'; 
  for (auto x : ans) cout << x << ' ';
  cout << '\n'; 
  
  return 0;
}

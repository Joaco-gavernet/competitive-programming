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


void fix(int p, vi& b, string& s) {
  const int n = SZ(b); 
  int i = p + 1; 
  while (i < n and (s[i - 1] == '<' or s[i - 1] == '=') and b[i] == -1) b[i] = b[i - 1] + (s[i - 1] == '<'), i++; 

  i = p - 1; 
  while (i >= 0 and (s[i] == '>' or s[i] == '=') and b[i] == -1) b[i] = b[i + 1] + (s[i] == '>'), i--; 
} 

int main(){  
  NaN;

  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  string s; cin >> s; 

  ll x = 1; 
  vector<ii> v = {{x, 0}}; 
  forn(i,n-1) {
    char c = s[i]; 
    if (c == '=') v.pb({x, i + 1});
    else if (c == '>') v.pb({--x, i + 1});
    else if (c == '<') v.pb({++x, i + 1}); 
    else assert(false); 
  } 
  sort(all(v)); 
  reverse(all(v)); 
  vi b(n, -1); 
  while (SZ(v)) {
    auto [x, p] = v.back(); v.pop_back(); 
    if (b[p] > -1) continue; 
    b[p] = 1; 
    fix(p, b, s); 
  } 

  ll tot = 0; 
  forn(i,n) tot += a[i] * b[i]; 

  cout << tot << '\n'; 
  for (auto x : b) cout << x << ' ';
  cout << '\n'; 
  
  return 0;
}

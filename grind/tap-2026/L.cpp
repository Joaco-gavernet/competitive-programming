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
  
  int n, m; cin >> n >> m; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi aux = a; 
  sort(all(aux)); 
  aux.erase(unique(all(aux)), aux.end()); 
  m = SZ(aux); 

  map<ll,ll> t; 
  forn(i,m) t[aux[i]] = i; 
  for (auto &x : a) x = t[x];

  // dp[inv][x] = "starting in x, best inc seq possible" 
  vector<vi> dp(2, vi(m)); 
  vi h(m); 
  for (int i = n - 1; i >= 0; i--) {
    dp[0][a[i]] = max(dp[0][a[i]], 1 + (a[i] + 1 < m ? dp[0][a[i] + 1] : 0)); 
  } 
  forn(i,n) dp[1][a[i]] = max(dp[1][a[i]], 1 + (a[i] + 1 < m ? dp[1][a[i] + 1] : 0)); 

  ll tot = 0, x = 0; 
  while (x < m) tot++, x += max(dp[0][x], dp[1][x]); 
  cout << m << ' ' << tot << '\n'; 
  
  return 0;
}

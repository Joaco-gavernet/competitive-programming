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


void solve() {
  ll n, k; cin >> n >> k; 
  if ((n + k - 1) / k > k) return void(cout << "IMPOSSIBLE\n"); 

  vector<vi> ans; 
  vi v; 
  forn(i,n) {
    if (SZ(v) < k) v.pb(i); 
    else {
      reverse(all(v)); 
      ans.pb(v); 
      v = {i}; 
    } 
  } 
  reverse(all(v)); 
  ans.pb(v); 

  for (auto v : ans) for (auto x : v) cout << x + 1 << ' '; 
  cout << '\n'; 
} 

int main(){  
  NaN;
  ll t; cin >> t; 
  while (t--) solve(); 
  return 0;
}

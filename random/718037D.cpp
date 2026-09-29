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


vi pi(const string &s) {
	int n = SZ(s);
	vi pi_s(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[j] != s[i]) { j = pi_s[j - 1]; }
		if (s[i] == s[j]) { j++; }
		pi_s[i] = j;
	}
	return pi_s;
}


int main(){  
  NaN;

  string s; cin >> s; 
  const ll n = SZ(s); 

  vi p = pi(s); 
  vi h(n + 1, 0); 
  for (auto x : p) h[x]++;

  // Every occurrence of a longer prefix contributes to its longest border.
  for (ll len = n; len > 0; len--) 
    h[p[len - 1]] += h[len];

  // Include each prefix's own occurrence starting at position 0.
  for (ll len = 1; len <= n; len++) h[len]++;

  vector<ii> ans = {{n, 1}}; 
  for (ll L = p[n - 1]; L > 0; L = p[L - 1]) 
    ans.pb({L, h[L]}); 

  reverse(all(ans)); 
  cout << SZ(ans) << '\n'; 
  for (auto [l, c] : ans) cout << l << ' ' << c << '\n'; 

  return 0;
}

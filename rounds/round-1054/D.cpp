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


const ll INF = 1LL<<60; 

ll check(string &s) {
  const int n = SZ(s); 
  vi pref(n), suf(n); 

  forr(i,1,n) {
    pref[i] = pref[i-1];
    if (s[i-1] == 'b') pref[i]++; 
  } 
  for (int i = n-2; i >= 0; i--) {
    suf[i] = suf[i+1];
    if (s[i+1] == 'b') suf[i]++; 
  } 
  ll ans = 0; 
  forn(i,n) if (s[i] == 'a') ans += min(pref[i], suf[i]); 

  return ans; 
} 

void solve() {
  int n; cin >> n; 
  string s; cin >> s; 

  // desplazo As
  ll best = check(s); 

  // desplazo Bs
  forn(i,n) s[i] = (s[i] == 'a' ? 'b' : 'a'); 
  best = min(best, check(s)); 

  cout << best << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

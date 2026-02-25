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

int f(ll x) {
  int sum = 0;
  while (x > 0) sum += x % 10, x /= 10; 
  return sum; 
} 

void solve() {
  string x; cin >> x; 
  const int n = SZ(x); 
  reverse(all(x)); 
  ll sum = x.back() - '0'; 
  x.pop_back(); 
  sort(all(x)); 
  reverse(all(x)); 
  string aux = x; 

  while (SZ(x) and sum + int(x.back() - '0') <= 9) sum += int(x.back() - '0'), x.pop_back(); 
  ll ans = SZ(x); 

  x = aux; 
  sum = 1; 
  ll ops = 1; 
  while (SZ(x) and sum + int(x.back() - '0') <= 9) sum += int(x.back() - '0'), x.pop_back(); 
  ans = min(ans, ops + SZ(x)); 

  cout << ans << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

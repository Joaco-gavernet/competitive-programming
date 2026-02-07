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


void upd(string &ans, ll &x, ll pos) {
  while (x > 0) {
    if (SZ(ans) < pos + 1) ans += '0' + x % 10, x /= 10; 
    else {
      int num = ans[pos] - '0'; 
      num += x % 10; 
      ans[pos] = '0' + (num % 10); 
      x /= 10; 
      x += num / 10; 
    } 
    pos++; 
  } 
} 

const int MAXN = 2e5+4; 

int solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi pref(MAXN); 
  forn(i,n) pref[a[i]]++; 
  for (int i = MAXN -1; i >= 0; i--) pref[i] += pref[i+1]; 

  string ans = "0"; 
  forr(i,1,MAXN) upd(ans, pref[i], i - 1); 

  reverse(all(ans)); 
  cout << ans << '\n'; 
  return 0;
}


int main(){
  FIN;
  int t = 1; 
  while (t--) solve();
  return 0;
}

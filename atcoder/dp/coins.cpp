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

typedef long double tipo;

int main(){  
  FIN;
  
  int n; cin >> n; 
  vector<tipo> p(n); forn(i,n) cin >> p[i]; 
  vector<vector<tipo>> dp((n+1)/2, vector<tipo>(n)); 

  tipo prev = 1.0; 
  forn(i,n) prev *= p[i], dp[0][i] = p[i]; 
  tipo sum = prev;
  forr(t,1,(n+1)/2) {
      tipo sum = 1.0;
      forn(i,n) {
          dp[t][i] = prev *((1.0 -p[i]) /p[i]);
          sum *= dp[t][i];
      }
      dbg(t, prev, sum); 
      prev = sum; 
  }

  forn(t,(n+1)/2) dbg(t, dp[t]); 

  forr(t,1,(n+1)/2) forn(i,n) sum += dp[t][i]; 
  cout << sum << '\n'; 

  return 0;
}

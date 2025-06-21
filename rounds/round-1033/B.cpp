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
#define x first
#define y second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

bool colin(ii a, ii b) {
  return (a.x * b.y - b.x * a.y) == 0;  
} 

void solve() {
  int n, s; cin >> n >> s; 
  vector<ii> d(n), p(n); 
  int px[] = {0, s, s, 0}; 
  int py[] = {0, 0, s, s}; 

  forn(i,n) cin >> d[i].x >> d[i].y >> p[i].x >> p[i].y; 

  int tot = 0;
  forn(i,n) {
    forn(j,4) {
      ii z = {px[j] -p[i].x, py[j] -p[i].y}; 
      if (colin(d[i], z)) {
        tot++; 
        break; 
      } 
    } 
  } 
  cout << tot << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

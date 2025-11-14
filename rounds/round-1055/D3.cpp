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


void solve() {
  int n, q; cin >> n >> q; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi typ(n); 

  vi pref[3]; 
  forn(i,3) pref[i].resize(n+1); 

  forn(i,n) {
    int  L = __lg(a[i]); 
    if ((1<<L) != a[i]) {
      if ((1<<L) +1 == a[i]) typ[i] = 1;
      else typ[i] = 2; 
    } 
    pref[0][i+1] = pref[0][i] +L; 
    pref[1][i+1] = pref[1][i] +(typ[i] == 1); 
    pref[2][i+1] = pref[2][i] +(typ[i] == 2); 
  } 

  forn(_,q) {
    int l, r; cin >> l >> r; 
    int sum, B, C; 
    sum = pref[0][r] -pref[0][l-1]; 
    B = pref[1][r] -pref[1][l-1]; 
    C = pref[2][r] -pref[2][l-1]; 
    cout << sum + B/2 + C << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

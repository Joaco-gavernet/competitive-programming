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
typedef vector<ii> vii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


bool sim(const int n, int k, const string &s, const vi &p, const int mid) {
  bool in = false; 
  forn(i,n) {
    if (s[i] == 'B') {
      if (in == false and p[i] > mid) {
        if (k == 0) return false; 
        k--; 
        in = true; 
      } 
    } else {
      if (in and p[i] > mid) in = false; 
    } 
  } 
  return true; 
} 

void solve() {
  int n, k; cin >> n >> k; 
  string s; cin >> s; 
  vi p(n); forn(i,n) cin >> p[i]; 

  int l = -1, r = 1e9+1; 
  while (l < r -1) {
    int mid = (l + r) /2; 
    if (sim(n, k, s, p, mid)) r = mid; 
    else l = mid; 
  } 
  cout << r << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

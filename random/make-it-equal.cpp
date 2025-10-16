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


int check(int x, int k) {
  int moda = x %k;
  if (moda >= (k+1)/2) moda = k-moda; 
  return moda; 
} 

void solve() {
  int n, k; cin >> n >> k;
  vi s(n), t(n);
  forn(i,n) cin >> s[i]; 
  forn(i,n) cin >> t[i]; 
  sort(all(s)); sort(all(t)); 

  map<int,int> ms, mt; 
  forn(i,n) {
    ms[check(s[i], k)]++; 
    mt[check(t[i], k)]++; 
  } 

  bool ok = true; 
  auto is = ms.begin(), it = mt.begin(); 
  for (; is != ms.end() and it != mt.end(); is++, it++) {
    if (is->ff != it->ff or is->ss != it->ss) ok = false;
  } 

  if (ok) cout << "YES\n"; 
  else cout << "NO\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

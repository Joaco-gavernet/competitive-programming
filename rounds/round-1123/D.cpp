#include <bits/stdc++.h>
using namespace std;

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
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


void solve() {
  ll n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  vector<vi> v(2); 
  forn(i,n) v[i&1].pb(a[i]); 
  forn(j,2) sort(all(v[j])); 
  forn(j,2) reverse(all(v[j])); 

  vi b; 
  forn(i,n) {
    b.pb(v[i&1].back()); 
    v[i&1].pop_back(); 
  } 

  dbg(a);
  dbg(b); 

  forn(i,n-1) {
    if (b[i] > b[i + 1]) {
      vi A, B; 
      for (int j = i + 1; j < n; j += 2) A.pb(b[j]); 
      for (int j = i + 2; j < n; j += 2) B.pb(b[j]); 
      dbg(A);
      dbg(B); 
      reverse(all(A)); 
      reverse(all(B)); 
      for (int j = i + 1, k = 0; j < n; j += 2, k++) b[j] = A[k]; 
      for (int j = i + 2, k = 0; j < n; j += 2, k++) b[j] = B[k]; 
      dbg(b); 

      for (int j = i + 1; j + 1 < n; j++) if (b[j] < b[j + 1]) return void(cout << "NO\n"); 
      break; 
    } 
  } 
  cout << "YES\n"; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

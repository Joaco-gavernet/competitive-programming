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

struct dmap : map<int,int> {
  auto erase(int x) -> void {
    if (--map<int,int>::at(x) == 0)
      map<int,int>::erase(x); 
  }
}; 

vi process(vi &a, int k) {
  const int n = SZ(a); 
  vi ans(n, -1); 
  dmap cont; 

  int l = 0, r = 0; 
  while (r < n) {
    while (r < n and SZ(cont) <= k) cont[a[r]]++, r++; 
    while (SZ(cont) > k) {
      ans[l] = r -1; 
      cont.erase(a[l++]); 
    }
  } 
  while (l < n and SZ(cont) == k) ans[l] = n, cont.erase(a[l++]); 
  return ans; 
} 

void solve() {
  int n, k, l, r; cin >> n >> k >> l >> r; l = max(l, k); 
  vi a(n); forn(i,n) cin >> a[i]; 

  ll tot = 0; 
  vi b = process(a, k-1); 
  vi c = process(a, k); 

  forn(i,n) {
    if (b[i] == -1) continue; 
    int mn = max(b[i], i +l-1); 
    int mx = min(c[i] -1, i +r-1); 
    tot += max(mx -mn +1, 0); 
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

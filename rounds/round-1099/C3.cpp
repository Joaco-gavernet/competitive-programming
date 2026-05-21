#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<int,int> ii;
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



int f(int a) {
  if (a == 1) return 0; 
  int ans = 0;
  if (a&1) ans = f(a + 1);
  else ans = f(a>>1); 
  return ans + 1;
} 
 
void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
 
  unordered_map<int,int> cnt; 
  priority_queue<ii> pq; 
  forn(i,n) {
    if (cnt[a[i]] == 0) pq.push({f(a[i]), a[i]}); 
    cnt[a[i]]++; 
  }
 
  ll steps = 0; 
  while (SZ(pq)) {
    auto [k, x] = pq.top(); pq.pop(); 
    int aux = cnt[x]; 
    if (aux == n or k == 1) break; 
 
    steps += aux; 
    cnt[x] = 0; 
    if (x & 1) x++; 
    else x /= 2; 
    k--; 
 
    if (cnt[x] == 0) pq.push({k, x}); 
    cnt[x] += aux; 
    pq.push({k, x}); 
  } 
 
  cout << steps + min(cnt[1], cnt[2]) << '\n';
}

int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

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

const ll INF = 1LL<<60; 

bool check(ll mid, vi &a, int n) {
  vb visto(n,false); 

  forr(i,0,n) {
    if (a[i] <= mid) visto[i] = true; 
    ll dist = abs(a[i] -a[i-1]);
    if (i > 0 and visto[i-1] and dist <= mid) visto[i] = true; 
  } 
  for (int i = n-1; i >= 0; i--) {
    if (a[i] <= mid) visto[i] = true; 
    ll dist = abs(a[i] -a[i+1]);
    if (i < n-1 and visto[i+1] and dist <= mid) visto[i] = true; 
  } 

  forn(i,n) if (visto[i] == false) return false;
  return true; 
} 

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  ll l = -1, r = INF; 
  while (l+1 < r) {
    ll mid = (l+r) /2; 
    if (check(mid, a, n)) r = mid; 
    else l = mid; 
  } 
  cout << r << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  forr(i,1,t+1) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

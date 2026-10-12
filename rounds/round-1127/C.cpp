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


bool f(ll n, ll lim, deque<ll>& a) {
  vi h(n + 1); 
  ll g = 1, id = 1; 
  while (SZ(a) < n) {
    if (h[g] + g > lim) g++; 
    while (SZ(a) + g > n and SZ(a)) a.pop_front();
    if (g > lim or SZ(a) + g > n) return false; 
    forn(_,g) a.pb(id); 
    h[g] += g; 
    id++; 
  } 
  return true; 
} 

void solve() {
  ll n; cin >> n; 
  ll l = 0, r = n + 1; 
  deque<ll> a; 
  while (l + 1 < r) {
    a.clear(); 
    ll mid = (l + r) / 2; 
    if (f(n, mid, a)) r = mid;
    else l = mid; 
  } 
  a.clear(); 
  f(n, r, a); 
  cout << r << '\n'; 
  for (auto x : a) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

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
  ll n, m, d; cin >> n >> m >> d; 
  vi s(m); forn(i,m) cin >> s[i]; 

  vi c(m), prev(m);
  prev[0] = 1;
  ll C = 1 + max(0ll, (n - s.back()) / d); 
  forn(i,m) {
    ll len = s[i] - prev[i] - 1; 
    c[i] += len / d + (s[i] > 1); 
    if (i + 1 < m) prev[i + 1] = s[i]; 
    C += c[i]; 
  } 

  ll best = 1ll<<60, h = 0; 
  forr(i, 1, m) {
    ll len = s[i] - prev[i - 1] - 1; 
    ll add = len / d + (s[i] > 1); 
    ll aux = C - c[i - 1] - c[i] + add; 
    if (aux < best) best = aux, h = 1; 
    else if (best == aux) h++; 
  } 

  // saco el ultimo 
  ll len = n - prev[m - 1]; 
  ll add = len / d; 
  ll aux = C - c[m - 1] - max(0ll, (n - s.back()) / d) + add; 
  if (aux < best) best = aux, h = 1; 
  else if (best == aux) h++; 

  cout << best << ' ' << h << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

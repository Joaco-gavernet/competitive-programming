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


const ll C = 30; 

void solve() {
  ll n; cin >> n; 
  string s; cin >> s; 

  vector<vi> op(n + 2, vi(C)), os(n + 2, vi(C)); 
  vector<vi> ep(n + 2, vi(C)), es(n + 2, vi(C)); 

  forr(i,1,n+2) {
    forn(j,C) ep[i][j] += ep[i - 1][j]; 
    forn(j,C) op[i][j] += op[i - 1][j]; 
    if (i <= n) {
      if (i % 2 == 0) ep[i][s[i - 1] - 'a']++; 
      else op[i][s[i - 1] - 'a']++; 
    } 
  } 
  for (int i = n; i >= 0; i--) {
    forn(j,C) es[i][j] += es[i + 1][j]; 
    forn(j,C) os[i][j] += os[i + 1][j]; 
    if (i >= 1) {
      if (i % 2 == 0) es[i][s[i - 1] - 'a']++; 
      else os[i][s[i - 1] - 'a']++; 
    } 
  } 

  ll tot = 0; 
  if (n % 2 == 1) {
    tot = 1ll<<60; 
    // find best delete possible 
    forr(i,1,n+1) {
      ll omx = 0, emx = 0; 
      forn(j,C) omx = max(omx, op[i - 1][j] + es[i + 1][j]); 
      forn(j,C) emx = max(emx, ep[i - 1][j] + os[i + 1][j]); 
      if ((n / 2 - omx) + (n / 2 - emx) + 1 < tot) tot = (n / 2 - omx) + (n / 2 - emx) + 1; 
    } 
  } else {
    tot = (n / 2 - *max_element(all(ep[n]))) + (n / 2 - *max_element(all(op[n]))); 
  } 
  cout << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

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


ll f(string s) {
  const int n = SZ(s); 

  ll worst = 0, i = 0;
  char prev = '0'; 
  while (i < n) {
    while (i < n and s[i] != '+') prev = s[i], i++; 
    ll acc = 0; 
    while (i < n and s[i] == '+') acc++, i++; 

    if (acc > 0) {
      char nxt = '*'; 
      if (i < n) nxt = s[i]; 

      ll z = (prev == '0') + (nxt == '0'); 
      ll neg = (prev == '-') + (nxt == '-'); 
      ll esp = (nxt == '*'); 
      if (acc % 2 == 1) {
        if (z + esp == 2) worst = max(worst, 1ll); 
        else worst = max(worst, 2ll); 
      } else {
        if (neg == 2 and acc == 2) worst = max(worst, 3ll); 
        else if (z == 1 and esp == 1) worst = max(worst, 1ll); 
        else worst = max(worst, 2ll); 
      } 
    } 
  } 

  return worst; 
} 

void solve() {
  int n; cin >> n;
  string s; cin >> s; 
  string rs = s; 

  bool ok = true; 
  if (s[0] == '0') ok = false; 
  forn(i,n-1) if (s[i] == '0' and s[i + 1] == '0') ok = false; 
  if (ok == false) return void(cout << "-1\n"); 

  forn(i,n) if (s[i] != '0') rs[i] = (s[i] == '+' ? '-' : '+'); 

  ll worst = max(f(s), f(rs));
  if (worst == 0) worst = -1; 
  cout << worst << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

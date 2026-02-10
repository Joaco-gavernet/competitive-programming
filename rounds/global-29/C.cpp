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


void solve() {
  int n; cin >> n; 
  string s; cin >> s; 

  vi debt(n,0); 
  forr(i,0,n) if (s[i] == '0') {
    if (i == 0) {
      if (i+1 < n) debt[i+1] = 2; 
      continue; 
    }
    if (i > 0 and (s[i-1] == '0' or debt[i-1] == 2)) {
      if (i+1 < n) debt[i+1] = 2; 
    }
    else if (i > 0 and debt[i-1] == 1) debt[i-1] = 0; 
    else if (i < n-1 and s[i+1] == '0') continue; 
    else if (i < n-1) debt[i+1] = 1; 
  }

  bool owe = false; 
  forn(i,n) {
    if (i == 2 and s[0] == '0') {
      if (i+1 < n) debt[i+1] = 0; 
      continue; 
    }
    if (debt[i] == 1) owe |= true; 
  }

  cout << (owe == false ? "YES" : "NO") << "\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

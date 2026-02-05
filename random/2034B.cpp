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

bool check(int mid, int m, int k, string s) {
  int cont = 0; 
  forn(i, SZ(s)) {
    if (s[i] == '1') cont = 0; 
    else cont++; 
    if (cont == m) {
      mid--, cont = 0; 
      forr(j,i,min(i+k, (ll)SZ(s))) s[j] = '1'; 
    }
  } 

  return mid >= 0; 
} 

void solve() {
  int n, m, k; cin >> n >> m >> k; 
  string s; cin >> s; 

  int l = -2, r = n + 1; 
  while (l + 1 < r) {
    int mid = (l + r) / 2; 
    if (check(mid, m, k, s)) r = mid; 
    else l = mid; 
  } 
  cout << r << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

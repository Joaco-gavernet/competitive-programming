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

ll count(vi &next, string &s, ll x, int n, int i = 0) {
  if (x <= 0) return 0;
  if (next[i] == -1) return x;

  ll aux = 0;
  if (next[i] == i) x /= 2, aux++, (++i) %= n;
  else {
    aux = min(x, (next[i] -i +n) %n); 
    x -= aux; 
    i = next[i]; 
  }
  return count(next, s, x, n, i) +aux; 
} 

void solve() {
  int n, q; cin >> n >> q; 
  string s; cin >> s; 
  vi next(n, -1); 
  forn(i,n) {
    forr(j,0,20) {
      if (s[(i+j) %n] == 'B') {
        next[i] = (i+j) %n; 
        break;
      }
    } 
  }
  vi a(q); forn(i,q) cin >> a[i]; 
  forn(i,q) cout << count(next, s, a[i], n) << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

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
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


void solve() {
  int n; cin >> n;
  vi v(n); forn(i,n) cin >> v[i]; 

  int ansl = -1, ansr = -1, ansz = 0; 
  forn(i,n) {
    int x = v[i]; 
    int l = -1, r = -1, sz = -1, act = 0; 
    forr(j,i+1,n) {
      if (v[j] > x) act--; 
      else if (v[j] < x) act++; 
      if (sz < act) {
        sz = act; 
        l = i, r = j; 
      } 
    } 
    if (sz > ansz) {
      ansz = sz; 
      ansl = l;
      ansr = r; 
    } 
  } 
  if (ansl == -1 and ansr == -1) ansl = ansr = 0; 
  cout << ansl +1 << ' ' << ansr +1 << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

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
  int N, A; cin >> N >> A; 

  if ((N -3) + 1 > 2*A) cout << "No\n"; 
  else {
    cout << "Yes\n"; 

    int x = 0, y = 0, n = N/2; 
    if ((N%2) == 0) n--; 
    forn(i,n) {
      cout << x << ' ' << y << '\n'; 
      x++; y ^= 1; 
    }
    x--; y ^= 1; 
    if ((N%2) == 0) {
      cout << x + A -(n-1) << ' ' << y << '\n';  
      cout << x + A -(n-1) << ' ' << 1 +y << '\n'; 
    } else {
      cout << x + 2*(A -(n-1)) << ' ' << y << '\n'; 
    } 
    forn(i,n) {
      cout << x << ' ' << 1 +y << '\n'; 
      x--; y ^= 1; 
    }
  } 
} 

int main(){
  FIN;

  int t; cin >> t;
  while (t--) solve(); 

  return 0;
}

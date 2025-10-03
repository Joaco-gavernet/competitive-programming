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
  int n, q; cin >> n >> q; 
  vi a(n); forn(i,n) cin >> a[i]; 

  // preproc
  vi one(n), zero(n); 
  one[0] = (a[0] == 1); 
  zero[0] = (a[0] == 0); 
  forr(i,1,n) {
    one[i] = one[i-1] + (a[i] == 1);
    zero[i] = zero[i-1] + (a[i] == 0);
  } 

  vi lefto(n, -1); // first double-one to left 
  int rightmost = -1; 
  forr(i,0,n-1) {
    lefto[i] = rightmost; 
    if (a[i] == 1 and a[i+1] == 1) rightmost = i;
  }
  lefto[n-1] = rightmost; 

  vi leftz(n, -1); // first double-zero to left 
  rightmost = -1; 
  forr(i,0,n-1) {
    leftz[i] = rightmost; 
    if (a[i] == 0 and a[i+1] == 0) rightmost = i;
  }
  leftz[n-1] = rightmost; 


  while (q--) {
    int l, r; cin >> l >> r; 
    l--, r--; 
    
    // check if valid 
    int sumo = one[r]; 
    int sumz = zero[r];
    if (l > 0) {
      sumo -= one[l-1];
      sumz -= zero[l-1];
    }

    int ans = -1; 
    if (sumo %3 == 0 and sumz %3 == 0) {
      ans = (sumo +sumz) /3;
      if (lefto[r] < l and leftz[r] < l) ans++;  
    }
    cout << ans << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

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

const int MOD = 1e9+7; 

ll be(ll x, ll y, ll m) {
  if (y == 0) return 1;
  ll p = be(x, y/2, m) % m;
  p = (p * p) % m;
  return (y%2 == 0)? p : (x * p) % m;
}

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 

  ll tot = 1; // empty subseq
  int i = n-1; 
  while (i >= 0) {
    tot += be(2, n -1 -i, MOD);

    int j = i +1; 
    while (j < n) {
      if (a[i] <= a[j]) {  
        j++; 
        continue; 
      }

      /*
      int k = i +1; 
      while (k < j) {
        if (a[i] > a[k] and a[k] > a[j]) {
          dbg(i, k, j); 
          tot -= be(2, n -1 -j, MOD); 
          (tot += MOD) %= MOD; 
        } 
        k++; 
      } 
      */
      int k = j +1; 
      while (k < n) {
        if (a[j] > a[k]) {
          dbg(i, j, k); 
          tot -= be(2, n -1 -i -2, MOD); 
          dbg(k, be(2, n -1 -i -2, MOD)); 
          (tot += MOD) %= MOD; 
        } 
        k++; 
      } 
      j++; 
    } 

    i--; 
  } 

  cout << tot << '\n'; 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

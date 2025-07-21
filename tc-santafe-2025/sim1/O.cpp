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

const int N = 35; 

void solve() {
  int n, q; cin >> n >> q; 
  vector<int> w(n); forn(i,n) cin >> w[i]; 

  vector<int> pref(n + 1);
  pref[0] = w[0];
  forr(i,1,n) {
    pref[i] = pref[i - 1] ^w[i];
  }

  vector<vector<int>> pre(n, vector<int>(N, 0)); 
  forn(i,n) {
    fill(pre[i].begin(), pre[i].end(), 0);
    if (i > 0) pre[i] = pre[i-1]; 
    pre[i][__lg(w[i])] = i; 

    for (int j = N -2; j >= 0; j--) {
      pre[i][j] = max(pre[i][j], pre[i][j +1]); 
    } 
  } 

  while (q--) {
    int x; cin >> x; 
    int r = n -1;
    while (r >= 0 and x > 0){
      int msb = __lg(x);
      int l = pre[r][msb];
      x ^= pref[r] ^ pref[l];
      r = l;
      if (w[l] > x) break;

      x ^= w[l];
      r--;
    }
    cout << n -r -1 << " ";
  } 
  cout << endl; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

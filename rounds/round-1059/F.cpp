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
#define esta(v,x) (v).find(x) != (v).end() 
#define RAYA cerr << "===============================" << endl


int f(vector<vi> &which, const int n) {
  vi skip(n, false); 
  forn(x,n-1) {
    for (auto sz: which[x]) skip[x+sz-1] = true; 
    if (skip[x]) continue; 
    return x; 
  }
  return -1;
}

void solve() {
  int n, m; cin >> n >> m;

  vi evt(n);
  vector<vi> who(n), which(n), whichr(n); 
  forn(i,m) {
    int l, r; cin >> l >> r; 
    evt[l-1]++; 
    if (r < n) evt[r]--;
    which[l-1].pb(r-l+1);
    whichr[r-1].pb(r-l+1); 
  } 
  reverse(all(whichr)); 

  forr(i,1,n) evt[i] += evt[i-1]; 
  int ini = 0, mx = *max_element(all(evt));
  vi ans(n, -1); 

  if (mx == m) {
    forn(i,n) if (evt[i] == mx) {
      ans[i] = ini++;
      break; 
    } 
  } else {
    int pos = f(which, n); 
    int poss = f(whichr, n); 
    if (poss > -1) poss = n -1 -poss; 

    // dbg(pos, poss); 
    if (pos > -1) {
      assert(pos +1 < n); 
      ans[pos] = ini++;
      ans[pos+1] = ini++;
    } else if (poss > -1) {
      assert(0 <= poss -1); 
      ans[poss] = ini++;
      ans[poss-1] = ini++;
    } else {
      ans[0] = ini++;
      ans[2] = ini++;
      ans[1] = ini++; 
    }
  } 

  forn(i,n) if (ans[i] == -1) ans[i] = ini++; 
  for (auto &x: ans) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

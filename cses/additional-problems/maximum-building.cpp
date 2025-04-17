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


ll check(vi &k) {
  k.pb(0); 
  const int n = SZ(k); 

  stack<ii> st; 
  st.push({0, -1}); 
  ll ans = 0, aux = -1, last = -1; 
  forn(i,n) {
    last = i; 
    while (st.top().first > k[i]) {
      auto [ki, id] = st.top(); st.pop(); 
      last = id; 
      aux = ki * (i - id); 
      ans = max(ans, aux); 
    }
    if (st.top().first < k[i]) st.push({k[i], last}); 
  } 
  return ans; 
} 

void preprocess(vector<vi> &pr, vector<string> &v) {
  const int n = SZ(v); 
  const int m = SZ(v[0]); 

  pr = vector<vi>(n, vi(m, 0)); 
  forn(j,m) {
    if (v[n-1][j] == '.') pr[n-1][j] = 1; 
    for (int i = n-2; i >= 0; i--) {
      if (v[i][j] == '.') pr[i][j] = pr[i +1][j] +1; 
    } 
  } 
} 

int main(){
  FIN;

  int n, m; cin >> n >> m; 
  vector<string> v(n); forn(i,n) cin >> v[i]; 



  ll ans = 0; 
  vector<vi> pr; 

  // first 
  preprocess(pr, v); 
  forn(i,SZ(pr)) ans = max(ans, check(pr[i])); 

  // reverse 
  pr.clear(); 
  vector<string> vt(m); 
  forn(i,n) forn(j,m) vt[j] += v[i][j]; 

  // second 
  preprocess(pr, vt); 
  forn(i,SZ(pr)) ans = max(ans, check(pr[i])); 

  cout << ans << '\n'; 

  return 0;
}

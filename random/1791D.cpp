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

  vector<ii> ops; 
  forn(i,26) {
    int l = -1, r = -1; 
    forn(j,n) if (s[j] == 'a'+i) {
      if (l == -1) l = r = j; 
      r = j; 
    } 
    if (l > -1 and l < r) ops.pb({l, -(i+1)}), ops.pb({r,i+1}); 
  }
  sort(all(ops)); 

  int mx = 0, idx = 0, act = 0; 
  for (auto [x, id]: ops) {
    act += (id < 0 ? 1 : -1); 
    if (act > mx) {
      mx = act; 
      idx = abs(x) + 1;
    } 
  } 

  map<char,int> mp; 
  forn(i,idx) mp[s[i]]++; 
  ll tot = SZ(mp); 
  mp.clear(); 

  forr(i,idx,n) mp[s[i]]++; 
  tot += SZ(mp); 

  cout << tot << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

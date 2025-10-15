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

const ll INF = 1LL<<60;  

void solve() {
  int n; cin >> n;
  string s; cin >> s; 
  vi pref(n+1); 

  forn(i,n) {
    pref[i+1] = pref[i]; 
    if (s[i] == 'a') pref[i+1]++; 
    else pref[i+1]--; 
  } 

  if (pref.back() == 0) cout << "0\n"; 
  else {
    int dif = pref.back(); 
    set<ii> st; 
    ll ans = INF; 
    forr(i,0,n+1) {
      // dif = pref[i] -(*it).ff;
      auto it = st.lower_bound({pref[i] -dif,-INF}); 
      if (it != st.end()) {
        if (dif == pref[i] -it->ff) ans = min(ans, i +it->ss); 
      } 

      st.insert({pref[i],-i}); 
    } 

    if (ans == n or ans == INF) ans = -1;
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

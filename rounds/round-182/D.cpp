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

const int MAXN = 2e5+5; 
const ll INF = 1LL<<60; 

void solve() {
  ll n, y; cin >> n >> y; 
  ll mx = 0; 
  vi cnt(MAXN), pref(MAXN); 
  vi c(n); forn(i,n) cin >> c[i], mx = max(mx, c[i]), cnt[c[i]]++; 
  forr(i,1,MAXN) pref[i] = pref[i-1] +cnt[i]; 

  ll best = -INF; 
  forr(x,2,max(mx,2LL)+1) {
      ll aux = 0; 
      const int up = (mx +x -1) /x;  
      forr(p,1,up+1) {
          ll need = pref[min(p*x, (ll)(MAXN -1))] -pref[(p-1)*x]; 
          aux += p*need -y*max(0LL, need -cnt[p]); 
          // dbg(p, need, cnt[p]); 
      }
      // dbg(x, aux); 
      best = max(best, aux); 
  } 

  cout << best << '\n'; 
}


int main(){
    FIN;
    int t = 1; 
    cin >> t;
    while (t--) solve();
    return 0;
}

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
  const int N = 2*n; 
  vi a(N); forn(i,N) cin >> a[i]; 

  vi par(N), impar(N); 
  par[0] = par[1] = a[0]; 
  impar[1] = a[1]; 
  forr(i,2,N) {
    par[i] = par[i-1]; 
    impar[i] = impar[i-1]; 
    if (i&1) impar[i] += a[i]; 
    else par[i] += a[i]; 
  } 

  vi pref(N); pref[0] = a[0]; 
  forn(i,N-1) pref[i+1] = pref[i] + a[i+1];  
  // dbg(pref); 
  // dbg(par); 
  // dbg(impar); 

  vi toprint; 
  forr(k,1,n+1) {
    ll ans = 0; 
    if (k&1) {
      ans = impar[N-k] -par[N-k];
      if (k > 1) ans += par[k-2] -impar[k-2];
    } else {
      ans = par[N-k] -impar[N-k];
      if (k > 1) ans += impar[k-2] -par[k-2];
    } 
    ans += pref[N-1] -pref[N-k];
    if (k > 1) ans -= pref[k-2];
    toprint.pb(ans); 
  } 
  for (auto &x: toprint) cout << x << ' '; 
  cout << '\n'; 
  // RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

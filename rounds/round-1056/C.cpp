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

const int MOD = 676'767'677;
const int MAXN = 1e5+5;

//~ Solucion O(N + Log N)

vector<ll> fact, ifact;

ll be(ll b, ll e, ll m = MOD) {
  ll r=1; b%=m;
  while(e){if(e&1LL)r=r*b%m;b=b*b%m;e/=2;}
  return r;
}
ll inv_mod(ll x, ll m){ return be(x,m-2,m); }

void init_fact(int maxn){
  fact.resize(maxn), ifact.resize(maxn);
  fact[0] = 1; forr(i, 1, maxn) fact[i] = (fact[i-1]*i)%MOD;
  ifact[maxn-1] = inv_mod(fact[maxn-1], MOD);
  for(int i = maxn-2; i >= 0; i--) ifact[i] = (ifact[i+1]*(i+1))%MOD;
}

ll binom(ll n, ll k){
  if(n < 0 or k < 0 or n < k) return 0;
  ll ans = fact[n];
  ans *= ifact[k]; ans %= MOD;
  ans *= ifact[n-k]; ans %= MOD;
  return ans;
}

bool impossible(int n, vi &a) {
  int mx = *max_element(all(a)); 
  int tot = 0;
  forn(i,n) {
    if (a[i] == mx) tot++; 
    if (i < n-1 and abs(a[i]-a[i+1]) != 1 and a[i] != mx) return true; 
  } 
  forn(i,n) {
    if (a[i] == mx) {
      int r = i; 
      while (r < n and a[r] == mx) r++; 
      if (r -i < tot) return true; 
      break; 
    } 
  } 
  return false; 
} 

void solve() {
  int n; cin >> n;
  vi a(n); forn(i,n) cin >> a[i]; 

  if (impossible(n, a)) cout << "0\n"; 
  else {
    cout << "boca" << '\n'; 
  }
}


int main(){
  FIN;
  init_fact(MAXN); 
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

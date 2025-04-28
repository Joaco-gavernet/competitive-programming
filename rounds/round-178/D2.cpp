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

// const int MAXN = 1e9+2;
const int MAXN = 10; 
const ll INF = 1LL<<60; 

// Criba lineal, obtiene los primos menores al parametro
vi min_prime; // min_prime[i] contiene el menor primo que divide a i, util para factorizar en log(i)
vi prime; 
vi pref; 

vi criba(ll n) {
  vb prime(n+1,true);
  min_prime.resize(n+1,INF);
  vi primos;
  for(ll p=2; p*p<=n; p++){
    if(!prime[p]) continue;
    for(ll i=p*p; i<=n; i += p) {
      prime[i] = false;
      min_prime[i] = min(min_prime[i],p);
    }
  }
  forr(i, 2, n+1){
    if(prime[i]) primos.pb(i), min_prime[i] = i;
  }
  return primos; // lista de primos hasta n
}


void solve() {
  int n; cin >> n; 

  ll coins = 0;
  vi a(n); forn(i,n) cin >> a[i], coins += a[i]; 

  // check if beautiful
  // if not: check how many wrongs and remainder coins 

  int l = -1, r = SZ(prime);
  while (l +1 < r) {
    int mid = l + (r-l)/2; 
    if (pref[mid] <= coins) l = mid; 
    else r = mid; 
  } 
  dbg(coins); 
  dbg(l, r); 

  RAYA; 
}


int main(){
  FIN;

  prime = criba(MAXN); 
  pref.pb(prime[0]); 
  forr(i,1,SZ(prime)) pref.pb(pref.back() +prime[i]); 
  dbg(prime); 
  dbg(pref); 

  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

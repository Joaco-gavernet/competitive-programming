#include <bits/stdc++.h>
using namespace std;

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
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


const int MAXN = 2e6+5; 
const ll INF = 1LL<<60; 

// Criba lineal, obtiene los primos menores al parametro
vi min_prime; // min_prime[i] contiene el menor primo que divide a i, util para factorizar en log(i)
vi cribe;

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
  vi a(n); forn(i,n) cin >> a[i]; 

  bool ok = true; 
  forn(i,n-1) if (a[i] > a[i+1]) ok = false; 

  vi prims; 
  forn(i,n) {
    vi facts; 
    int x = a[i]; 
    while (x > 1 and min_prime[x] > 1) {
      facts.pb(min_prime[x]); 
      x /= min_prime[x]; 
    } 

    if (a[i] == 1) prims.pb(1); 
    if (SZ(facts)) {
      sort(all(facts)); 
      prims.pb(facts.back()); 
      prims.pb(facts.front());
    } 
  } 

  bool A = false; 
  forn(i,SZ(prims)-1) if (prims[i] > prims[i+1]) A = true;

  if (ok) cout << "Bob" << '\n'; 
  else {
    if (A) cout << "Alice" << '\n';
    else cout << "Bob" << '\n'; 
  } 
}


int main() {
  NaN;
  cribe = criba(MAXN); 
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

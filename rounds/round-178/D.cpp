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

const int MAXN = 1e7+2;
const ll INF = 1LL<<60; 

// Criba lineal, obtiene los primos menores al parametro
vi min_prime; // min_prime[i] contiene el menor primo que divide a i, util para factorizar en log(i)
vi prime; 

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

int closer(vi &wrong, const ll prim) {
  int l = -1, r = SZ(wrong); 
  while (l +1 < r) {
    int mid = l + (r-l)/2; 
    if (wrong[mid] > prim) r = mid; 
    else l = mid; 
  } 

  if (l == SZ(wrong) -1) return l; 
  if (r == 0) return r; 
  assert(l >= 0 and l < SZ(wrong)); 
  assert(r >= 0 and r < SZ(wrong)); 
  if (abs(wrong[l] -prim) < abs(wrong[r] -prim)) return l; 
  return r; 
} 

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  sort(all(a)); 
  reverse(all(a)); 

  // check if beautiful, if not, check how many wrongs and remainder coins 
  int p = 0; 
  ll coins = 0; 
  vi wrong; 
  for (auto x: a) {
    if (prime[p] <= x) coins += x -prime[p++];
    else wrong.pb(x);
  } 

  // check if possible to save wrongs
  reverse(all(wrong)); 
  while (SZ(wrong)) {
    int id = closer(wrong, prime[p]); 
    if (coins < prime[p] -wrong[id]) break; 
    coins -= prime[p++] -wrong[id];
    swap(wrong[id], wrong.back()); 
    wrong.pop_back(); 
  } 

  cout << SZ(wrong) << '\n'; 
}


int main(){
  FIN;
  prime = criba(MAXN); 
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

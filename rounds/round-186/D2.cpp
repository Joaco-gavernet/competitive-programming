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

const ll MOD = 998244353;

const int MAXN = 55; // n <= 50
vi fact(MAXN), invfact(MAXN); 

void solve() {
  int n; cin >> n; 
  const int N = n +1; 
  vi a(N); forn(i,N) cin >> a[i]; 

  ll rounds = 0;
  forr(i,1,N) rounds = max(rounds, a[i]); 

  ll need = 0; 
  forr(i,1,N) need += max(0LL, rounds -1 -a[i]); 

  if (a[0] < need) cout << "0\n"; 
  else {
    int down = 0; 
    forr(i,1,N) {
      if (a[i] < rounds -1) {
        a[0] -= (rounds -1 -a[i]);
        a[i] = rounds -1; 
      }
      if (a[i] == rounds -1) down++; 
    }
    if (a[0] >= down) {
      forr(i,1,N) {
        if (a[i] < rounds) {
          a[0]--;
          a[i] = rounds; 
        }
      }
    } 

    int up = 0; 
    if (a[0] >= n) a[0] %= n;
    forr(i,1,N) if (a[i] == rounds) up++; 
    if (up == n) up = 0; 

    ll tot = fact[up + a[0]]; 
    (tot *= invfact[a[0]]) %= MOD; 
    (tot *= fact[n -up]) %= MOD;
    cout << tot << '\n'; 
  } 
}

ll be(ll x, ll y) {
  if (y == 0) return 1; 
  ll p = be(x, y/2) % MOD; 
  p = (p * p) % MOD; 
  if (y%2 == 1) p = (x * p) % MOD; 
  return p; 
} 

int main(){
  FIN;
  int t = 1; 
  cin >> t;

  fact[0] = 1;
  forr(i,1,MAXN) fact[i] = fact[i-1] * i % MOD; 

  invfact[MAXN-1] = be(fact[MAXN-1], MOD -2); 
  forr(i,1,MAXN) invfact[MAXN -i -1] = invfact[MAXN -i] * (MAXN -i) % MOD; 

  while (t--) solve();
  return 0;
}

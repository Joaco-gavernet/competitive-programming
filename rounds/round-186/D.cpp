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

long long modpow(long long a, long long e) {
  long long r = 1 % MOD;
  a %= MOD;
  while (e > 0) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}

vi pre(int N, ll M) {
  vi fact(N + 1);
  fact[0] = 1;
  for (int i = 1; i <= N; ++i) fact[i] = (fact[i - 1] * i) % M;
  return fact;
}

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
    forr(i,1,N) {
      if (a[i] < rounds -1) {
        a[0] -= (rounds -1 -a[i]);
        a[i] = rounds -1; 
      }
    }

    int up = 0; 
    if (a[0] > n) a[0] %= n;
    forr(i,1,N) if (a[i] == rounds) up++; 

    ll tot = fact[up] *invfact[up-a[0]] *fact[n -a[0]];
    cout << tot % MOD << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;

  fact[0] = 1;
  for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;
  invfact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
  for (int i = MAXN - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1) % MOD;

  while (t--) solve();
  return 0;
}

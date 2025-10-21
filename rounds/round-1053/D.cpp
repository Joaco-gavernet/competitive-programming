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

const int MOD = 998244353;
const int MAXN = 2e5+5;
// const int MAXN = 10;
vi fact; 

ll mod_pow(ll a, ll e) {
  ll r = 1 % MOD;
  a %= MOD;
  while (e) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}

void init_fact(int N) {
  fact.assign(N + 1, 1);
  for (int i = 1; i <= N; ++i) fact[i] = fact[i - 1] * i % MOD;
}

ll be_it(ll b, ll e, ll m) {
  ll r=1; b%=m;
  while(e){if(e&1LL)r=r*b%m;b=b*b%m;e/=2;}
  return r;
}

ll inv_mod(ll x, ll m) {return be_it(x,m-2,m);}

void solve() {
  int n; cin >> n; 
  ll acc = 0; 
  vi a(n); forn(i,n) cin >> a[i], acc += a[i]; 

  if (acc != n) cout << "0\n";
  else {
    ll ans = 1;
    ll z = 0; 
    for (int i = n-1; i >= 0; i--) {
      if (i < n/2) z += 2; 
      else if (2*(i+1) == n+1) z++; 

      if (z > 0) {
        if (z < a[i]) {
          cout << "0\n";
          return; 
        }

        // nCk mod MOD with modular inverse 
        (ans *= fact[z]) %= MOD; 
        (ans *= inv_mod(fact[a[i]], MOD)) %= MOD; 
        (ans *= inv_mod(fact[z - a[i]], MOD)) %= MOD; 

        z -= a[i]; 
      } else if (a[i] > 0) ans *= 0; 
    }
<<<<<<< Updated upstream

    cout << ans << '\n'; 
=======
    if (z > 0) cout << "0\n"; 
    else cout << dp.back() << '\n'; 
>>>>>>> Stashed changes
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  init_fact(MAXN); 
  while (t--) solve();
  return 0;
}

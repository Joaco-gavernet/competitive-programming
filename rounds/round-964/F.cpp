#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

//~ Solucion O(N + Log N)
vector<ll> fact, ifact;

ll be(ll b, ll e, ll m) {
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

int main(){
  FIN;

  // precomputing factorials with dp
  init_fact(MAXN);
  
  int t; cin >> t;
  while (t--) {
    int n,k; cin >> n >> k;
    int on = 0, off = 0;

    vi v(n); 
    forn(i,n) {
      cin >> v[i];
      if (v[i]) on++;
      else off++;
    }


    ll ans = 0;
    forr(d, k/2 +1, min(on+1,k+1)) {
      if (k -d > off or d > on) continue;

      // binomial-coefficients
      ll a = binom(on,d);
      ll b = binom(off,k-d);

      ans += (a * b) %MOD; 
      if (ans >= MOD) ans -= MOD;
    }

    cout << ans << endl;
  }


  return 0;
}

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
const ll MAXN = (int)(1e6);


int main(){
  FIN;

  ll n; cin >> n;
  ll aux = n % MOD;
  ll ans = aux * (aux+1) /2;
  ans %= MOD;
  
  // solve interval (1,sqrt(n)]
  forr(i,1,MAXN+1) {
    ll cont = n /i -1;
    cont *= i; cont %= MOD;
    if (cont < 0) break;
    ans += cont;
    if (ans >= MOD) ans -= MOD;
  }

  // solve interval (sqrt(n),n]
  if (n > MAXN) {
    ll r = n;
    ll inv2 = (MOD+1)/2;
    forr(i,2,MAXN+1) {
      ll l = n/i +1;
      // suma aritmetica
      ll suma = (l+r); suma %= MOD; 
      suma *= (r-l+1); suma %= MOD;
      suma *= inv2; suma %= MOD;
      suma *= (i-2); suma %= MOD;
      ans += suma;
      if (ans >= MOD) ans -= MOD;
    }
  }

  cout << ans << '\n';

  
  return 0;
}

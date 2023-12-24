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
#define op(a,b) (((a%MOD)*(b%MOD))%MOD) 
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(1e9+5);



int main(){
  FIN;
  int t; cin >> t;
  while (t--) {
    // a = base
    // b = exponent
    ll a, b; cin >> a >> b;

    // step 1: construction and memoization with dp vector
    vector<ll> v = {1,a};
    ll k = a;
    forn(_,log2(b)) {
      k = op(k,k);
      v.pb(k);
    }
    
    // step 2: use dp vector
    ll bis = b;
    ll ans = 1;
    while (floor(log2(bis)) > 0) {
      ll m = log2(bis); // find exponent odd "m" in base "a"
      ans = op(ans,op(v[m],v[m])); // use precalculated values in "v"
      bis -= pow(2,m); // substract what was calculated from "bis" ("b") 
    }
    
    // step 3: consider if b is odd
    if (bis == 1) ans = op(ans,a);
    
    cout << ans << '\n';
  }
  
  return 0;
}








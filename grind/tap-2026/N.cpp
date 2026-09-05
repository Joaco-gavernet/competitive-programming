/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int MOD = 998244353;
const int MAXN  = 2e6+5;


ll be(ll x, ll y, ll m = MOD) {
  if (y == 0) return 1;
  ll p = be(x, y/2, m) % m;
  p = (p * p) % m;
  return (y%2 == 0)? p : (x * p) % m;
}

ll inv_mod(ll x, ll m = MOD) {return be(x,m-2,m);}

int main(){  
  FIN;

  ll n, k, a; cin >> n >> k >> a; 
  if (max(0LL, n - 2) < k) return (cout << 0 << '\n', 0); 
  if (n == 1) return (cout << a << '\n', 0); 
  if (n == 2) return (cout << a * a << '\n', 0); 
  vi fact(MAXN); 
  fact[0] = fact[1] = 1; 
  forr(i,2,MAXN) fact[i] = (fact[i - 1] * i) % MOD; 

  ll tot = a * a; 
  (tot *= fact[n - 2]) %= MOD; 
  (tot *= inv_mod(fact[k])) %= MOD; 
  (tot *= inv_mod(fact[n - 2 - k])) %= MOD; 
  (tot *= be(a - 1, n - k - 2)) %= MOD; 
  cout << tot << '\n'; 

  return 0;
}

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

#define uint unsigned int
typedef unsigned long long ll;
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

const ll MAXN = 1e8+5; 


int main(){
  FIN;
  // Consider
  // [x] unsigned int for 1<<32
  // [x] compute criba with bitset
  // [x] check only 5 mod 6 to cut the memory 
  ll n, A, B, C, D; cin >> n >> A >> B >> C >> D; 

  auto f = [&](ll x) -> ll {
    return A * x * x * x + B * x * x + C * x + D; 
  }; 

  auto T = [&](ll x) -> ll {
    return x / 3; 
  }; 

  auto cond = [&](ll x) -> bool {
    return x % 6 == 1 or x % 6 == 5; 
  }; 

  ll tot = 0;
  if (n >= 2) {
    ll sum = 0; 
    for (ll i = 2; i <= n; i *= 2) sum += n / i;
    tot += sum * f(2); 
  } 
  if (n >= 3) {
    ll sum = 0; 
    for (ll i = 3; i <= n; i *= 3) sum += n / i;
    tot += sum * f(3); 
  } 

  // build criba using congruence mod 6 
  bitset<MAXN> b; 
  for (ll i = 5; i <= n; i++) if (cond(i)) {
    if (b[T(i)]) continue; 
    ll sum = 0; 
    for (ll j = i; j <= n; j += i) if (cond(j)) {
      b[T(j)] = true; 
    }
    for (ll k = i; k <= n; k *= i) sum += n / k;
    tot += sum * f(i); 
  } 

  cout << (uint)tot << '\n'; 

  return 0;
}

/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

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
#define RAYA cerr << "=============================\n" 


using u128 = __uint128_t; 
using i128 = __int128_t; 

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); 
struct MyRandom {
  uniform_int_distribution<ll> dist; 
  MyRandom(ll l, ll r): dist(l, r) {} 
  ll get() { return dist(rng); } 
}; 

u128 random_u128() {
  return (u128(rng()) << 64) | u128(rng());
}

ll solve(vi& a, vector<i128>& h, vector<i128>& H) {
  const int n = SZ(a); 
  vector<i128> ph(n + 1); 
  forn(i,n) ph[i + 1] = ph[i] ^ h[a[i]]; 

  ll tot = 0, i = 0; 
  while (i < n) { 
    if (a[i] == 0) {
      unordered_map<ll, bool> seen; 
      seen[a[i]] = true; 

      ll r = i + 1, mx = 1; 
      while (r < n and seen[a[r]] == false) {
        seen[a[r]] = true; 
        mx = max(mx, a[r]); 
        int l = (r + 1) - mx - 1; 
        if (l >= 0 and (ph[r + 1] ^ ph[l]) == H[mx + 1]) tot++; 
        r++; 
      } 
      i = r; 
    } else i++; 
  } 
  return tot; 
} 

int main(){  
  FIN;

  int n; cin >> n;  
  vi a(n); forn(i,n) cin >> a[i], a[i]--; 

  MyRandom randi(0, 1LL<<60); 
  vector<i128> h(n), H(n + 1); 
  forn(i,n) h[i] = random_u128(), H[i + 1] = H[i] ^ h[i]; 

  ll tot = 0;
  for (auto x : a) tot += x == 0; 
  tot += solve(a, h, H); 
  reverse(all(a)); 
  tot += solve(a, h, H); 
  cout << tot << '\n'; 

  return 0;
}

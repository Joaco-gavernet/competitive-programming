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

struct DistinctCounter : map<int,int> {
  auto erase(int x) -> void {
    if (--map<int,int>::at(x) == 0)
      map<int,int>::erase(x); 
  } 
}; 

vi process(vi &a, int k) {
  const int n = SZ(a);
  int dif = 0;
  vi next(n, -1);
  DistinctCounter mp;

  int l = 0, r = 0; 
  while (r < n) {
    while (r < n and SZ(mp) <= k) mp[a[r]]++, r++; 
    while (SZ(mp) > k) next[l] = r-1, mp.erase(a[l++]); 
  } 
  while (l < n and SZ(mp) == k) next[l] = n, mp.erase(a[l++]); 
  return next; 
} 

void solve() {
  ll n, k, l, r;
  cin >> n >> k >> l >> r; l = max(l, k); 
  vi a(n); forn(i,n) cin >> a[i]; 

  vi b = process(a, k-1); 
  vi c = process(a, k); 

  ll tot = 0; 
  forn(i,n) {
    if (b[i] == -1) continue; 
    int left = max(b[i], i +l -1);
    int right = min(c[i] -1, i +r -1);
    if (right -left +1 > 0) tot += right -left +1;
  } 

  cout << tot << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

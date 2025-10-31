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

bool cond(int fro, int prev, int last) {
  return fro == last or fro == prev; 
} 

void solve() {
  int n, k; cin >> n >> k; 
  map<int,int> mp; 
  vi a(n); forn(i,n) cin >> a[i], mp[a[i]]++; 

  ll x[] = {a[0], a[1], a[(n > 2 ? 2 : 0)]}; 
  if (SZ(mp) < n) {
    forr(k,1,n+1) if (mp[k] == 0) {
      x[0] = k; 
      break; 
    }
    x[2] = a.back(); 
    forr(u,1,n+1) if (u != x[0] and u != x[2]) {
      x[1] = u; 
      break; 
    }
  }

  forn(i,k) cout << x[i%3] << ' '; 
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

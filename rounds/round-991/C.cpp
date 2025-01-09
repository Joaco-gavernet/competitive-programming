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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define RAYA cerr << "===============================" << endl

const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


bool check(ll sum, ll dos, ll tres) {
  if (sum %9 == 0) return true; 
  ll rest = sum %9; 

  const ll maxi = 2*dos + 6*tres +5;
  vb possible(maxi, false); 
  vector<ii> how(maxi, {-1, -1}); 
  
  possible[0] = true; 
  how[0] = {0, 0}; 
  if (dos > 0) { 
    possible[2] = true;
    how[2] = {1,0}; 
  }
  if (tres > 0) { 
    possible[6] = true;
    how[6] = {0,1}; 
  }
  forn(i,maxi) {
    if (possible[i] == false) continue; 
    if (how[i].first < dos) {
      possible[i +2] = true; 
      how[i +2] = how[i]; 
      how[i +2].first++; 
    }
    if (how[i].second < tres) {
      possible[i +6] = true; 
      how[i +6] = how[i]; 
      how[i +6].second++; 
    }
  }
  
  forn(i,maxi) {
    if (possible[i] and (rest +i) %9 == 0) 
      return true; 
  } 

  return false; 
} 

void solve() {
  string num; cin >> num; 
  ll sum = 0, dos = 0, tres = 0; 
  for (char c : num) {
    ll x = int(c -'0'); 
    if (x == 2) dos++; 
    else if (x == 3) tres++; 
    sum += x; 
  }
  if (check(sum,dos,tres)) cout << "YES\n"; 
  else cout << "NO\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

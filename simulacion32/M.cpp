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


int n, k, worst = -1; 
ll check(string &s) {
  int mx = n%k, mi = k -n%k, ans = 0, last = 0; 
  if (mx == 0) swap(mx, mi); 
  forn(_,mx) {
    ans = max(ans, stoi(s.substr(last,worst))); 
    last += worst; 
  }

  return ans; 
}

int main(){
  FIN;

  cin >> n >> k; 
  string s; cin >> s; 
  sort(all(s)); 
  worst = n/k +int(bool(n%k)); 
  if (k >= 9) {
    if (k == 10 or n == 9) cout << *s.rbegin() << '\n'; 
    else cout << s[0] << s[1] << '\n'; 
    return 0; 
  }

  ll ans = check(s); 
  while (next_permutation(all(s))) ans = min(ans, check(s)); 

  cout << ans << '\n'; 
  return 0;
}

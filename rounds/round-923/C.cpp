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
const int MAXN = (int)(2e5+5);
 
 
 
int main(){
  FIN;

  int t; cin >> t;
  while (t--) {
    int n,m,K,k; cin >> n >> m >> K;
    set<int> a;
    set<int> b;
    forn(_,n) cin >> k, a.insert(k);
    forn(_,m) cin >> k, b.insert(k);
    k = K/2;

    int as = 0, bs = 0, both = 0;

    string ans = "NO\n";
    forr(i,1,K+1) {
      dbg(a.count(i), b.count(i));
      if (a.count(i) == 0 and b.count(i) == 0) goto fin;
      else if (a.count(i) == 1 and b.count(i) == 1) both++;
      else if (a.count(i)) as++;
      else if (b.count(i)) bs++;
    }
    dbg(as,bs,both);

    dbg(k);
    if (as >= k and bs >= k) ans = "YES\n";
    else if (as >= k and bs + both >= k) ans = "YES\n";
    else if (bs >= k and as + both >= k) ans = "YES\n";
    else if (as < k and bs < k and k-as <= both and k-as-bs <= both-k+as) ans = "YES\n";
    fin: cout << ans;
  }

  return 0;
}

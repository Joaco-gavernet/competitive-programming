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
const int MAXN = 10;
#else
#define dbg(...)
const int MAXN = (int)(2e5+5);
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < int(b); i++)
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


int main(){
  FIN;

  int n,m; cin >> n >> m;
  vector<int> cost(n), returns(n);
  priority_queue<int> elements;
  forn(i,n) cin >> cost[i];
  forn(i,n) cin >> returns[i];

  int aux;
  forn(i,m) {
    cin >> aux;
    elements.push(aux);
  }

  vector<int> loss(n);
  forn(i,n) loss[i] = cost[i] - returns[i];

  vector<pair<int,int>> weapon(n);
  forn(i,n) weapon[i] = {loss[i], cost[i]};
  sort(all(weapon));
  ll xp = 0;

  dbg(weapon);

  // preprocessing
  vector<int> dp(MAXN,INF);
  forn(i,n) dp[cost[i]] = min(dp[cost[i]], loss[i]);
  forn(i,MAXN) dp[i] = min(dp[i],dp[i-1]);
  dbg(dp);


  while(true) {
    // elemento i-th
    int actual = elements.top();
    elements.pop();
    if (dp[actual] == INF) break;
    else {
      xp += 2;
      actual -= dp[actual];
      elements.push(actual);
    }
  }

  cout << xp << '\n';
  
  
  return 0;
}

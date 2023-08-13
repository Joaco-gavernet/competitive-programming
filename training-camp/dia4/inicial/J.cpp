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

bool second(pair<int,int> a, pair<int,int> b) {
  bool result = false;
  if (a.second != b.second) {
    result = a.second > b.second;
  } else {
    result = a.first > b.first;
  }
  return result;
}

int main(){
  FIN;
  
  int n; cin >> n;
  vector<pair<int,int>> v(n);
  forn(i,n) cin >> v[i].first >> v[i].second;
  
  sort(v.begin(),v.end(),second);
  ll reps = 1, tot = 0;
  ll i = 0;
  while (i < n and v[i].second != 0) {
    reps += v[i].second;
    tot += v[i].first;
    i++;
    reps--;
  }
  while (i<n and reps > 0) {
    tot += v[i].first;
    reps--;
    i++;
  }
  cout << tot << "\n";
  
  return 0;
}

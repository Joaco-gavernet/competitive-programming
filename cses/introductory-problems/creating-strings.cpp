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

vector<string> ans;

// solve(i,x,r,&ans);
// i - last index of characters in r added to x
// x - actual state of the string
// r - actual state of the dashboard of characters (with amounts)
// &ans - final answers to print
// n - size of the solution string
void solve(string x, vector<pair<char,int>> r, int n) {
  if (int(x.size()) == n) cout << x << '\n'; // base case
  else {
    forn(j,r.size()) {
      if (r[j].second > 0) {
	x += r[j].first;
	r[j].second--;
	solve(x,r,n);
	r[j].second++;
	x.pop_back();
      }
    }
  }
}

int main(){
  FIN;
  
  // precalculating factorials dynamically
  vector<int> fact(10);
  fact[0] = 1;
  fact[1] = 1;
  forr(i,1,10) fact[i] = fact[i-1]*i;
  
  // reading standard input
  string s; cin >> s;
  int n = s.size();
  int abc[26] = {0};
  for (char i : s) abc[i-'a']++;
  vector<pair<char,int>> r; forn(i,26) if (abc[i] > 0) r.pb({char(i+'a'),abc[i]});
  
  // finding total possible solutions
  int divisor = 1;
  forn(i,r.size()) divisor *= fact[r[i].second];
  int tot = fact[n]/divisor;
  cout << tot << '\n';
  
  // building solutions recursively
  forn(i,r.size()) {
    string x; x += r[i].first;
    r[i].second--;
    solve(x,r,n);
    r[i].second++;
    x.pop_back();
  }
  
  return 0;
}





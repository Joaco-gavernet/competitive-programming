#include <bits/stdc++.h>
using namespace std;

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
typedef vector<int> vi;

#define RAYA cerr << "===============================" << endl

#define forr(i,a,b) for (int i = (a); i < b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define fs first
#define ss second

const int INF = 1<<30;

void solve() {
  int n; cin >> n;
  string s = to_string(n);
  int sz = s.size();
  s += s, s += s, s += s; // TODO check

  vector<pair<int,int>> vec;
  dbg(s);

  for (int a = 1; a <= 10000; a++) {
    int num = 0;
    for (int j = 1; j <= min(sz*a, 6); j++) {
      num = num *10 + s[j-1] -48;
      int b = sz *a - j;
      if (a == 20) {
	dbg(b,j,num);
	dbg(n *a -b);
      }
      if (n *a -b == num and b != 0) 
	vec.push_back({a,b});
    }
  }

  cout << vec.size() << '\n';
  for (auto [a,b]: vec) cout << a << " " << b << '\n';
  cout << '\n';
}

int main() {

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

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

typedef vector<int> vi;

int solve(int l, int r, vector<vi> &prea, vector<vi> &preb) {
  dbg(l,r);

  // build actual vectors in (l,r) range
  int ans = 0;
  forn(i,26) {
    int acta = prea[r][i] - prea[l-1][i];
    int actb = preb[r][i] - preb[l-1][i];
    dbg(acta,actb);
    ans += abs(acta - actb);
  }

  return ans/;
}

/*
0
1
0
2
2
1
1
0
*/

int main(){
  FIN;

  int t; cin >> t;
  while (t--) {
    int n,q; cin >> n >> q;
    string a,b; cin >> a >> b;

    // Preprocessing
    vector<vi> prea(n+1,vi(26,0));
    vector<vi> preb(n+1,vi(26,0));
    forr(i,1,n+1) {
      char c = a[i-1];
      prea[i] = prea[i-1];
      prea[i][c -'a']++;
    }
    forr(i,1,n+1) {
      char c = b[i-1];
      if (i>0) preb[i] = preb[i-1];
      preb[i][c -'a']++;
    }


    while (q--) {
      int l,r; cin >> l >> r;
      cout << solve(l,r,prea,preb) << '\n';
    }
    RAYA;
  }
  
  
  
  return 0;
}

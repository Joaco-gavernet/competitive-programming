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

#define f first
#define s second

// if v is in a cycle: 
// - ans[v].f == 1
// - ans[v].s == size of the cycle
// else if v is not in a cycle: 
// - ans[v].f == 0
// - ans[v].s == distance to proximum cycle
vector<pair<int,int>> floydAlgorithm(int x, vector<int> &succ) {
  int n = succ.size();
  vector<pair<int,int>> ans(n);
  vector<bool> visto(n);
  int tot = 0;

  while (tot < n) {
    // check if there is any cycle
    stack<int> s; s.push(x);
    int a = succ[x]; 
    int b = succ[succ[x]];

    while (a != b and visto[a] == 0) {
      s.push(a);
      a = succ[a];
      b = succ[succ[b]];
    }

    if (visto[a] == 1) { // use already computed nodes for efficiency
      while (s.size()) { // update visited nodes
        a = s.top(); s.pop();
        visto[a] = 1; tot++;
        ans[a].f = 0; // path to cycle
        ans[a].s = ans[succ[a]].s +1; // consider distance to start of cycle
      }
    } else {
      // find first node that belongs to the cycle
      int dist = 0;
      a = x;
      while (a != b) {
        a = succ[a];
        dist++;
        b = succ[b];
      }
      int start = a;

      // calculate the length of the cycle
      b = succ[a];
      int length = 1;
      while (start != b) {
        length++;
        b = succ[b];
      }

      // update ans for cycle found
      ans[start] = {1,length};
      if (visto[start] == 0) visto[start] = 1, tot++;
      b = succ[start];
      while (b != start) {
        if (visto[b] == 1) break;
        ans[b] = {1,length};
        visto[b] = 1, tot++;
        b = succ[b];
      }
      dist += ans[start].s;

      // update ans for path from start to cycle
      if (x != start) { 
        b = x;
        while (b != start) {
          if (visto[b] == 1) break;
          ans[b] = {0,dist--};
          visto[b] = 1, tot++;
          b = succ[b];
        }
      }
    }
    
    while (tot < n and visto[x] == 1) x++;
  }

  return ans;
}

int main(){
  FIN;

  int n; cin >> n;
  vector<int> succ(n); 
  forn(i,n) {
    cin >> succ[i];
    succ[i]--;
  }

  vector<pair<int,int>> cycles = floydAlgorithm(0,succ);

  // print result
  for(auto [a,b] : cycles) cout << b << ' ';
  cout << endl;
  
  
  return 0;
}






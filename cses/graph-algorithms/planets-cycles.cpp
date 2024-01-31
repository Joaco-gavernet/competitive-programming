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
vector<pair<int,int>> findCycles(int x, vector<int> &succ) {
  int n = succ.size();
  vector<pair<int,int>> ans(n);
  vector<bool> visto(n);
  int tot = 0;
  dbg(succ);

  while (tot < n) {
    // check if there is any cycle
    int a = succ[x];
    int b = succ[succ[x]];
    dbg(x);
    dbg(a,b);

    while (a != b) {
      if (a == succ[a] and b == succ[succ[b]]) break;
      a = succ[a];
      b = succ[succ[b]];
    }
    
    // find first node that belongs to the cycle
    a = x;
    while (a != b) {
      a = succ[a];
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
    visto[start] = 1;
    tot++;
    b = succ[start];
    while (b != start) {
      ans[b] = {1,length};
      tot++;
      visto[b] = 1;
      b = succ[b];
    }

    int dist = 1;
    while (x != start) {
      if (visto[x] == 1) break;
      ans[x] = {0,dist};
      dist; tot++;
      visto[x] = 1;
      x = succ[x];
    }
    
    x = 0;
    dbg(visto);
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

  vector<pair<int,int>> cycles = findCycles(0,succ);
  dbg(cycles);

  vector<int> ans(n);
  forn(i,n) {
    if (cycles[i].f == 1) ans[i] = cycles[i].s;
    else {
      int result = cycles[i].s; // distance to proximum cycle
      int act = i;
      while (cycles[act].f == 0) act = succ[act]; 
      result += cycles[act].s;
      ans[i] = result;
    }
  }

  // print result
  for(int i: ans) cout << i << ' ';
  cout << endl;
  
  
  return 0;
}






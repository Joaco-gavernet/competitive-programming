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
const int MAXN = (int)(6e5+5);
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


struct vertex {
  map<char,int> next, go; 
  int p,link,nextleaf;
  char pch;
  vector<int> leaf;
  vertex(int p=-1, char pch=-1,int nextleaf=-1):
    p(p),pch(pch),link(-1),nextleaf(nextleaf){}
};

vector<int> marca(MAXN,0);
vector<bool> visto(MAXN,false);
vector<vertex> t;
vector<vector<int>> g(MAXN); // Suffix-links tree

void aho_init(){ //do not forget!!
  t.clear(); t.pb(vertex());
}

void add_string(string s, int id) {
  int v=0;
  for(char c:s) {
    if(!t[v].next.count(c)){
      t[v].next[c]=t.size();
      t.pb(vertex(v,c));
    }
    v=t[v].next[c];
  }
  t[v].leaf.pb(id);
}

int go(int v, char c);

int get_link(int v) {
  if(t[v].link < 0) {
    if(v == 0 || t[v].p == 0) t[v].link = 0;
    else t[v].link = go(get_link(t[v].p),t[v].pch);
    g[t[v].link].pb(v);
  }
  return t[v].link;
}

int go(int v, char c){
  if(!t[v].go.count(c)) {
    if (t[v].next.count(c)) t[v].go[c] = t[v].next[c];
    else t[v].go[c] = v == 0 ? 0 : go(get_link(v),c);
  }
  return t[v].go[c];
}

void construct_links() { forn(i,t.size()) get_link(i); }

int dfs(int v) {
  visto[v] = true;

  for (int u: g[v]) if (visto[u] == false) {
    marca[v] += dfs(u);
  }
  return marca[v];
}

int main(){
  FIN;

  string s; cin >> s;
  int k; cin >> k;

  aho_init();

  vector<string> ss(k);
  forn(i,k) cin >> ss[i], add_string(ss[i],i);
  construct_links();


  int act = 0;
  for (char c: s) {
    while (act != 0 and go(act,c) == 0) act = get_link(act);
    act = go(act,c);
    marca[act] += 1;
  }

  dfs(0);

  // go through trie to check if words are visited at the end
  forn(i,k) {
    string z = ss[i];
    int act = 0;
    for (char c: z) act = go(act,c);
    cout << marca[act] << '\n';
  }

  return 0;
}


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


const int K = 26;

struct Vertex {
  int next[K];
  int leaf;

  Vertex() {
    fill(begin(next), end(next), -1);
    leaf = 0;
  }
};

void add_string(string const& s, vector<Vertex> &trie) {
  int v = 0;
  for (char ch : s) {
    int c = ch - 'a';
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = int(trie.size());
      trie.emplace_back();
    }
    v = trie[v].next[c];
  }
  trie[v].leaf++;
}

bool find(string &pal, vector<Vertex> &trie) {
    int cur = 0;
    for(char u : pal) {
        cur = trie[cur].next[u-'a'];
        if(cur == -1) return false;
    }
    return true;
}


int main(){
  FIN;
  
  vector<Vertex> tr(1), tri(1);
  int reverted = false;
  
  int q; cin >> q;
  forn(i,q) {
    int op; 
    string act; 
    
    cin >> op;
    
    if (op == 1) {
      cin >> act;
      if (reverted == false) {
	add_string(act,tr);
	reverse(act.begin(),act.end());
	add_string(act,tri);
      }
      else {
	add_string(act,tri);
	reverse(act.begin(),act.end());
	add_string(act,tr);
      }
      
    } else if (op == 2) {
      cin >> act;
      bool result;
      
      if (reverted == false) result = find(act,tr);
      else result = find(act,tri);
      cout << result << "\n";
      
    } else if (op == 3) {
      reverted = !reverted;
    }
  }
  
  
  return 0;
}

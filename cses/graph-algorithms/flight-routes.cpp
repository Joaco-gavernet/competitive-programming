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
const ll INF = (ll)(1LL<<60); // (1LL<<60)
const int MAXN = (int)(2e5+5);

typedef ll tipo;

ll n,m,k;

struct arista {
  tipo x, w; // x -> next node, w = weight
};

struct nodo {
  tipo d, v, a; // d -> distance, v -> actual node, a = previous node
  bool operator<(const nodo& x) const {return d > x.d;}
};

void printpq(priority_queue<nodo> p) {
  while (!p.empty()) {
    nodo i = p.top();
    dbg(i.d,i.v,i.a);
    p.pop();
  }
}

priority_queue<ll> ans[MAXN];

void Dijkstra(int start, vector<vector<arista>> &g) {
  vector<nodo> act(n);
  priority_queue<nodo> p; p.push({0,start,-1});
  
  while(!p.empty()) {
    nodo it=p.top(); p.pop();
    if(it.d > ans[it.v].top()) continue;
    else {
      act[it.v] = it;
      for(arista &u : g[it.v]) {
	ll cur = it.d + u.w;
	if (ll(ans[u.x].size()) == k and cur < ans[u.x].top()) ans[u.x].pop();
	if (ll(ans[u.x].size()) < k) {
	  ans[u.x].push(cur);
	  p.push({cur,u.x,it.v});
	}
	
      }
    }
  }
}



int main(){
  FIN;
  
  cin >> n >> m >> k;
  vector<vector<arista>> g(n);
  
  ll a,b,w;
  while (m--) {
    cin >> a >> b >> w;
    g[--a].pb({--b,w});
  }
  
  ans[0].push(0);
  Dijkstra(0,g);
  
  deque<ll> z;
  while(ans[n-1].size()) {
    z.push_front(ans[n-1].top());
    ans[n-1].pop();
  }
  
  for(ll i: z) cout << i << ' ';
  
  
  return 0;
}




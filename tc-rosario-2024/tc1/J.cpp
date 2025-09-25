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

typedef ll tipo;

struct arista {
    int x; tipo w; // x -> next node, w = weight
};

struct nodo {
    tipo d, v, a; // d -> distance, v -> actual node, a = previous node
    bool operator<(const nodo& x) const {return d > x.d;}
};

vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
    vector<nodo> ans(n);
    vector<bool> visto(n, false);
    priority_queue<nodo> p; p.push({0,start,-1});
    while(!p.empty()) {
        nodo it=p.top(); p.pop();
        if(visto[it.v]) continue;
        else {
            ans[it.v] = it; visto[it.v] = true;
            for(arista u : g[it.v]) {
                if(!visto[u.x]) p.push({it.d + u.w, u.x, it.v});
            }
        }
    }
    return ans;
}

int main(){
  FIN;
  int n, m;
  cin >> n >> m;
  vector<vector<arista>> g(n);
  forn(i,m){
    int a, b;
    ll d;
    cin >> a >> b >> d;
    a--;b--;
    arista e1, e2;
    e1.x=b; e2.x=a;
    e1.w=d; e2.w=d;
    g[a].pb(e1); g[b].pb(e2);
  }
  vector <nodo> ans = Dijkstra(n-1,n,g);
  //forn(i,n) cout << ans[i].d << " ";
  //cout << "\n";
  if(ans[0].d==0){cout << "inf\n"; return 0;}
  /*vector <int> recorrido;
  recorrido.pb(0);
  int z=0;
  while(z!=-1){
    z=ans[z].a;
    recorrido.pb(z);
  }
  
  //cout*/
  vector<pair<ll,ll>> v;
  forn(i,n) v.pb({ans[i].d,ans[i].v});
  sort(all(v));
  string juega;
  forn(i,n) juega+="1";
  vector <pair<string,ll>> brunito;
  forn(i,n){
    if(v[i].second==0) break;
    juega[v[i].second]='0';
    //cout << juega << " " << v[i+1].first-v[i].first << "\n";
    if(v[i+1].first-v[i].first!=0) brunito.pb({juega,v[i+1].first-v[i].first});
  }
  cout << ans[0].d << " " << brunito.size() << "\n";
  for( auto u : brunito) cout << u.first << " " << u.second << "\n";
  return 0;
}

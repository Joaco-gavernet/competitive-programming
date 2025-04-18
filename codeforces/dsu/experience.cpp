#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

// DSU struct con path compression y union por size
// Complejidad: O(ack(n)) por operacion, donde ack(n) es la funcion inversa de Ackermann, casi O(1)
struct DSU {
  vi link, sz, ans;
  vector<vi> childs; 

  DSU(int tam) {
    link.resize(tam+5), sz.resize(tam+5);
    childs.resize(tam +5), ans.resize(tam +5);
    forn(i, tam+5) link[i] = i, sz[i] = 1;
  }

  ll find(ll x){ return (link[x] == x ? x : find(link[x])); }
  bool same(ll a, ll b) { return find(a) == find(b); }

  void join(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
    ans[b] -= ans[a]; 
  }

  ll get(int x) {
    if (link[x] == x) return ans[x]; 
    else return ans[x] + get(link[x]); 
  } 
};

int main(){
  FIN;

  int n, m; cin >> n >> m; 
  DSU ds(n); 
  vi ans(n); 

  while (m--) {
    string op; cin >> op; 
    if (op == "join") {
      int a, b; cin >> a >> b; 
      ds.join(a, b); 
    } else if (op == "add") {
      int a, v; cin >> a >> v; 
      ds.ans[ds.find(a)] += v; 
    } else {
      int x; cin >> x; 
      cout << ds.get(x) << '\n'; 
    } 
  } 

  
  return 0;
}

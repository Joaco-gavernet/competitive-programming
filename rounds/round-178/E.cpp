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


const ll INF = 1LL<<59; 

int main(){
  FIN;

  int n, k; cin >> n >> k; 
  string s; cin >> s; 
  vector<string> v(k); forn(i,k) cin >> v[i]; 
  s = '&' + s; n++; 

  map<char, int> next; 
  forn(i,26) next['a'+i] = -1; 
  vector<map<char, int>> edge(n); 

  dbg(INF); 
  vi min_cost(n, INF); 
  for (int i = n-1; i >= 0; i--) {
    edge[i] = next; 
    next[s[i]] = i; 

    forn(j,k) {
      char c = 'a' +j; 
      dbg(edge[i][c]); 
      if (edge[i][c] == -1) continue; 
      min_cost[i] = min(min_cost[i], min_cost[edge[i][c]] +1); 
    } 
    dbg(min_cost[i]); 
    if (min_cost[i] == INF) min_cost[i] = 0; 
  } 


  vi ans; 
  forn(i,k) {
    string aux = v[i]; 
    int pos = 0, j = 0; 
    while (j < SZ(aux)) {
      char c = aux[j]; 
      if (edge[pos][c] == -1) break; 
      pos = edge[pos][c]; 
      j++; 
    } 

    if (j == SZ(aux)) ans.pb(min_cost[j]);
    else ans.pb(0); 
  } 

  for (auto &x: ans) cout << x << '\n'; 

  return 0;
}

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


int main(){
  FIN;
  
  int n; cin >> n;
  vector<int> v(n); forn(i,n) cin >> v[i];
  vector<int> ans(n,0);
  
  set<int> apariciones;
  apariciones.insert(-1);
  apariciones.insert(n);
  
  multiset<int> intervalos;
  intervalos.insert((n+1));
  int max = *max_element(v.begin(),v.end());
  ans[0] = max;
  
  vector<vector<int>> num_pos(max+1);
  
  forn(i,n) num_pos[v[i]].pb((int)i);
  
  for (int i = 1; i < max+1; i++) {
    forn(j,num_pos[i].size()) {
      apariciones.insert((int)num_pos[i][j]);
      
      // opcion 1:
      //~ auto prev = *(--apariciones.lower_bound((int)i));
      //~ auto beg = apariciones.lower_bound((int)i);
      //~ auto fin = apariciones.upper_bound((int)i);
      //~ dbg(prev,*beg,*fin);
      
      // opcion 2:
      auto it = apariciones.find((int)num_pos[i][j]);
      auto l_it = prev(it);
      auto r_it = next(it);
      
      // actualizacion de intervalos
      int viejo = *r_it - *l_it;
      intervalos.erase(viejo);

      int n1 = *r_it - *it;
      int n2 = *it - *l_it;	
      intervalos.insert(n1);
      intervalos.insert(n2);
    }
    
    for (int j = *intervalos.rbegin()-1; j < n and ans[j] == 0; j++)
      ans[j] = i;
  }
  
  forn(i,n) cout << ans[i] << " ";
  
  
  
  return 0;
}

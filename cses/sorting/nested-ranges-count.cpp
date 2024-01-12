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
#define ii pair<ll,ll>
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

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long ll;

using namespace __gnu_pbds;
using namespace std;

struct tup {
  int x,y,z;
};

bool greaterComp (const tup &a, const tup &b) { // l < l' and r > r'
  if (a.x == b.x) return a.y < b.y; 
  return a.x > b.x; 
}

bool lessComp (const tup &a, const tup &b) { // l > l' and r < r'
  if (a.x == b.x) return a.y > b.y; 
  return a.x < b.x; 
}

typedef tree<ii,null_type,less<ii>,rb_tree_tag,
  tree_order_statistics_node_update> indexed_set;


int main(){
  FIN;
  
  int n; cin >> n;
  vector<tup> v(n); 
  
  //~ v[i].x = start
  //~ v[i].y = end
  //~ v[i].z = original position
  forn(i,n) {
    cin >> v[i].x >> v[i].y;
    v[i].z = i;
  }

  vector<int> a(n); // range "i" contains a[i] ranges
  vector<int> b(n); // range "i" is contained in b[i] ranges
  
  
  // solving for a
  sort(all(v),greaterComp);
  forn(i,n) dbg(v[i].x,v[i].y);
  indexed_set s;
  for (auto p : v) {
    if (s.size())
      a[p.z] = s.order_of_key({p.y,INF});
    s.insert({p.y,p.z});
  }
  s.clear();

  // solving for b
  sort(all(v),lessComp);
  for (auto p : v) {
    if (s.size())
      b[p.z] = s.size() - s.order_of_key({p.y,-1});
    s.insert({p.y,p.z});
  }
  
  forn(i,n) cout << a[i] << ' ';
  cout << endl;
  forn(i,n) cout << b[i] << ' ';
  
  return 0;
}

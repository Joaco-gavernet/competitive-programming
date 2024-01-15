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

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pi pair<ll,ll>
#define f first
#define s second

using namespace __gnu_pbds;
using namespace std;
typedef tree<pi,null_type,less<pi>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


int main(){
  FIN;
  
  ll n, k; cin >> n >> k;
  vector<ll> v(n); forn(i,n) cin >> v[i];
  
  ll tot = n-k+1;
  vector<ll> r;
  
  indexed_set s; 
  forn(i,k) s.insert({v[i],i});
  
  ll i = 0;
  do {
    if (s.size()%2) r.pb((*s.find_by_order(s.size()>>1)).f);
    else r.pb((*s.find_by_order((s.size()>>1)-1)).f);
    s.erase({v[i],i});
    if (i+k < n) s.insert({v[i+k],i+k}); 
    i++;
  } while (i < tot);
  
  forn(j,tot) cout << r[j] << ' ';
  
  return 0;
}

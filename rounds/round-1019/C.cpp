#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int check(vi &a, int k, int ini = 0) {
  const int n = SZ(a); 
  indexed_set st; 
  int ans = n; 
  forr(i,ini,n) {
    st.insert({a[i], i}); 
    if (ans != n and a[i] <= k) return ans; 
    auto ptr = st.find_by_order((SZ(st) -1) /2); 
    if ((*ptr).fst <= k) ans = i; 
    else if (ans != n and (*ptr).fst > k) return ans; 
  } 
  return ans; 
} 

void solve() {
  int n, k; cin >> n >> k; 
  vi a(n); forn(i,n) cin >> a[i]; 
  if (n == 3) {
    int mns = 0; 
    for (auto x: a) if (x <= k) mns++; 
    if (mns >= 2) cout << "YES\n"; 
    else cout << "NO\n"; 
    return; 
  } 

  int pa = check(a,k);
  int pb = check(a,k,pa+1); 

  reverse(all(a)); 
  int rpa = check(a,k); 
  int rpb = check(a,k,rpa+1); 

  bool ok = false; 
  if (pa < n and (pb < n or pa + rpa < n)) ok = true; 
  if (rpa < n and (rpb < n or rpa + pa < n)) ok = true; 

  if (ok) cout << "YES\n"; 
  else cout << "NO\n"; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

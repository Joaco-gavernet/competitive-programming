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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;


int query(vi &a, int l, int r) {
  forr(i,l,r+1) if (a[i] == -1) cout << i+1 << ' ';
  cout << endl; 
  int mad; cin >> mad; 
  return mad; 
} 

void solve() {
  int n; cin >> n; 

  indexed_set st; 
  forn(i,n) st.insert(i); 

  vi a(n, -1); 
  int q = 0, tot = 0;
  while (tot < n and q < 3*n) {
    q++; 

    int l = -1, r = SZ(st); 
    int ref = query(a, 0, n-1); 
    while (l +1 < r) {
      int mid = (l + r) /2; 
      int conv = *st.find_by_order(mid); 
      int ret = query(a, 0, conv); 
      if (ret == ref) r = mid; 
      else l = mid; 
    } 
    r = *st.find_by_order(r); 

    int li = -1, ri = r; 
    while (li +1 < ri) {
      int mid = (li + ri) /2; 
      int conv = *st.find_by_order(mid); 
      int ret = query(a, conv, r); 
      if (ret == ref) li = mid; 
      else ri = mid; 
    } 
    li = *st.find_by_order(li); 

    a[r] = ref; // fix right appearence 
    a[li] = ref; // fix left appearence 
    st.erase(r); 
    st.erase(li); 
    tot += 2; 
  } 

  cout << "! "; 
  for (auto &x: a) {
    if (x == -1) x = 1; 
    cout << x << ' '; 
  }
  cout << endl; 
}


int main(){
  // FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

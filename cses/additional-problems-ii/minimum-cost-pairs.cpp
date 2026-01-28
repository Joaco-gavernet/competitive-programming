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



int main(){
  FIN;

  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 


  const int N = n + 4; 
  const ll INF = 1LL<<60; 

  set<ii> st; 
  vi left(N, -1), right(N, -1); 
  forn(i,N) left[i] = i-1, right[i] = i+1;

  sort(all(a)); 
  vi b(n -1 +4, INF); 
  forn(i,n-1) b[i+2] = a[i+1] - a[i]; 
  forn(i,n-1) st.insert({b[i+2], i+2}); 
  st.insert({INF, 0}); 
  st.insert({INF, 1}); 
  st.insert({INF, n}); 
  st.insert({INF, n+1}); 

  ll tot = 0; 
  vi ans(n/2); 
  forn(k,n/2) {
      assert(SZ(st)); 
      auto [x, id] = *st.begin(); 
      tot += x; 

      st.erase(st.begin()); 
      st.erase({b[left[id]], left[id]}); 
      st.erase({b[right[id]], right[id]}); 
      b[id] = b[left[id]] + b[right[id]] - b[id]; 
      b[left[id]] = b[right[id]] = -1; 
      st.insert({b[id], id}); 

      left[right[right[id]]] = id; 
      right[left[left[id]]] = id; 
      right[id] = right[right[id]]; 
      left[id] = left[left[id]]; 

      ans[k] = tot;
  }

  for (auto x: ans) cout << x << ' '; 
  cout << '\n'; 

  return 0;
}

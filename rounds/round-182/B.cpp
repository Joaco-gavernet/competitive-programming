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

/*
*/

void solve() {
  int n; cin >> n; 
  vector<int> p(n); forn(i,n) cin >> p[i]; 

  // compresion de coordenadas 
  vector<int> todos = p; sort(all(todos)); 
  todos.erase(unique(all(todos)), todos.end()); 
  vi rest; 
  int act = 0; 
  if (todos.front() == 0) act = 1;
  forr(i,1,n+1) {
    if (act < SZ(todos)) {
      if (i != todos[act]) rest.pb(i); 
      else act++; 
    } else rest.pb(i); 
  } 

  vi zero; 
  forn(i,n) if (p[i] == 0) zero.pb(i); 
  if (SZ(zero)) {
    int i = n-1; 
    while (p[i] != 0) i--; 
    p[i] = rest.front(); 
  }

  if (SZ(zero) > 1) {
    int i = 0; 
    while (p[i] != 0) i++; 
    p[i] = rest.back(); 
  } 

  int l = 1<<30, r = -1; 
  forn(i,n) if (p[i] != 0 and p[i] != i+1) {
    l = min(l, min(p[i] -1, int(i)));  
    r = max(r, max(p[i] -1, int(i))); 
  } 
  if (r == -1) r = -1, l = 0; 

  cout << r -l +1 << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

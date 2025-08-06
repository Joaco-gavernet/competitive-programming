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


void solve() {
  int n; cin >> n; 
  deque<ll> p; 
  forn(i,n) {
    ll x; cin >> x; 
    p.pb(x); 
  }
  vi q; 
  string s; 
  int dir = 0; 
  while (SZ(p)) {
    if (dir == 0) {
      if (SZ(s)) {
        if (s.back() < p.front()) dir = -1;  
        else dir = 1; 
      }
      s += 'L'; 
      q.pb(p.front()), p.pop_front(); 
    } else if (dir == -1) {
      if (p.front() < q.back()) s += 'L', q.pb(p.front()), p.pop_front(), dir = 1; 
      else if (p.back() < q.back()) s += 'R', q.pb(p.back()), p.pop_back(), dir = 1; 
      else {
        if (p.front() > p.back()) s += 'L', q.pb(p.front()), p.pop_front(); 
        else s += 'R', q.pb(p.back()), p.pop_back(); 
      } 
    } else if (dir == 1) {
      if (p.front() > q.back()) s += 'L', q.pb(p.front()), p.pop_front(), dir = -1; 
      else if (p.back() > q.back()) s += 'R', q.pb(p.back()), p.pop_back(), dir = -1; 
      else {
        if (p.front() < p.back()) s += 'L', q.pb(p.front()), p.pop_front(); 
        else s += 'R', q.pb(p.back()), p.pop_back(); 
      } 
    } 
  } 

  cout << s << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

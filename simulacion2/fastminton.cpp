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
  
  string seq; cin >> seq;

  pair<int,int> l = {0,0};
  pair<int,int> r = {0,0};    // player<games,points>
  int serves = 0;      // 0 (left) | 1 (right)
  
  for (char u : seq) {
    if (u == 'S') {
      if (serves == 0) {  // serves left
	l.second++;
      } else {            // serves right
	r.second++;
      }
      
    } else if (u == 'R') {
      if (serves == 0) {  // serves left
	r.second++;
	serves = 1;
      } else {            // serves right
	l.second++;
	serves = 0;
      }
      
    } else if (u == 'Q') {
      if (l.first == 2) {
	printf("%d (winner) - %d\n", l.first, r.first);
      } else if (r.first == 2) {
	printf("%d - %d (winner)\n", l.first, r.first);
      } else {
	if (serves == 0)
	  printf("%d (%d*) - %d (%d)\n", l.first, l.second, r.first, r.second);
	else if (serves == 1)
	  printf("%d (%d) - %d (%d*)\n", l.first, l.second, r.first, r.second);	
      }
      
    }
    
    // check if game ended
    if (l.second == 10) {
      l.first++;
      l.second = 0;
      r.second = 0;
    } else if (r.second == 10) {
      r.first++;
      l.second = 0;
      r.second = 0;
    }
    
    if (l.second > 4 and (l.second - r.second) >= 2) {
      l.first++;
      l.second = 0;
      r.second = 0;
    }
    if (r.second > 4 and (r.second - l.second) >= 2) {
      r.first++;
      l.second = 0;
      r.second = 0;
    }
    
  }
  
  
  return 0;
}

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

  int on = 0;
  forn(i,32) if ((1<<i) & n) on++;  

  if (on&1) cout << "NO\n"; 
  else {
    int padd = __builtin_clz(n); 
    int digs = 32 -padd; 
    int tail = 0;
    for (int i = 0; i < 32 and (n&(1<<i)) == 0; i++) tail++;  

    bool ok = true; 
    int l = digs-1, r = tail; 
    while (l >= r) {
      if (bool(n&(1<<l)) != bool(n&(1<<r))) 
        ok = false; 
      l--, r++; 
    } 

    if (ok) cout << "YES\n"; 
    else cout << "NO\n"; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

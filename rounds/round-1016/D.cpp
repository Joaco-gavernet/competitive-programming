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
  int n, q; cin >> n >> q; 

  while (q--) {
    char c; cin >> c; cin >> c; 

    ll x = 0, y = 0, d = 0; 
    if (c == '>') {
      cin >> y >> x; x--, y--; 
      forr(step,1,n) {
        ll lim = (1<<(n-step)); 
        if (x >= lim and y >= lim) d += lim<<1; 
        else if (y >= lim) d += lim<<2;
        else if (x >= lim) d += lim*6; 
        x %= lim, y %= lim;
      } 
      if (x >= 1 and y >= 1) d++; 
      else if (y >= 1) d += 2;
      else if (x >= 1) d += 3; 

      cout << d +1 << '\n'; 
    } else {
      cin >> d; d--; 
      forr(step,1,n) {
        ll aux = d /4; 
        if (aux == 1) x += (1<<(n-step)), y += (1<<(n-step)); 
        else if (aux == 2) y += (1<<(n-step)); 
        else if (aux == 3) x += (1<<(n-step)); 
        d %= 4; 
      } 
      if (d == 1) x++, y++; 
      else if (d == 2) y++; 
      else if (d == 3) x++; 

      cout << y+1 << ' ' << x+1 << '\n'; 
    } 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

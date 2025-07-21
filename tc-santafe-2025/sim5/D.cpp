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

  int n; ll t;
  cin >> n >> t; 
  vi v(n); 
  ll ans = 0, cur = 0; 
  priority_queue<ll> espera; 

  for (ll i = 0; i < n; i++) {
    cin >> v[i]; 
    ll wait = 0; 
    cur++; 
    if (v[i] -i -1 >= 0) espera.push(v[i] -i -1);
    if (SZ(espera)) wait = espera.top(); 
    while (wait +i +1 >= t and SZ(espera) > 0) {
      espera.pop(); cur--; 
      if (SZ(espera)) wait = espera.top(); 
      else wait = 0; 
    } 
    if (wait +i +1 < t) ans = max(ans, cur); 
  } 
  cout << ans << endl; 

  return 0;
}

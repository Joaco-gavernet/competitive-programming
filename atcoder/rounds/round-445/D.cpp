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
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


int main(){
  FIN;

  int H, W, n; cin >> H >> W >> n; 
  vector<ii> v(n), w(n), h(n); 
  forn(i,n) cin >> v[i].ff >> v[i].ss, h[i].ff = v[i].ff, w[i].ff = v[i].ss, h[i].ss = w[i].ss = i; 

  sort(all(w)); 
  sort(all(h)); 
  vb visto(n); 
  vector<ii> ans(n); 
  int x = 0, y = 0; 
  while (SZ(w) or SZ(h)) {
    while (SZ(w) and w.back().ff == W - x) {
      auto [wi, id] = w.back(); 
      if (visto[id] == false) {
        visto[id] = true; 
        ans[id] = {y, x}; 
        y += v[id].ff; 
      } 
      w.pop_back(); 
    } 
    while (SZ(h) and h.back().ff == H - y) {
      auto [hi, id] = h.back(); 
      if (visto[id] == false) {
        visto[id] = true; 
        ans[id] = {y, x}; 
        x += v[id].ss; 
      } 
      h.pop_back(); 
    } 
    while (SZ(h) and visto[h.back().ss]) h.pop_back(); 
    while (SZ(w) and visto[w.back().ss]) w.pop_back(); 
  } 
  for (auto [x, y]: ans) cout << x + 1 << ' ' << y + 1 << '\n'; 

  return 0;
}

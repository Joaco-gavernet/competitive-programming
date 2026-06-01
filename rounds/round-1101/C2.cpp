#include <bits/stdc++.h>
using namespace std;

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
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl



void solve() {
  int n, x, s; cin >> n >> x >> s; 
  string u; cin >> u; 

  auto f = [&](int k) -> ll {
    // fixing first k Ambiverts as Introverts
    string uu = u; 
    for (auto &c : uu) {
      if (c == 'A') {
        if (k) k--, c = 'I';
        else c = 'E'; 
      } 
    }

    vi tab(x); 
    int i = 0, j = 0;
    for (auto c : uu) {
      if (c == 'I' and i < x) {
        tab[i] = 1;
        if (tab[i] == s) j++;
        i++;
      } else if (c == 'E' and j < i) {
        tab[j]++;
        if (tab[j] == s) j++;
      }
    }
    ll tot = accumulate(all(tab), 0LL); 
    return tot; 
  };


  // ternary search 
  int l = 0, r = SZ(u) + 1; 
  while (l + 1 < r) {
    int mid = (l + r) / 2; 
    if (f(mid) < f(mid + 1)) l = mid + 1; 
    else r = mid; 
  } 

  cout << max(f(l), f(r)) << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

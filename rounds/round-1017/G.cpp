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
  int q; cin >> q; 

  ll ans = 0, sum = 0; 
  deque<ll> a, ar; 

  bool r = false; 
  while (q--) {
    int op; cin >> op; 
    if (op == 1) {
      ans += sum;
      if (r) {
        ans -= 1LL * ar.back() * (SZ(a));
        ar.push_front(ar.back()); 
        ar.pop_back(); 
        a.push_back(a.front()); 
        a.pop_front(); 
      } else {
        ans -= 1LL * a.back() * (SZ(a));
        a.push_front(a.back()); 
        a.pop_back(); 
        ar.push_back(ar.front()); 
        ar.pop_front(); 
      } 
    } else if (op == 2) {
      r ^= 1;
      ans = 1LL * sum * (SZ(a) +1) -ans; 
    } else if (op == 3) {
      ll k; cin >> k; 
      if (r) ar.push_back(k), a.push_front(k); 
      else a.push_back(k), ar.push_front(k); 
      ans += 1LL * k *SZ(a); 
      sum += k; 
    } 
    cout << ans << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

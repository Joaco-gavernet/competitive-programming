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
  int n, k; cin >> n >> k;
  map<int,int> mp; 
  vi a(n); 
  forn(i,n) cin >> a[i], mp[a[i]]++; 
  sort(all(a)); 

  while (k--) {
    ll best = 0;
    int next = 0;
    forn(i,n) if (next == a[i]) next++; 
    map<int,int> aux; 
    forn(i,n) {
      if (a[i] > next or mp[a[i]] >= 2) {
        aux[next]++; 
        best = max(best, next -a[i]); 
        a[i] = next; 
      }
    } 
    mp = aux; 
    if (best == 0) break; 
  } 

  ll sum = 0;
  int next = 0; 
  forn(i,n) {
    sum += a[i]; 
    if (next == a[i]) next++; 
  }

  if (k&1 and mp[next-1] > 1) {
    sum -= mp[next-1] *(next -1);
    sum += mp[next-1] *next;
  } 

  cout << sum << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

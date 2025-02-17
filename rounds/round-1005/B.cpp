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
  map<int, int> mp; 
  vi a(n); forn(i,n) cin >> a[i], mp[a[i]]++; 
  vb uni(n, false); 
  forn(i,n) if (mp[a[i]] == 1) uni[i] = true; 

  int al = -1, ar = -1; 
  int l = 0, r = 0; 

  while (r < n and uni[r] == false) r++; 
  if (r < n) l = r++, al = l, ar = r; 

  while (r < n) {
    while (r < n and uni[r]) r++; 
    if (ar -al < r -l) al = l, ar = r; 

    while (r < n and uni[r] == false) r++; 
    if (r < n) l = r++; 
  } 

  if (n == 1) cout << 1 << ' ' << 1 << '\n';
  else if (ar == -1) cout << 0 << '\n';
  else cout << al +1 << ' ' << ar << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

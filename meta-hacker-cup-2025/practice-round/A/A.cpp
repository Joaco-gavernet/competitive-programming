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


void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi b(n); forn(i,n) cin >> b[i]; 
  vi ca = a, cb = b; 

  bool ok = true; 
  forn(i,n) if (b[i] < a[i]) ok = false; 

  sort(all(a)); 
  sort(all(b)); 
  a.erase(unique(all(a)), a.end()); 
  b.erase(unique(all(b)), b.end()); 
  reverse(all(a)); 
  reverse(all(b)); 

  while (SZ(a) and SZ(b) and a.back() <= b.back()) {
    while (SZ(a) and SZ(b) and a.back() < b.back()) a.pop_back(); 
    if (SZ(a) and a.back() == b.back()) a.pop_back(), b.pop_back(); 
  } 
  if (SZ(b)) ok = false; 

  if (ok == false) cout << "-1\n"; 
  else {
    map<int,int> mp;
    forn(i,n) mp[ca[i]] = i;

    vector<pair<ll,ii>> ans; 
    forn(i,n) if (ca[i] < cb[i]) ans.pb({ca[i], {i, mp[cb[i]]}}); 
    sort(all(ans)); 

    cout << SZ(ans) << '\n'; 
    for (auto [k, pr]: ans) cout << pr.ff +1 << ' ' << pr.ss +1 << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  forr(i,1,t+1) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

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

ll query(int typ, int l, int r) {
  cout << typ << ' ' << l+1 << ' ' << r+1 << endl; 
  ll ans; cin >> ans; 
  return ans; 
} 

bool check(int mid) {
  return (query(1,0,mid) == query(2,0,mid));
} 

void solve() {
  int n; cin >> n;

  ll sum = query(2, 0, n-1);  
  ll len = sum -n*(n+1)/2; 

  int l = -1, r = n;
  while (l+1 < r) {
    int mid = (l+r) /2; 
    if (check(mid)) l = mid; 
    else r = mid; 
  }

  r++; 
  cout << "! " << r << ' ' << r+len-1 << endl; 
}


int main(){
  // FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

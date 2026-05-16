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
  int n; cin >> n; 
  ll x; cin >> x; 
  vector<int> v(n); 
  forn(i,n) cin >> v[i]; 

  map<int,int> cnt; 
  forn(i,n) cnt[v[i]]++; 

  forn(i,n) {
    int a = v[i]; 
    if ((x-a != a and cnt[x-a] >= 1) or (x-a == a and cnt[x-a] >= 2)) {
      int ia = -1, ib = -1; 
      forn(j,n) if (v[j] == x-a) ia = j; 
      forn(j,n) if (v[j] == a and j != ia) ib = j; 
      ia++, ib++; 
      cout << ia << ' ' << ib << '\n'; 
      return; 
    } 
  } 
  cout << "-1\n"; 
}


int main(){
  NaN;
  int t = 1; 
  // cin >> t;
  while (t--) solve();
  return 0;
}

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r){ // Random number in [l, r]
  return uniform_int_distribution<int>(l, r)(rng);
}

const int k = 50; 

void solve() {
  int n, q; cin >> n >> q; 
  vector<ii> v; // precompute frequency
  vi a(n); 
  forn(i,n) cin >> a[i], v.pb({a[i], i}); 
  sort(all(v)); 

  while (q--) {
    ll l, r; cin >> l >> r; 
    const int L = r -l +1; 
    const int T = L /3; 
    l--, r--; 

    vi ans;
    forn(_,k) {
      int x = a[my_random(l,r)]; 

      ii ub = make_pair(x, r), lb = make_pair(x, l); 
      int freq = upper_bound(all(v), ub) -lower_bound(all(v), lb);
      if (freq > T and (SZ(ans) == 0 or ans.front() != x and ans.back() != x)) ans.pb(x);
    }
    sort(all(ans)); 

    if (SZ(ans) == 0) cout << "-1\n";  
    else {
      for (auto &x: ans) cout << x << ' '; 
      cout << '\n'; 
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

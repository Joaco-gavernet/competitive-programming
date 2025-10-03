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

bool is_ruinable(int x) {
  int aux = __lg(x +1); 
  return x +1 == (1<<aux);
} 

void solve() {
  int n, q; cin >> n >> q; 
  vi a(n); forn(i,n) cin >> a[i]; 


  vi steps(n); // steps to finish for Poby
  vi ruins(n); // possible one-step ruins for Rekkles 
  vi three(n); 
  forn(i,n) {
    // calc steps 
    steps[i] = __lg(a[i]);
    if (i > 0) steps[i] += steps[i-1];

    // calc ruins 
    ruins[i] = is_ruinable(a[i]); 

    int aux = __lg(a[i]/2 +1); 
    if (a[i]/2 +1 == (1<<aux)) ruins[i]++; 
    if (i > 0) ruins[i] += ruins[i-1]; 

    // calc three
    if (a[i] == 3) three[i] = 1; 
    if (i > 0) three[i] += three[i-1];  
  } 
  dbg(a); 
  dbg(steps); 
  dbg(ruins); 

  while (q--) {
    int l, r; cin >> l >> r; 
    l--, r--; 

    ll tot = steps[r];
    ll ruinable = ruins[r]; 
    ll tres = three[r];  
    if (l > 0) {
      tot -= steps[l-1]; 
      ruinable -= ruins[l-1]; 
      tres -= three[l-1];
    }
    dbg(l, r, tot, ruinable); 
    if (tres) ruinable--; 
    tot += ruinable/2;
    cout << tot << '\n'; 
  } 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

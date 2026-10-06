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


const ll C = 30; 

bool check(vi& cs, vi& ct) {
  ll l = 0, r = C - 1; 
  while (r >= 0 and ct[r] == 0) r--; 

  ll ss = 0, st = 0; 
  forn(i,C) ss += cs[i], st += ct[i]; 

  if (l == r) return (cs[0] == ss and ss < st);
  else return l < r; 
} 

void solve() {
  ll q; cin >> q; 

  vi cs(C), ct(C); 
  cs[0] = ct[0] = 1; 
  while (q--) {
    ll d, k; cin >> d >> k; 
    string x; cin >> x; 

    vi cnt(C); 
    for (auto c : x) cnt[c - 'a']++; 
    forn(i,C) cnt[i] *= k; 

    if (d == 1) forn(i,C) cs[i] += cnt[i]; 
    else forn(i,C) ct[i] += cnt[i]; 

    if (check(cs, ct)) cout << "YES\n";
    else cout << "NO\n"; 
  } 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

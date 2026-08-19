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


const ll MAXN = 2e5+5; 
const ll MOD = 998'244'353; 
vi fact(MAXN); 


void solve() {
  string s; cin >> s; 

  vi v; 
  ll aux = 0; 
  char c = s.back(); 
  while (SZ(s)) {
    if (s.back() == c) {
      c = (c == '0' ? '1' : '0');
      if (aux > 0) v.pb(aux), aux = 0; 
    } else aux++; 
    s.pop_back(); 
  } 
  if (aux > 0) v.pb(aux); 

  ll ops = 0, tot = 1;
  for (auto x : v) ops += x, (tot *= ++x) %= MOD; 
  (tot *= fact[ops]) %= MOD; 
  cout << ops << ' ' << tot << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  fact[0] = fact[1] = 1; 
  forr(i,2,MAXN) fact[i] = (fact[i - 1] * i) % MOD; 
  cin >> t;
  while (t--) solve();
  return 0;
}

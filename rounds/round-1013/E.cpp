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

// const ll MAXN = 1e7+5; 
const ll MAXN = 100; 
vi pref(MAXN, 0); 

vi criba(ll n) {
  vb prime(n+1,true);
  vi primos;
  for(ll p=2; p*p<=n; p++){
    if(!prime[p]) continue;
    int sq = sqrt(p); 
    if (sq*sq != p) sq = -1; 
    dbg(p); 
    pref[p] = 1;
    for(ll i=p*p, j = 0; i<=n; i += p, j++) {
      if (j %2 == 0 or (sq != -1 and prime[i /p])) {
        dbg(p, i);
        pref[i]++; 
      }
      prime[i] = false;
    }
  }
  forn(i,MAXN-1) pref[i+1] += pref[i]; 
  forr(i, 2, n+1) if(prime[i]) primos.pb(i);
  return primos; // lista de primos hasta n
}

void solve() {
  int n; cin >> n; 
  dbg(n); 
  cout << pref[n] << '\n'; 
}


int main(){
  FIN;
  vi crib = criba(MAXN); 
  dbg(pref); 
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef unsigned long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);

// 12345678910111213141516171819202122232425
// 9
// 180
// 2700
// 36000

ll getN(ll number, ll digit) {
  for (ll place = 0; place < digit; place++) 
    number = number / 10;
  return number % 10;
}

int main(){
  FIN;
  const int LIMIT = (int)(19);
  
  vector<ll> pows(LIMIT,1);
  forn(i,LIMIT) {
    forn(j,i) pows[i] *= 10;
  }
  dbg(pows);
  
  vector<ll> intervals;
  forn(i,LIMIT) {
    ll tot = (i-1)*pow(10,i) + (pow(10,i-1)-1)*80/9 + 9;
    intervals.pb(tot);
  }
  dbg(intervals);
  
  int t; cin >> t;
  forn(_,t){
    ll k; cin >> k; // 158888888888888841 -> 6 vs 9
    
    // step 1: find roof of digits (d)
    ll d = 0;
    while (d < LIMIT and intervals[d] < k) d++;
    dbg(d);
    
    // step 2: find number containing our digit
    ll n = pow(10,d)-1 - floor((intervals[d]-k)/d); 
    dbg(n);
    dbg(intervals[d]-k);
    
    // step 3: find mod d (rewrite improper fraction as a mixed fraction)
    ll m = (intervals[d]-k)%d;
    dbg(m);
    
    cout << getN(n,m) << '\n';

    RAYA;
  }
  
  
  return 0;
}

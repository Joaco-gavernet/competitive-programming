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

typedef long long ll;
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
const int MAXN = (int)(2e12+5);


int main(){
  FIN;
  
  ll k,j1,j2,n; cin >> n >> k >> j1;
  ll ka = k;
  
  while (cin >> j2 and ka > 0) {
    dbg(ka,j1,j2);
    if (j1 > j2) ka--;
    else {
      j1 = j2;
      ka = k-1;
    }
    
  }
  
  cout << j1 << "\n"; 
  
  
  
  return 0;
}



  //~ ll n,streak; cin >> n >> streak;


  //~ vector<ll> p(2*n); forn(i,n) cin >> p[i];
  //~ forn(i,n) p[n+i] = p[i];

  //~ ll l = 0;
  //~ ll r = 1;  

  //~ if (streak >= n-1) p[l] = *max_element(p.begin(),p.end());
  //~ else {
    //~ ll k = streak;
    //~ while (k) {
      //~ k = streak;
      //~ while (k and p[l] > p[r]) {
	//~ r++;
	//~ k--;
      //~ }

      //~ if (k) {
	//~ l=r;
	//~ r = l+1;
      //~ }
    //~ }
  //~ }
  
  //~ cout << p[l] << "\n";
  

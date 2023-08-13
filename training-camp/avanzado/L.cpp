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
const int MAXN = (int)(2e5+5);


int main(){
  FIN;
  
  ll n; cin >> n;
  vector<pair<ll,ll>> v;
  
  ll t,s,act;
  ll tot = n;             // variable to count repetitions
  forn(i,n) {
    cin >> t >> s;
    if (t == 2) {
      tot--;
      t = -1;
    }
    
    forn(j,s) {
      cin >> act;
      v.pb({act,t});
    }
  }

  sort(v.begin(),v.end());
  dbg(tot,v);
  
  ll reference = v[0].first;
  ll answer = 0;
  ll i = 0, reps = 0;
  while (i < (ll)v.size()) {
    if (v[i].second == -1) {
      while (i < (ll)v.size() and reference == v[i].first) i++;
      if (i == (ll)v.size()) i--;
      reference = v[i].first;
    } else {
      if (reps == 0) reps = 1;
      if (v[i].first == reference) reps++;
      else {
	reference = v[i].first;
	reps = 0;
      }
    }
    
    if (reps == tot) answer++;
    dbg(i,reference,reps,answer);
    i++;
  }
  cout << answer << "\n";
  
  return 0;
}

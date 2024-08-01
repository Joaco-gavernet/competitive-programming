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

class Compare {
  public: 
    bool operator() (pair<ll,int> a, pair<ll,int> b) {
      return a.first > b.first;
    }
};

int main(){
  FIN;
  
  int t; cin >> t;
  while (t--) {
    int h,n; cin >> h >> n;
    ll total = 0;
    vector<int> damage(n); forn(i,n) cin >> damage[i], total += damage[i];
    vector<ll> cooldown(n); forn(i,n) cin >> cooldown[i];

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,Compare> pq;
    forn(i,n) {
      dbg(i, cooldown[i] +1);
      pq.push({cooldown[i] +1,i});
    }

    dbg(h,total);
    if (h <= total) cout << "1\n";
    else {
      h -= total;
      pair<ll,int> act;
      while (h > 0) {
        act = pq.top(); pq.pop();
        // dbg(act);
        h -= damage[act.second];
        if (h <= 0) break;

        pq.push({act.first +cooldown[act.second], act.second});
        // RAYA;
      }

      cout << act.first << endl;
    }
  }
  
  
  return 0;
}

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


#define a q[i].first 
#define b q[i].second 

int main(){
  FIN;
  
  int n,m; cin >> n >> m;
  vector<int> v(n);
  vector<int> arr(n+1); // arr[2] = 5 means "2" is in index "5"
  
  forn(i,n) {
    cin >> v[i];
    arr[v[i]] = i + 1;
  }
  
  vector<pair<int,int>> q(m);
  forn(i,m) cin >> a >> b;
  
  int rounds = 1;
  forr(num,2,n+1) if (arr[num] < arr[num-1]) rounds++;
  
  forn(i,m) {
    int act = 0;
    // conditions of previous state before swapping
    if (v[a-1] > 1 and arr[v[a-1]] < arr[v[a-1]-1]) act--;
    if (v[b-1] > 1 and arr[v[b-1]] < arr[v[b-1]-1]) act--;
    if (v[a-1] < n and arr[v[a-1]+1] != arr[v[b-1]] and arr[v[a-1]+1] < arr[v[a-1]]) act--;
    if (v[b-1] < n and arr[v[b-1]+1] != arr[v[a-1]] and arr[v[b-1]+1] < arr[v[b-1]]) act--;
    
    // swapping corresponding indexes
    swap(v[a-1],v[b-1]);
    swap(arr[v[a-1]],arr[v[b-1]]);

    // conditions of resulting state after swapping
    if (v[a-1] > 1 and arr[v[a-1]] < arr[v[a-1]-1]) act++;
    if (v[b-1] > 1 and arr[v[b-1]] < arr[v[b-1]-1]) act++;
    if (v[a-1] < n and arr[v[a-1]+1] != arr[v[b-1]] and arr[v[a-1]+1] < arr[v[a-1]]) act++;
    if (v[b-1] < n and arr[v[b-1]+1] != arr[v[a-1]] and arr[v[b-1]+1] < arr[v[b-1]]) act++;
    
    rounds += act; // act manifests the difference between both states
    
    cout << rounds << '\n';
  }
  
  
  return 0;
}

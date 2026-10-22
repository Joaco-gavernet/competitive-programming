#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

using ll = long long; 
using vi = vector<ll>; 
using vb = vector<bool>; 
using ii = pair<ll,ll>; 
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define ff first
#define ss second 



int main(){  
  NaN;
  
  int n, d, b; cin >> n >> d >> b; 
  vi x(n), c(n); 
  forn(i,n) cin >> x[i] >> c[i]; 
  x.pb(d);
  c.pb(0); 
  n++; 
  
  ll tot = 0, prev = 0; 
  priority_queue<ii> pq; 
  forn(i,n) {
    ll dist = x[i] - prev; 
    if (dist > b) {
      while (SZ(pq) and dist > b) b += pq.top().ff, pq.pop(), tot++; 
      if (dist > b) {
        cout << -1 << '\n'; 
        return 0; 
      } 
    } 
    b -= dist; 
    prev = x[i]; 
    if (b >= 0 and x[i] == d) break; 
    pq.push({c[i], x[i]}); 
  } 
  cout << tot << '\n'; 
  
  return 0;
}

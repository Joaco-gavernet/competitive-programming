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
#define RAYA cerr << "======================\n" 

// Description: Fenwick Tree (BIT) for range queries and point updates
// Time: O(log n) for both queries and updates
// Usage: BIT bit(v); bit.query(l,r); bit.update(pos,val);
struct BIT {
  vector <ll> prefix, a;
  BIT(vector <ll> &v) {
    int n = v.size(); prefix.resize(n+1); a = v;
    vector <ll> aux(n+1,0);
    forn(i,n) aux[i+1] = aux[i] + v[i];
    forr(i,1,n+1) prefix[i] = aux[i] - aux[i - (i&(-i))];
  }
  ll query(int l, int r) { //[a,b] 0-indexed
    ll ans = 0; r++;
    while(r) ans += prefix[r], r -= r&(-r);
    while(l) ans -= prefix[l], l -= l&(-l);
    return ans;
  }
  void update(int pos, ll val) {
    int i = pos + 1; ll upd = val - a[pos];
    while(i < SZ(prefix)) prefix[i] += upd, i += i&(-i);
    a[pos] = val;
  }
};

vi calc(vi& p) {
  const int n = SZ(p); 
  vi pl(n); 
  
  // Reuse your BIT as a frequency counter
  vi zeros(n + 1, 0);
  BIT freq(zeros);
  
  forn(i,n) {
    // query sum of frequencies strictly greater than p[i]
    pl[i] = freq.query(p[i] + 1, n); 
    // mark p[i] as seen (frequency changes from 0 to 1)
    freq.update(p[i], 1); 
  } 
  return pl; 
} 

int main(){  
  NaN;

  int n, q; cin >> n >> q; 
  vi p(n); forn(i,n) cin >> p[i];  

  // preprocessing 
  vi lef = calc(p); 
  reverse(all(p)); forn(i,n) p[i] = (n + 1) - p[i]; 

  vi rig = calc(p); 
  reverse(all(rig)); 
  reverse(all(p)); forn(i,n) p[i] = (n + 1) - p[i]; 
  BIT flef(lef), frig(rig); 

  vi g(n); 
  forn(i,n) {
    if (i > 0) g[i] = g[i - 1]; 
    ll add = (n - 1 - i) - rig[i]; 
    ll res = i - lef[i]; 
    g[i] += add - res; 
  }

  forn(_,q) {
    int t; cin >> t;
    if (t == 1) {
      int i; cin >> i; i--; 
      ll x = p[i], y = p[i + 1]; 

      ll j = i + 1; 
      ll xi = lef[i]; 
      ll xj = lef[j]; 
      ll yi = rig[i]; 
      ll yj = rig[j]; 

      lef[i] = xj - (x > y); 
      lef[j] = xi + (x < y); 
      rig[i] = yj + (x < y); 
      rig[j] = yi - (x > y); 
      flef.update(i, lef[i]); 
      flef.update(j, lef[j]); 
      frig.update(i, rig[i]); 
      frig.update(j, rig[j]); 

      g[i] += x - y; 
      swap(p[i], p[i + 1]); 

    } else {
      int k; cin >> k; k--; 
      if (k == -1) cout << flef.query(0, n - 1) << '\n'; 
      else cout << flef.query(0, k) + frig.query(k + 1, n - 1) + g[k] << '\n'; 
    } 
  } 

  return 0;
}

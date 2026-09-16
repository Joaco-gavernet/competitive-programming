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
#define esta(x,v) ((v).find(x) != (v).end()) 


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

void solve() {
  int n; cin >> n; 
  vi a(n); forn(i,n) cin >> a[i]; 
  vi p(n); forn(i,n) cin >> p[i], p[i]--; 
  reverse(all(p)); 

  vi base(n); 
  BIT fenwick(base); 

  set<ll> s = {p[0]}; 
  fenwick.update(p[0], a[p[0]]); 
  vi ans(n); 

  forr(i,1,n) {
    auto it = s.upper_bound(p[i]); 
    if (it == s.begin()) s.insert(p[i]); 
    else {
      it--; 
      ll ch = fenwick.query(*it, p[i]); 
      if (ch < a[p[i]]) s.insert(p[i]);
    } 

    // update forefeits set 
    fenwick.update(p[i], a[p[i]]); 
    ll j; 
    if (esta(p[i], s)) j = p[i]; 
    else j = *(--s.lower_bound(p[i])); 
    it = s.upper_bound(j); 
    while (it != s.end() and fenwick.query(j, *it - 1) >= a[*it]) {
      s.erase(it); 
      it = s.upper_bound(j); 
    } 
    ans[i] = SZ(s) - 1; 
  } 

  reverse(all(ans)); 
  for (auto x : ans) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  NaN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

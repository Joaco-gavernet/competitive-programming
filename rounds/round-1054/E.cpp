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


void solve() {
  ll n, k, l, r;
  cin >> n >> k >> l >> r; 
  vi a(n); forn(i,n) cin >> a[i]; 

  // next different vector
  int dif = 0; 
  vi next(n, -1); 
  map<int,int> cont; 
  forn(i,n) { 
    if (cont[a[i]] == 0 and dif == k) {
      for (int j = i; j >= 0 and next[j] == -1; j--) next[j] = i; 
    }

    if (i -k >= 0) {
      if (cont[a[i-k]] == 1) dif--; 
      cont[a[i-k]]--; 
    }
    if (cont[a[i]] == 0) dif++; 
    cont[a[i]]++; 
  } 
  for (int i = n-1; i >= 0 and next[i] == -1; i--) next[i] = n; 
  dbg(next); 

  ///////////////////////////// solution ///////////////////////
  dif = 0;
  map<int,int> mp; 
  ll tot = 0;
  dbg(a); 
  forn(i,n) { 
    if (i -k >= 0) {
      if (mp[a[i-k]] == 1) dif--; 
      mp[a[i-k]]--; 
    }
    if (mp[a[i]] == 0) dif++; 
    mp[a[i]]++; 

    if (dif == k) {
      dbg(i, tot); 

      int top = min(r, next[i]); 
      int aux = l - k; 
      tot += i -k +1;
      tot += min(next[i], r -k) -(l-k);
    } 
  } 

  cout << tot << '\n'; 
  RAYA; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

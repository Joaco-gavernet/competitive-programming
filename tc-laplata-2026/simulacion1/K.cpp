/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())


const int MAXN = 5e3+5; 
vi memo(MAXN, -1); 

ll mex(vi& v) {
  // find mex of a vector 
  vi h(SZ(v) + 1); 
  for (auto x : v) if (x < SZ(h)) h[x] = 1; 
  forn(i, SZ(h)) if (h[i] == 0) return i;  
  assert(false); 
  return -1; 
} 

ll g(int x) {
  // find grundy of a path 
  if (memo[x] > -1) return memo[x]; 
  vi ops; 
  forr(i, 1, (x + 1) / 2 + 1) {
    ll lef = max(0LL, i - 2); 
    ll rig = max(0LL, x - i - 1);
    ops.pb(g(lef) ^ g(rig)); 
  } 
  return memo[x] = mex(ops); 
} 

int main(){  
  FIN;

  string s; cin >> s; 
  s += '#'; 
  const int n = SZ(s); 
  memo[0] = 0;
  memo[1] = 1;
  memo[2] = 1;

  // transform this problem into: node kayle problem 
  vi paths; 
  int act = 0; 
  forr(i,1,n-1) {
    if (s[i - 1] == s[i + 1]) act++; 
    else {
      if (act > 0) paths.pb(act); 
      act = 0; 
    } 
  } 

  int S = 0; 
  for (auto x : paths) S ^= g(x);  
  if (S == 0) cout << "Second\n";
  else {
    cout << "First\n"; 

    forr(j,1,n-1) {
      if (s[j - 1] == s[j + 1]) act++; 
      else {
        if (act > 0) {
          // check if win is possible from this range 
          ll A = S ^ g(act); 

          forr(i, 1, (act + 1) / 2 + 1) {
            ll lef = max(0LL, i - 2); 
            ll rig = max(0LL, act - i - 1);
            if ((A ^ g(lef) ^ g(rig)) == 0) {
              cout << j - act + i << '\n'; 
              return 0;
            } 
          } 
        } 
        act = 0; 
      } 
    } 

    assert(false); 
  } 

  return 0;
}

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
#define ff first
#define ss second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl


int main(){
  FIN;

  string s; cin >> s; 
  const int n = SZ(s); 
  map<char,int> mp; 
  for (auto c: s) {
      mp[c]++; 
      if (mp[c] > n/2 +(n %2)) {
          cout << "-1\n";
          return 0; 
      }    
  }
  vector<pair<char,int>> prs; 
  for (auto [k, v]: mp) prs.pb({k, v}); 
  sort(all(prs)); 
  reverse(all(prs)); 
  dbg(prs); 

  string ans = "";
  pair<char, int> a = prs.back(); prs.pop_back(); 
  pair<char, int> b = {-1, -1}; 
  if (SZ(prs)) b = prs.back(), prs.pop_back(); 
  dbg(a, b); 
  ans += a.ff, a.ss--; 
  if (a.ss == 0) a = b, b = {-1,-1}; 
  if (b.ff == -1 and SZ(prs)) b = prs.back(), prs.pop_back(); 
  while (b.ss != -1) {
      dbg(ans); 
      dbg(a, b); 
      if (ans.back() == a.ff) {
          ans += b.ff, b.ss--; 
          if (b.ss == 0) b = {-1,-1}; 
          if (b.ff == -1 and SZ(prs)) b = prs.back(), prs.pop_back(); 
      } else {
          ans += a.ff, a.ss--; 
          if (a.ss == 0) a = b, b = {-1,-1}; 
          if (b.ff == -1 and SZ(prs)) b = prs.back(), prs.pop_back(); 
      }
  }
  dbg(a); 
  cout << ans << '\n'; 


  return 0;
}

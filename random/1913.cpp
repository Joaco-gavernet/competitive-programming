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


void solve() {
  string s; cin >> s; 
  int cnt[2]; 
  for (char c: s) cnt[c - '0']++; 

  if (cnt[0] == cnt[1]) cout << "0\n"; 
  else {
    reverse(all(s)); 
    int tot = 0;
    if (cnt[0] < cnt[1]) {
      for (int i = 0; i < SZ(s) and cnt[0] < cnt[1]; i++) {
        tot++; 
        if (s[i] == '0') tot++; 
        else cnt[1]--; 
      } 
      tot += cnt[1]; 
    } else {
      for (int i = 0; i < SZ(s) and cnt[1] < cnt[0]; i++) {
        tot++; 
        if (s[i] == '1') tot++; 
        else cnt[0]--; 
      } 
      tot += cnt[0]; 
    } 
    cout << tot << '\n'; 
  } 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

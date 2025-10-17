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
#define esta(v,x) (v).find(x) != (v).end() 
#define RAYA cerr << "===============================" << endl


int check(vector<vi> &who) {
  const int n = SZ(who); 
  set<int> st; 
  int pos = -1, cand = -1; 
  forn(i,n) {
    int j = 0;
    for (; j < SZ(who[i]) and who[i][j] > 0; j++) {
      int x = who[i][j]; 
      st.insert(x); 
    }
    if (esta(st, cand)) return i-1;
    else cand = -1;
    if (SZ(st) == 1) cand = *st.begin(); 
    for (; j < SZ(who[i]); j++) {
      int x = who[i][j]; 
      st.erase(-x); 
    }
  } 
  return pos; 
} 

void solve() {
  int n, m; cin >> n >> m;

  vi evt(n);
  vector<vi> who(n); 
  forn(i,m) {
    int l, r; cin >> l >> r; 
    evt[--l]++; 
    who[l].pb(i+1);
    if (r < n) evt[r]--;
    who[r-1].pb(-(i+1));
  } 
  forr(i,1,n) evt[i] += evt[i-1]; 
  int mx = *max_element(all(evt));

  vi ans(n); 
  forn(i,n) ans[i] = i; 
  forn(i,n) sort(all(who[i])), reverse(all(who[i])); 

  if (mx == m) {
    forn(i,n) if (evt[i] == mx) {
      swap(ans[0], ans[i]);
      break; 
    } 
  } else {
    int pos = check(who); 
    forn(i,n) {
      forn(j,SZ(who[i])) who[i][j] *= -1; 
      reverse(all(who[i])); 
    }
    reverse(all(who)); 
    int poss = check(who); 
    if (poss > -1) poss = n -1 -poss; 

    if (pos > -1) {
      swap(ans[1], ans[pos+1]); 
      swap(ans[0], ans[pos]); 
    } else if (poss > -1) {
      swap(ans[0], ans[poss]); 
      swap(ans[1], ans[poss-1]); 
    } 

    if (pos == -1 and poss == -1) swap(ans[1], ans[n-1]); 
  } 

  for (auto &x: ans) cout << x << ' ';
  cout << '\n'; 
}


int main(){
  FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

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

int query_base(int n) {
  cout << "? "; 
  cout << n << ' '; 
  forr(i,1,n+1) cout << i << ' '; 
  cout << endl; 
  int ans; cin >> ans; 
  return ans; 
} 

int query(int a, int b, int left, int right) {
  cout << "? "; 
  cout << "6 ";
  cout << left +1 << ' '; 
  cout << left +1 << ' '; 
  cout << a +1 << ' '; 
  cout << right +1 << ' '; 
  cout << left +1 << ' '; 
  cout << b +1 << endl; 
  int ans; cin >> ans; 
  return ans; 
} 

void solve() {
  int n; cin >> n; 

  int left = -1, right = -1; 
  // left = index of some '(' 
  // right = index of some ')' 

  if (query_base(n) == 0) left = n-1, right = 0;  
  else {
    // binsearch for base brackets '(' and ')' 
    int l = 0, r = n; 
    while (l + 1 < r) {
      int mid = (l + r) /2; 
      if (query_base(mid)) r = mid;
      else l = mid; 
    } 
    left = l -1, right = r -1; 
  }

  // find rest of brackets 
  string ans(n,'x'); 
  ans[left] = '('; 
  ans[right] = ')'; 

  int a = -1, b = -1; 
  forn(i,n) {
    if (ans[i] == 'x') {
      if (a == -1) a = i; 
      else b = i; 
    } 
    if (a != -1 and b != -1) {
      int aux = query(a, b, left, right); 
      if (aux == 1) ans[a] = '(', ans[b] = '('; 
      if (aux == 2) ans[a] = ')', ans[b] = '('; 
      if (aux == 3) ans[a] = '(', ans[b] = ')'; 
      if (aux == 4) ans[a] = ')', ans[b] = ')'; 
      a = b = -1; 
    } 
  } 
  if (a != -1) {
    int aux = query(a, left, left, right); 
    if (aux == 1) ans[a] = '('; 
    else ans[a] = ')'; 
  } 
  cout << "! " << ans << endl; 
}


int main(){
  // FIN;
  int t = 1; 
  cin >> t;
  while (t--) solve();
  return 0;
}

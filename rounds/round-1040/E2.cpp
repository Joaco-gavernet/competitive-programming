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

const int N = 6; 
map<int, string> mp; 
vi formula = {
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 2, 
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 2, 0, 1, 0, 1, 0, 1,
  0, 1, 0, 1, 0, 1, 0, 1, 0, 1,
  0, 2, 0, 0, 1, 0, 1, 0, 1, 0,
  2, 0, 0, 1, 0, 2, 0, 0, 2
};

int query(vi &op, int left, int right) {
  int i = 0;
  cout << "? " << SZ(formula) << ' '; 
  for (auto &x: formula) {
    if (x == 0) cout << left +1 << ' '; 
    else if (x == 1) cout << right +1 << ' '; 
    else cout << op[i++] +1 << ' ' ;
  } 
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
  // dbg(left, right); 

  // find rest of brackets 
  string ans(n,'x'); 
  ans[left] = '('; 
  ans[right] = ')'; 

  vi acc; 
  forn(i,n) {
    if (ans[i] == 'x') acc.pb(i); 
    if (SZ(acc) == N) {
      int aux = query(acc, left, right); 
      string str = mp[aux]; 
      forn(i,N) {
        if (str[i] == '0') ans[acc[i]] = '('; 
        else ans[acc[i]] = ')'; 
      } 

      acc.clear(); 
    } 
  } 
  if (SZ(acc)) {
    int valid = SZ(acc); 
    while (SZ(acc) < N) acc.pb(left); 
    int aux = query(acc, left, right); 
    string str = mp[aux]; 
    forn(i,valid) {
      if (str[i] == '0') ans[acc[i]] = '('; 
      else ans[acc[i]] = ')'; 
    } 
  } 
  cout << "! " << ans << endl; 
}

void init() {
  mp = {
    {707, "000000"}, {708, "000001"}, {709, "000010"}, {710, "000011"}, {711, "000100"}, {712, "000101"}, {713, "000110"}, {714, "000111"},
    {716, "001000"}, {717, "001001"}, {718, "001010"}, {719, "001011"}, {720, "001100"}, {721, "001101"}, {722, "001110"}, {723, "001111"},
    {860, "010000"}, {861, "010001"}, {862, "010010"}, {863, "010011"}, {864, "010100"}, {865, "010101"}, {866, "010110"}, {867, "010111"},
    {886, "011000"}, {887, "011001"}, {888, "011010"}, {889, "011011"}, {890, "011100"}, {891, "011101"}, {892, "011110"}, {893, "011111"},
    {1268, "100000"}, {1269, "100001"}, {1270, "100010"}, {1271, "100011"}, {1272, "100100"}, {1273, "100101"}, {1274, "100110"}, {1275, "100111"},
    {1277, "101000"}, {1278, "101001"}, {1279, "101010"}, {1280, "101011"}, {1281, "101100"}, {1282, "101101"}, {1283, "101110"}, {1284, "101111"},
    {1718, "110000"}, {1719, "110001"}, {1720, "110010"}, {1721, "110011"}, {1722, "110100"}, {1723, "110101"}, {1724, "110110"}, {1725, "110111"},
    {1777, "111000"}, {1778, "111001"}, {1779, "111010"}, {1780, "111011"}, {1781, "111100"}, {1782, "111101"}, {1783, "111110"}, {1784, "111111"}
  };
} 

int main(){
  // FIN;
  int t = 1; 
  cin >> t;
  init(); 
  while (t--) solve();
  return 0;
}

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


bool vowel(char c) {
  return c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U'; 
} 

bool gas(string s) {
  string base = "GAS"; 
  base = s[0] + base + s[0]; 
  if (vowel(s[0]) == false) return false; 
  if (s[0] != s.back()) return false; 
  return s == base; 
} 

int main(){  
  NaN;
  
  string s; cin >> s; 
  const int n = SZ(s); 

  set<string> st; 
  forn(i,n-4) if (gas(s.substr(i,5))) {
    string aux = s.substr(0, i) + s.substr(i + 4, n - (i + 4));
    st.insert(aux); 
  } 

  if (SZ(st) == 0) cout << "-\n";
  else if (SZ(st) > 1) cout << "+\n";
  else cout << *st.begin() << '\n'; 
  
  return 0;
}

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
#define RAYA cerr << "=======================\n" 


bool alldig(string s) {
  for (char c : s) if (c < '0' or '9' < c) return false;
  return true; 
} 

bool z4(string s) {
  ll i = SZ(s) - 1, tot = 0; 
  while (i >= 0 and s[i] == '0') i--, tot++; 
  return tot >= 4; 
} 

bool pow10(string s) {
  if (s[0] != '1') return false; 
  forr(i,1,SZ(s)) if (s[i] != '0') return false;
  return true; 
} 

string cut(string s) {
  while (SZ(s) and s.back() == '0') s.pop_back(); 
  string ans; 
  ans += s[0]; 
  if (SZ(s) > 1) ans += "." + s.substr(1, SZ(s) - 1); 
  return ans; 
} 

int main(){  
  NaN;
  
  int n; cin >> n; 
  vector<string> s(n); 

  string aux; 
  getline(cin, aux); 
  forn(i,n) getline(cin, s[i]); 

  vector<string> ans(n); 
  forn(i,n) {
    stringstream ss(s[i]); 
    string word; 
    while (ss >> word) {
      if (alldig(word) and z4(word)) {
        string aux = ""; 
        if (pow10(word)) aux = "10^{" + to_string(SZ(word) - 1) + "}"; 
        else aux = cut(word) + "\\cdot10^{" + to_string(SZ(word) - 1) + "}"; 
        word = aux; 
      } 
      if (SZ(ans[i])) ans[i] += ' '; 
      ans[i] += word; 
    } 
  } 

  for (auto s : ans) cout << s << '\n'; 

  return 0;
}

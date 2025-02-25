#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) v.find(x) != v.end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

bool check(string &s) {
  ll tot = 0; 
  int prod = 10; 
  for(char c : s) {
    if (c == '-') continue; 
    if (c == 'X') tot += 10; 
    else tot += int(c -'0')*prod;
    prod--; 
  }
  // DBG(tot); 
  if (tot %11 == 0) return true; 
  else return false; 
}

bool check_guion(string &s) {
  ll tot = 0; 
  for (char c : s) if (c == '-') tot++; 
  if (SZ(s) -tot != 10) return false; 
  forn(i,SZ(s)-1) {
    if (s[i] == '-' and s[i+1] == '-') return false; 
    if (s[i] == 'X') return false; 
  }
  if (tot > 3) return false; 
  if (tot == 3 and s[SZ(s)-2] != '-') return false; 
  else if (*s.begin() == '-' or *s.rbegin() == '-') return false; 
  else return true; 
}

void solve() {
  string s; cin >> s; 
  if (check(s) == false or check_guion(s) == false) {
    cout << "invalid\n"; 
    return; 
  }
  string ans = "978-";
  ll cont = 38; 
  int prod = 3; 
  forn(i,SZ(s)-1) {
    char c = s[i]; 
    ans += c; 
    if (c == '-') continue;
    cont += int(c -'0') *prod;
    if (prod == 1) prod = 3; 
    else prod = 1; 
  }
  // DBG(cont); 
  if (cont %10 == 0) ans += '0'; 
  else ans += char(10 -cont %10 +'0'); 
  cout << ans << '\n'; 
}


int main() {
  FIN; 

  int t; cin >> t; 
  while (t--) {
    solve(); 
    // RAYA; 
  }


  return 0;
}

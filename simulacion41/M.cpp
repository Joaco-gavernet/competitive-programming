#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"


int main() {
  FIN; 
  
  string s; cin >> s;
  map<char, string> t;
  t['O'] = ".-.-";
  t['K'] = ".-";
  
  string ans = "";
  for (char c: s) 
    ans += t[c]; 
  cout << ans << '\n'; 
  
  
  return 0; 
} 

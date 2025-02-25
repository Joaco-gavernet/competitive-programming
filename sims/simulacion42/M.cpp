#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++) 
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '
#define RAYA cerr << "==============================\n"


char vocals[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
bool is_vocal(char c) {
  bool ans = false;
  for(char x: vocals) if (c == x) {
    ans = true;
    break;
  }
  return ans; 
}

void to_low(string &s) {
  for (char &c: s) {
    if (c == '-') continue;
    if (c <= 'Z') c += 'a'-'A';
  }
}

int main() {
  FIN; 
  
  string a; cin >> a; 
  string b; cin >> b; 
  const int n = SZ(a); 
  const int m = SZ(b); 
  
  // convert all to lowercase 
  to_low(a); 
  to_low(b); 
  //~ DBG(a);
  //~ DBG(b); 
  int j=0;
  forn(i,m){
    if(j<n and a[j]==b[i]){j++; continue;}
    if(is_vocal(b[i])) continue;
    cout << "Different\n";
    return 0;
  }
  
  if (j != n) cout << "Different\n";
  else cout << "Same\n";
  
  
  return 0; 
} 










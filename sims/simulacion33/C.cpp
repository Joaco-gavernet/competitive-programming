#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "======================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '



int main() {
  FIN; 

  int n; cin >> n; 
  string s; cin >> s; 
  for (int i = n-1; i >= 0; i--) {
    if (i >= 2 and s[i-2] == '1') {
      s[i] = s[i-1] = 'x'; 
      i = i-2; 
    }
    if (i >= 1 and s[i-1] == '1') {
      s[i] = 'x'; 
      i--; 
    }
  }
  // DBG(s); 
  ll tot = 0; 
  for (auto c: s) if (c != '0') tot++; 
  cout << tot << '\n'; 


  return 0;
}

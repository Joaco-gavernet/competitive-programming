#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=============================\n"



int main() {
  FIN;

  int n; cin >> n; 
  string a, b; cin >> a >> b; 

  int i = 0;
  string ans = "";
  while (i < n) {
    if (a[i] == '/') {
      if ((i +1 < n and a[i+1] == '.') or i == n-1) ans += 'v';
      else {
        i++;
        while (i < n and a[i] != '/') i++;
        i++;
        ans += 'w'; 
      }
    }
    i++; 
  }
  cout << ans << '\n'; 
  

  return 0; 
}
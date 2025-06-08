#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"

int main() {
  FIN;

  unsigned t0, t1; 
  t0 = clock(); 

  int MAXN = 1e9; 
  int x = 1; 
  
  forn(i,MAXN) x %= 2; 
  t1 = clock(); 
  double time = (double(t1-t0) /CLOCKS_PER_SEC);
  DBG(time); 

  return 0; 
}
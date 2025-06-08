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

  int n; cin >> n; 
  map<int,int> stones; 
  forn(i,n) {
    int x; cin >> x;
    stones[x]++; 
  }

  int i = 1;
  while (true) {
    if (stones[i] == 0) break; 
    i++; 
  }

  if (i %2 or n == 1) cout << "Alicius\n"; 
  else cout << "Bobius\n";


  return 0; 
}
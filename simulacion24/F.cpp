#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"




int main() {
  FIN; 

  vi a(5); forn(i,5) cin >> a[i];
  map<int,int> b; 
  forn(i,4) {
    int x; cin >> x;
    b[x]++; 
  }
  for (int x : a) {
    if (b[x] == 0) {
      cout << x << endl;
      return 0; 
    }
  }

  return 0;
}
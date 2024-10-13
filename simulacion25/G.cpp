#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n" 


int main() {
  FIN; 
  int n;
  cin >> n;
  forn(i,75) cout << "1 1000\n";
  forn(i,50) cout << 2+i << " " << 999-i << "\n";
  forn(i,n-125) cout << "1 1\n";
  cout << "\n";
  forn(i,74) cout << "1 1000\n";
  cout << "500 1000\n";
  forn(i,50) cout << 2+i << " " << 999-i << "\n";
  forn(i,n-125) cout << "1 1\n";
  cout << "\n";
  return 0;
}

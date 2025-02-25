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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"


int main() {
  FIN; 

  vi karound(5); 
  vi klong(5); 
  forn(i,5) {
    cin >> karound[i]; 
    cin >> klong[i]; 
  }
  ll n, k; cin >> n >> k;  

  ll tot = 0; 
  forn(i,5) tot += karound[i]*klong[i];
  tot /= 5; 

  cout << (tot*n) /k << endl; 


  return 0;
}

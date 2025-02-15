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


int main() {
  FIN;
  int n; cin >> n;
  vi v(n), g(n);
  forn(i,n) cin >> v[i];
  forn(i,n) cin >> g[i];
  int mini=n, maxi=0, j=0;
  forn(i,n) if(g[j]<v[i]) {maxi++; j++;}
  j=0;
  forn(i,n) if(g[i]>v[j]) {mini--; j++;}
  cout << maxi-mini+1 << "\n";
  forr(i,mini,maxi+1) cout << i << " ";
  
  return 0; 
} 

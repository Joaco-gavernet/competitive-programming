#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define forr(i,a,b) for (int i = a; i < b; i++)  
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back 
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=================================\n" 




int main() {
  int n, m; cin >> n >> m; 
  ll tot = 0; 
  vi s(n), p(n);
  forn(i,n) cin >> s[i] >> p[i], tot += p[i]; 

  vi tr(n); 
  forr(i,1,n) {
    tr[i] = tr[i-1]; 
    if (s[i-1] == -1) tr[i]++; 
  }
  forn(i,n) cerr << tr[i] << ' ';
  cerr << endl;


  return 0; 
} 

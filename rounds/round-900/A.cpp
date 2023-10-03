#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
#define forr(i,a,n) for (ll i=a; i<n; i++)
#define forn(i,n) forr(i,0,n)

int main() {
  
  int t,n,k,aux;

  
  cin >> t;
  forn(_,t) {
    cin >> n >> k;
    
    unordered_map<int,bool> v; 
    forn(i,n) cin >> aux, v.insert({aux,1});
    (v[k] == true) ? cout << "YES\n" : cout << "NO\n";
  }
  
  return 0;
}

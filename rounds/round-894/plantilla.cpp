#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forr(i,a,b) for(ll i=(a);i<(ll)(b);i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl 

int main() {
  FIN;

  ll t; cin >> t;
  ll n,m;
  
  forn(_,t) {
    cin >> n >> m;
    vector<string> tab(n); 
    vector<map<char,int>> v(m); 

    forn(i,n) {
      cin >> tab[i]; 
      forn(j,m) v[j][tab[i][j]]++; 
    }
    string check = "vika"; 

    for (int i = m - 1; i >= 0; i--) {
      if (v[i][check.back()] > 0) check.pop_back(); 
      if (SZ(check) == 0) break; 
    } 

    if (SZ(check) == 0) cout << "YES\n";
    else cout << "NO\n"; 
  }


  return 0;
}

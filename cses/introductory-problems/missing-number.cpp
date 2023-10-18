#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forr(i,a,b) for (ll i = a; i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)

int main() {
  
  int n,a; cin >> n;
  map<int,bool> s;
  
  while (cin >> a) s.insert({a,1});  
  for (int i = 1; i <= n; i++) if (s[i] == 0) cout << i;
  
  return 0;
}

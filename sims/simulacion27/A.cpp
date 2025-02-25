#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
  FIN; 

  int n; cin >> n; 
  string s; cin >> s; 
  ll ans = 0, i = 0; 
  while (i < n) {
    ll aux = 0; 
    while (i < n and s[i] == 'a') {
      aux++; 
      i++; 
    }
    if (aux > 1) ans += aux; 
    i++; 
  }
  cout << ans << endl; 

  return 0; 
}

#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main() {
  FIN; 
  
  int n; cin >> n;
  long long ans = 1LL<<60;
  
  for (int i = 0; i < n; i++) {
    long long a, b; cin >> a >> b;
    ans = min(ans, b/a);
  }
  
  cout << ans << endl;
  
  return 0;
}

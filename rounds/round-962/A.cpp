#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << (n/4) + (n%4)/2 << '\n';
  }
  return 0;
}

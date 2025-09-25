#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;

  string z = "hello";
  int i = 0;
  for (char c: s) {
    if (c == z[i]) i++;
  }
  if (i == 5) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}

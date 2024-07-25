#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n,x; cin >> n >> x;
  set s{x};
  int ans = 1;

  for (int i = 0; i < n; i++) {
    int a; cin >> a;

    for (int y: s) {
      if (y % a) continue;
      if (y == a) {
	ans++;
	s = {x, x/a};
	break;
      }
      s.emplace(y/a);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t; while (t--) solve();
}

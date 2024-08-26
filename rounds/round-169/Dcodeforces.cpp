#include <bits/stdc++.h>
using namespace std;

// checkout how using const is useful somehow to improve clarity
bool intersect(const string &a, const string &b) {
  string out;
  ranges::set_intersection(a, b, back_inserter(out));
  return out.size();
}

void run() {
  int n, q; cin >> n >> q;
  vector<string> s(n); for (auto &x : s) cin >> x;
  map<string, set<int>> m; for (int i = 0; i < n; i++) m[s[i]].emplace(i);

  while (q--) {
    int x, y; cin >> x >> y; x--, y--;
    if (x > y) swap(x, y);
    if (intersect(s[x], s[y])) {
      cout << y - x << '\n';
      continue;
    }

    int ans = 1e9;
    for (auto &[k, v] : m) {
      if (k == s[x] or k == s[y]) continue; // jumps if the same kind
      auto it = v.lower_bound(x); // super cool way of solving 
      if (it != v.end()) ans = min(ans, *it -x); // note that *it > y because already filtered in intersect
      if (it != v.begin()) {
        it--;
        ans = min(ans, y - *it);
      }
    }
    if (ans > y-x and ans != 1e9) {
      ans = 2 * (ans- (y-x)) + y-x; // counts the distance twice   x----------------y=======k
    }
    ans = max(ans, y-x); // to check????
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t; while (t--) run();
}

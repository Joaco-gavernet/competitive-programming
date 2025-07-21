#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(arg) cout << "[" << #arg << "]: " << arg << endl
#else
#define debug(arg) 42
#endif

#define all(n) begin(n), end(n)

struct Test {
	int x, y, z;
	vector<int> a, b, c;

	Test(int x, int y, int z, vector<int> a, vector<int> b, vector<int> c) : x(x), y(y), z(z), a(all(a)), b(all(b)), c(all(c)) {}
};

// Test a{2, 3, 1, {1}, {}, {}};
// Test a;
// 
//
// seq.pb({2, 3, 1, {1}, {}, {}});
// seq.emplace_back(2, 3, 1, {1}, {}, {});

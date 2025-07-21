#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(arg) cout << "[" << #arg << "]: " << arg << endl
#else
#define debug(arg) 42
#endif

using llu = unsigned long long;
using ll = long long;
using lf = double;

#define vec vector
#define pb push_back
#define all(n) begin(n), end(n)

struct Tree {
	int n;
	vec<ll> s;
	Tree(int n) : n(n), s(2*n) {}

	void add(int x, ll v) {
		for (s[x += n] += v; x >>= 1;) s[x] = gcd(s[x<<1], s[x<<1|1]);
	}

	int get(int l, int r) {
		int ans = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) ans = gcd(ans, s[l++]);
			if (r&1) ans = gcd(ans, s[--r]);
		}
		return ans;
	}
};

const int MX = 4e5;

int criba[MX + 1];

void solv() {
	int n, q; cin >> n >> q;
	vec<ll> A(n); for (auto &i : A) cin >> i;
	vec<ll> a(n);
	Tree tree(n);
	map<int, int> fish;
	fish.insert({n - 1, n});
	tree.add(n - 1, n);

	auto join = [&](auto itl, auto itr) {
		debug("join");
		itr->second += itl->second;
		tree.add(itl->first, -itl->second);
		tree.add(itr->first, itl->second);
		fish.erase(itl);
	};

	auto split = [&](auto it, int p) {
		debug("split");
		int cnt = it->second - (it->first - p);
		it->second -= cnt;
		tree.add(it->first, -cnt);
		tree.add(p, cnt);
		auto r = fish.insert({p, cnt});
		return r.first;
	};

	auto fuck = [&](int x) {
		if (!x) return llu(n);
		map<int, int> bully;
		while (criba[x]) bully[criba[x]]++, x /= criba[x];
		if (x != 1) bully[x]++;
		llu prod = 1;
		for (auto &[_, c] : bully) prod *= (c + 1);
		return prod;
	};

	auto process = [&](int p, ll v) {
		auto it = fish.lower_bound(p);
		// PRIORIDAD: siempre desconectarse primero
		if (a[p] < v) {
			// Crece
			// desconectarse con el siguiente
			if (p < n - 1 && a[p] <= a[p + 1] && v > a[p + 1]) it = split(it, p);
			// conectarse con el anterior
			if (p && a[p - 1] > a[p] && a[p - 1] <= v) join(prev(it), it);
		} else if (a[p] > v) {
			// Decrece
			// desconectarse con el anterior
			if (p && a[p - 1] <= a[p] && a[p - 1] > v) split(it, p - 1);
			// conectarse con el siguiente
			if (p < n - 1 && a[p] > a[p + 1] && v <= a[p + 1]) join(it, next(it));
		}
		a[p] = v;
	};

	for (int i = 0; i < n; ++i) process(i, A[i]);

	int ans = fuck(tree.get(0, n - 1));

	cout << ans << '\n';
	while (q--) {
		int p; ll v; cin >> p >> v, --p;
		process(p, v);
		ans = fuck(tree.get(0, n - 1));
		cout << ans << '\n';
	}
}

int main() {
	for (llu i = 2; i <= MX; ++i) if (!criba[i]) for (llu j = i*i; j <= MX; j += i) criba[j] = i;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solv();
	return 0;
}

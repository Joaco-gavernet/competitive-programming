#include <bits/stdc++.h>
#include <stdio.h>

#define FIN std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0)
#define forn(i, n) for(int i=0;i<n;i++)

using namespace std;

int n, k;
vector<int> a;

bool good(double x) {
    int s = 0;
    forn(i,n) {
        s += floor(a[i]/x);
    }
    return s >= k;
}

int main() {
    FIN;

    cin >> n >> k;
    a.resize(n);
    forn(i,n) cin >> a[i];

    double l = 0;      // good(l) = 1
    double r = 1e8;    // good(r) = 0
    cout << setprecision(20);

    forn(i, 100) {
        double m = (l + r) / 2;
        cerr << i << ": " << good(m) << " " << m << '\n';

        if (good(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';

    return 0;
}

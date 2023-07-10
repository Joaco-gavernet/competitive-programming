#include <bits/stdc++.h>
#include <stdio.h>

#define FIN std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0)
#define forn(i, n) for(int i=0;i<n;i++)

using namespace std;

int n, x, y;

bool enoughCopies(int t) {
    t -= min(x, y);
    if (t<0) return false;
    return (t/x + t/y + 1) >= n;
}

int main() {
    FIN;

    cout << setprecision(20);
    cin >> n >> x >> y;

    int l = 0;
    int r = numeric_limits<int>::max();

    if (n != 0) {
        forn(i, 100) {
            cerr << i<< " " << l << " " << r << '\n';
            int m = (l + r)/2;
            if (enoughCopies(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r;
    } else {
        cout << 0;
    }

    return 0;
}

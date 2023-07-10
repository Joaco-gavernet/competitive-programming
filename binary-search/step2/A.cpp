#include <bits/stdc++.h>
#include <stdio.h>

#define FIN std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0)

using namespace std;

long long w, h, n;

bool f(long long x) {
    return ((x/w) * (x/h)) >= n;
}

int main() {
    FIN;

    cin >> w >> h >> n;

    long long l = 0;        // f(l) = 0
    long long r = 1;        // f(r) = 1

    while (f(r) == 0) r *= 2;

    while (r > l + 1) {
        long long m = (l + r) / 2;
        if (f(m) == 0) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r;

    return 0;
}

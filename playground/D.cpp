#include <bits/stdc++.h>
#include <stdio.h>

#define FIN std::ios::sync_with_stdio(0);std::cin.tie(0);std::cout.tie(0)
#define forn(i, n) for(int i=0;i<n;i++)

using namespace std;

int m, n;
vector< vector<int> > a;
vector<int> results;

bool good(int x) {
    int t,z,y;
    int total = 0;
    results.resize(n);

    forn(i,n) {
        t = a[i][0];
        z = a[i][1];
        y = a[i][2];
        int cont = 0;

        forn(j,x) {
            if (t != 0) {
                t--;
                if (t == 0) {
                    cont++; // ballon finished
                    if (x == 6) cout << "j " << j << " cont: " << cont << "\n";
                }
            } else {
                if (cont % z == 0) {
                    y--;
                    if (y == 0) {
                        t = a[i][0];
                        y = a[i][2];
                    }
                }
            }
        }
        results[i] = cont;
        total += cont;
    }

    return total >= m;
}

int main() {

    cin >> m >> n;
    a.resize(n);

    forn (i,n) {
        a[i].resize(3);
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    int l = 0;
    int r = 1e5;

    forn (i, 60) {
        int middle = (l + r) / 2;
        cerr << l << " " << r << "\n";
        if (good(middle)) {
            r = middle;
        } else {
            l = middle;
        }
    }

    cout << r << "\n";
    forn(i, n) cout << results[i] << " ";

    return 0;
}

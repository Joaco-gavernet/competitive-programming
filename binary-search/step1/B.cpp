#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int maximumIndexNotGreaterThan(int n, vector<int>& arr, int i, int j) {
    if (i > j) return -1; // Return -1 when no index is found
    else {
        int mid = i + ((j - i) / 2);

        if (arr[mid] <= n) {
            int result = maximumIndexNotGreaterThan(n, arr, mid + 1, j);
            return (result != -1) ? result : mid; // Return result if found, otherwise return mid
        } else {
            return maximumIndexNotGreaterThan(n, arr, i, mid - 1);
        }
    }
}

int main() {
    FIN;

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> queries(k);

    forn(i, n) cin >> arr[i];
    forn(i, k) cin >> queries[i];

    forn(i, k) cout << 1 + maximumIndexNotGreaterThan(queries[i], arr, 0, n - 1) << " ";

    return 0;
}

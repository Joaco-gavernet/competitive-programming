#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

int binarySearch(int n, int arr[], int i, int j) {
    int result = 0;
    if (i > j) return 0;

    int aux = i + ((j - i) / 2);

    if (arr[aux] == n) return 1;
    else if (arr[aux] < n) return binarySearch(n, arr, aux + 1, j);
    else return binarySearch(n, arr, i, aux - 1);
}

int main(){
    FIN;

    int n, k;
    cin >> n >> k;
    int arr[n];
    int queries[k];
    forn(i, n) cin >> arr[i];
    forn(i, k) cin >> queries[i];

    forn(i, k) cout << (binarySearch(queries[i], arr, 0, n - 1) ? "YES\n" : "NO\n");

    return 0;
}

// Fast search
#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i=0;i<n;i++)
#define FIN ios::sync_with_stdilso(0);cin.tie(0);cout.tie(0)

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    forn(i,n) cin >> a[i];
    sort(a.begin(), a.end());

    int k;
    cin >> k;

    vector< pair<int,int> > queries(k);
    forn(i, k)
        cin >> queries[i].first >> queries[i].second;

    forn(i, k) {
        pair<int,int> query = make_pair(queries[i].first, queries[i].second);

        int l = -1;  // a[l] < query.first
        int r = n;   // a[r] => query.second
        int tot = 1;

        while (r > l + 1) {
            int m = (l + r) / 2;
            if (a[m] < query.first) {
                l = m;
            } else {
                r = m;
            }
        }
        tot += l;

        l = -1;      // a[l] <= query.second
        r = n;       // a[r] > query.second

        while (r > l + 1) {
            int m = (l + r) / 2;
            if (a[m] <= query.second) {
                l = m;
            } else {
                r = m;
            }
        }
        tot = r - tot;
        cout << tot << " ";
    }

    return 0;
}

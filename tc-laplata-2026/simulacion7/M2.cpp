#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"


int find(vi& a, ll x) {
    int l = 0, r = SZ(a); 
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (x + 1 <= a[mid]) r = mid;
        else l = mid; 
    }
    return r; 
}

int main() {
    FIN;

    int n; cin >> n;
    vi a(n); forn(i,n) cin >> a[i]; 
    sort(all(a)); 

    vi suf(n); 
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) suf[i] = suf[i + 1] + a[i]; 
    for (auto x : suf) cout << x << ' ';
    cout << '\n'; 

    ll tot = 0;
    forn(i,n) {
        int j = find(a, a[i]);
        cout << i << ' ' << j << '\n';
        tot += suf[j] - (n - j) * a[i]; 
    }
    cout << tot << '\n'; 

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n"


void solve() {
    int n, k; cin >> n >> k;
    vi a(n); forn(i,n) cin >> a[i]; 

    const ll INF = 1LL<<60; 
    vector<vi> dp(k + 2, vi(3, -INF)); 
    // dp[moves][phase] = 
    // phase = where is the core answer? 
    // moves = how many of the k's operations were used? 

    dp[0][0] = 0;
    forn(i,n) {
        vector<vi> nxt(k + 2, vi(3, -INF)); 
        forr(moves,0,k+1) {
            // phase 0: core has not started 
            nxt[moves][0] = max(nxt[moves][0], dp[moves][0]); // ignore 
            nxt[moves][1] = max(nxt[moves][1], dp[moves][0] + a[i]); // start core 
            nxt[moves + 1][0] = max(nxt[moves + 1][0], dp[moves][0] + a[i]); // import to future core 

            // phase 1: currently inside the core 
            nxt[moves][1] = max(nxt[moves][1], dp[moves][1] + a[i]); // keep 
            nxt[moves][2] = max(nxt[moves][2], dp[moves][1]); // finish + ignore 
            nxt[moves + 1][1] = max(nxt[moves + 1][1], dp[moves][1]); // remove 
            nxt[moves + 1][2] = max(nxt[moves + 1][2], dp[moves][1] + a[i]); // finish + import 

            // phase 2: core has already ended 
            nxt[moves][2] = max(nxt[moves][2], dp[moves][2]); 
            nxt[moves + 1][2] = max(nxt[moves + 1][2], dp[moves][2] + a[i]); 
        }
        dp = nxt; 
    }
    ll mx = *max_element(all(a)); 
    forr(i,0,k+1) mx = max(mx, max(dp[i][1], dp[i][2])); 
    cout << mx << '\n';
} 

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
}

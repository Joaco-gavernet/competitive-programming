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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"


int main() {
    FIN;

    int n; cin >> n;
    vi v(3); forn(i,3) cin >> v[i];
    sort(all(v));
    vi dp(n + 1);
    for (auto x : v) {
        if (x > n) break;
        dp[x] = max(dp[x], 1LL); 
        forn(i, n + 1) {
            if (i - x >= 0 and dp[i - x] > 0)
                dp[i] = max(dp[i], dp[i - x] + 1);
        }
    }
    cout << dp[n] << '\n';

    return 0;
}
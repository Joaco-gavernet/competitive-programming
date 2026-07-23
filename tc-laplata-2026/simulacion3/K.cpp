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
    vi b(n); forn(i,n) cin >> b[i]; 

    ll sum = 0, mx = 0, best = 0;
    forn(i,min(n,k)) {
        sum += a[i];
        mx = max(mx, b[i]); 
        best = max(best, sum + (k - i - 1) * mx); 
    }
    cout << best << '\n';
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}
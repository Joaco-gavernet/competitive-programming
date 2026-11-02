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
#define RAYA cerr << "=========================\n"



void solve() {
    string s; cin >> s;
    ll n = stoi(s);
    ll sz = SZ(s);

    vi ans; 
    ll x = n;
    forr(i, 0, sz + 1) {
        if (x >= n + i and (x - n - i) % sz == 0) {
            if (i + (x - n - i) / sz * sz != 0) 
                ans.pb(i + (x - n - i) / sz * sz); 
        }
        ll d = x % 10; 
        x /= 10; 
        forn(i,sz-1) d *= 10;
        x += d; 
    }
    cout << SZ(ans) << '\n';
    sort(all(ans)); 
    for (auto x : ans) cout << x << ' ';
    cout << '\n'; 
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
}
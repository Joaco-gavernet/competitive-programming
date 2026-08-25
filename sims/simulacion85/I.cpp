#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using vi = vector<ll>; 
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

const ll INF = 1LL<<60; 

void solve() {
    int n; cin >> n;
    vi a(n); forn(i,n) cin >> a[i]; 
    vi x; 
    forn(i,n) {
        ll aux = INF; 
        if (a[i] != 1) {
            ll den = a[i] - 1;
            ll num = a[i];
            aux = (num + den - (den / abs(den))) / den; 
        }
        x.pb(aux);
    }
    
    for (auto z : a) cout << z << ' ';
    cout << '\n';
    for (auto z : x) cout << z << ' ';
    cout << '\n';
    RAYA; 

    ll tot = 0;
    indexed_set ops; 
    for (int i = n - 1; i >= 0; i--) {
        ll y = a[i]; 
        ll l = -1, r = SZ(ops); 
        while (l + 1 < r) {
            ll mid = (l + r) / 2;
            ll val = *ops.find_by_order(mid);
            if (y < val) r = mid;
            else l = mid; 
        }
        // for (auto z : ops) cout << z << ' ';
        // cout << '\n';
        cerr << y << ' ' << SZ(ops) - r << '\n'; 
        tot += SZ(ops) - r;
        if (a[i] == 0 or a[i] == 1) tot--; 
        ops.insert(x[i]);
    }
    cout << tot << '\n';
    RAYA; 
    RAYA; 
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}
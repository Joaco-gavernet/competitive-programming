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
    ll z = 0, o = 0, g = 0, neg = 0; 
    vi a(n); 
    forn(i,n) {
        cin >> a[i]; 
        z += a[i] == 0;
        o += a[i] == 1;
        g += a[i] > 1; 
        neg += a[i] < 0; 
    } 
    // cerr << z << ' ' << o << ' ' << g << ' ' << neg << '\n'; 

    ll tot = z * (o + g) + o * g + (o * (o - 1)) / 2 + neg * (o + g); 
    cout << tot << '\n';
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}
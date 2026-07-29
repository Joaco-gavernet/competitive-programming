#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
 #include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
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

using i128 = __int128_t; 

typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

// void print128(i128 x) {
//     string ans = "";
//     while (x > 0) {
//         ans += '0' + (x % 10); 
//         x /= 10;
//     }
//     cout << ans << '\n';
// }

i128 solve(vector<i128> &v){
    indexed_set s1, s2;
    i128 ans = 0;
    ll n = SZ(v);
    forn(i,n) {
        s1.insert({v[i],i}); s2.insert({-v[i],i});
        ll u=int(s1.order_of_key(*s1.lower_bound({v[i]-1,-1})));
        ll w=int(s2.order_of_key(*s2.lower_bound({-v[i]-1,-1})));
        ans+=v[i]*(u+w);
    }
    return ans;
}

int main() {
    FIN;
    ll n; cin >> n;
    vi v(n);
    forn(i,n) cin >> v[i];
    vector<i128> V(n); 
    forn(i,n) V[i] = i128(v[i]);

    i128 ans = solve(v);
    reverse(all(v));
    ans-=solve(v);
    cout << ans << "\n";
    return 0;
}

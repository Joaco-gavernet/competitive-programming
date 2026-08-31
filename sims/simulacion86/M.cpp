#include <bits/stdc++.h> 
#include <ext/pb_ds/assoc_container.hpp>
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
#define DBG(x) cerr << #x <<  " = " << x << endl
#define RAYA cerr << "==================\n"


typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

ll calc(deque<ll>& p) {
    const int n = SZ(p); 
    ll tot = 0;
    indexed_set st; 
    for (int i = n - 1; i >= 0; i--) {
        st.insert(p[i]);
        tot += st.order_of_key(p[i]); 
    }
    return tot;
}

int main() {
    FIN;

    int n, m; cin >> n >> m;
    deque<ll> p(n); forn(i,n) cin >> p[i];
    string ops; cin >> ops;

    ll tot = 0, aux = 0;
    tot = calc(p);
    reverse(all(p));
    aux = calc(p);
    reverse(all(p)); 

    cout << tot << '\n';

    vi ans(m);
    forn(i,m) {
        auto c = ops[i];
        if (c == 'R') swap(tot, aux), reverse(all(p)); 
        else {
            int x = p.front(); 
            p.pop_front();
            ll diff = (n - x) - (x - 1);
            p.push_back(x); 
            tot += diff, aux -= diff; 
        }
        ans[i] = (tot % 10);
    }

    for (auto x : ans) cout << x;
    cout << '\n'; 


    return 0; 
}
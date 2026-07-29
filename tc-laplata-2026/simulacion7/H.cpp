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

struct evt {
    int op;
    string name; 
};

int main() {
    FIN;

    int n, m; cin >> n >> m;
    
    vector<evt> v(n);
    forn(i,n) {
        int op; cin >> op;
        string s = "#"; 
        if (op == 2) cin >> s;
        v[i] = {op, s};
    }

    reverse(all(v)); 
    ll tot = 0;
    map<string, ll> mp; 
    ll mx = 0;
    for (auto [op, name]: v) {
        // cout << op << ' ' << name << '\n'; 
        if (op == 2) {
            mp[name]++;
            mx = max(mx, mp[name]); 
        } else {
            tot += mx; 
            mx = 0;
            mp.clear(); 
        }
    }
    cout << tot << '\n'; 

    return 0;
}
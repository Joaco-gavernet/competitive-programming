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

using tipo = ll; 
struct punto {
    tipo x, y; 
    punto const operator - (const punto& p) const { return {x - p.x, y - p.y}; }
    punto const operator + (const punto& p) const { return {x + p.x, y + p.y}; }
    tipo operator * (const punto& p) const { return x * p.x + y * p.y; }
    tipo operator ^ (const punto& p) const { return x * p.y - y * p.x; }
};

ostream &operator << (ostream& os, const punto& p) {
    return os << "(" << p.x << ',' << p.y << ")"; 
}

bool f(punto& a, punto& b, punto& c) {
    punto p = b - a;
    punto q = c - b; 
    return (p ^ q) < 0; 
}

void solve() {
    int n; cin >> n;
    vector<punto> v(n); forn(i,n) cin >> v[i].x >> v[i].y; 

    ll l = 0, r = 2, best = 0; 
    while (r < n) {
        while (l + 1 < r and (
            !f(v[r - 2], v[r - 1], v[r]) 
            or !f(v[r], v[l], v[l + 1]) 
            or !f(v[r - 1], v[r], v[l])
        )) l++; 
        if (r - l + 1 >= 3 
            and f(v[r - 2], v[r - 1], v[r]) 
            and f(v[r], v[l], v[l + 1]) 
            and f(v[r - 1], v[r], v[l])) 
                best = max(best, r - l + 1); 
        r++; 
    }
    cout << best << '\n';
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
}
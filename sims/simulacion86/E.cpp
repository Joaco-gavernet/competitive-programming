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
#define DBG(x) cerr << #x <<  " = " << x << endl
#define RAYA cerr << "==================\n"

ii extendedEuclid(ll a, ll b) {
    ll x, y;
    if (b == 0) return {1, 0};
    auto p = extendedEuclid(b, a % b); 
    x = p.ss, y = p.ff - (a / b) * x; 
    if (a * x + b * y == - __gcd(a, b)) x = -x, y = -y; 
    return {x, y};
}

void solve(){
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if(x1==x2 or y1==y2) {cout << x1+1 << " " << y1+1 << "\n"; return;}
    ll a=y1-y2, b=x1-x2, g=__gcd(a,b), c=x1*y2-y1*x2;
    ii p=extendedEuclid(a,b);
    cout << x1+p.ff << " " << (a*(x1+p.ff)+c-g)/b << "\n";

}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0; 
}
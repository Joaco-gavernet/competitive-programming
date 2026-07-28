#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i = a, jet = b; i < jet; i++)
#define SZ(x) int((x).size())
#define ALL(x) x.begin(), x.end()
#define mset(a,v) memset((a), (v), sizeof(a))
#define NCG ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;

const string ids = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void solve() {
    ll r, c, k; cin >> r >> c >> k; 
    vector<string> tab(r); fore(i,0,r) cin >> tab[i];
    vector<vv> M(r, vv(c)); 
    ll R = 0;
    fore(y,0,r) fore(x,0,c) M[y][x] = (tab[y][x] == 'R'), R += M[y][x];
    
    vector<ii> cords;
    fore(y,0,r) {
        if ((y&1) == 0)
            for (ll x = 0; x < c; x++) cords.pb({y, x});
        else
            for (ll x = c-1; x >= 0; x--) cords.pb({y, x});
    }

    ll piso = R / k, rem = R % k, chk = 0, rice = 0;
    vector<vv> ans(r, vv(c));
    fore(i, 0, r * c) {
        auto [y, x] = cords[i]; 
        if (M[y][x] and piso + (chk < rem) == rice) chk++, rice = 0;
        rice += M[y][x];
        ans[y][x] = chk;
    }

    for (auto row : ans) {
        for (auto x : row) cout << ids[x]; 
        cout << '\n';
    }
}

int main() {
    NCG;
    int t; cin >> t;
    while (t--) solve(); 
    return 0;
}
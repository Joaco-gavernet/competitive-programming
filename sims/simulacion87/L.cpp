#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
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

// if (SZ(a) == 0 or SZ(b) == 0) {
//     if (SZ(a) == 0 and SZ(b) == 0) win[2] += esp;
//     else if (SZ(a) == 0) win[player^1] += esp;
//     else if (SZ(b) == 0) win[player] += esp; 
//     return;
// }

using ld = long double; 

vector<ld> win(3); 
void f(int player, deque<ii> a, deque<ii> b, ld esp) {

    auto [HP, ATK] = a.front(); a.pop_front();
    forn(i,SZ(b)) {
        deque<ii> c = b;
        HP -= c[i].ss; 
        c[i].ff -= ATK; 
        if (c[i].ff <= 0) c.erase(c.begin() + i); 

        if (HP > 0) a.pb({HP, ATK}); 
        if (SZ(c) > 0 and SZ(a) > 0) {
            ld nesp = esp / SZ(b); 
            f(player ^ 1, c, a, nesp); 
        } else {
            if (SZ(a) > 0) win[player] += esp / SZ(b); 
            else if (SZ(c) > 0) win[player ^ 1] += esp / SZ(b); 
            else win[2] += esp / SZ(b); 
        }
        if (HP > 0) a.pop_back(); 
        HP += b[i].ss; 
    }
}

int main() {
    FIN; 

    int n, m; cin >> n >> m; 
    deque<ii> a(n); forn(i,n) cin >> a[i].ff, a[i].ss = a[i].ff;
    deque<ii> b(m); forn(i,m) cin >> b[i].ff, b[i].ss = b[i].ff; 

    if (n > m) f(0,a,b,1.0);
    else if (n < m) f(1,b,a,1.0);
    else f(0,a,b,0.5), f(1,b,a,0.5);

    cout << fixed << setprecision(10); 
    for (auto x : win) cout << x << '\n';

    return 0; 
}
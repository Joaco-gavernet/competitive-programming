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
#define RAYA cerr << "============================\n"


int main() {
    FIN;

    int n; cin >> n; 
    vi f(n); forn(i,n) cin >> f[i], f[i]--;
    vi s(n); forn(i,n) cin >> s[i], s[i]--; 

    vi ans, in(2 * n), off(2 * n);  
    forn(i,n) ans.pb(i), in[f[i]]++; 
    
    vi zero; 
    forr(i,n,2*n) if (in[i] == 0) zero.pb(i);
    while (SZ(zero) > 0) {
        auto i = zero.back();
        zero.pop_back(); 
        ans.pb(i); 
        if (off[s[i - n]] == false) {
            off[s[i - n]] = true; 
            if (--in[f[s[i - n]]] == 0) zero.pb(f[s[i - n]]);
        }
    }

    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end()); 
    for (auto x : ans) if (off[x] == false) cout << x + 1 << ' ';
    cout << '\n'; 


    return 0; 
}
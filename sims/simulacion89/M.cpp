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

void solve() {
    int n; cin >> n; 
    string s; cin >> s;

    int tot = 0; 
    forr(i,1,n-1) {
        if (s[i - 1] == '1' and s[i] == '1' and s[i + 1] == '1') {
            tot = 1;
            s[i - 1] = s[i] = s[i + 1] = '0'; 
            break;
        }
    }
    if (tot == 0) {
        forr(i,0,n-1) {
            if (s[i] == '1' and s[i + 1] == '1') {
                tot = 1;
                s[i] = s[i + 1] = '0'; 
                break;
            }
        }
    }
    forn(i,n) tot += s[i] == '1'; 
    cout << tot << '\n'; 
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
}
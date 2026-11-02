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
    string s; cin >> s;
    ll ans=1, n=SZ(s);
    vi h(26);
    forn(i,n){
        ll j=i;
        while(s[j]==s[i]) j++;
        h[s[i]-'a']+=j-i;
        ans+=j-i-(j-i)*(j-i+1)/2;
        i=j-1;
    }
    forn(i,26) ans+=h[i]*(h[i]+1)/2;
    cout << ans << "\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
}
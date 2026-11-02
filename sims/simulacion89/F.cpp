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
    int n, x=0; cin >> n;
    map <string,int> m;
    m["xxx"]=2; m["xx."]=1; m[".xx"]=1;
    forn(i,n){
        string s; cin >> s;
        x^=m[s.substr(0,3)]; x^=m[s.substr(3,3)];
    }
    if(x==0) cout << "Polycarp\n";
    else cout << "Monocarp\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve();
    return 0; 
}
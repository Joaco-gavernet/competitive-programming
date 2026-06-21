#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ss second
#define ff first
#define DBG(x) cerr << #x << " = " << x <<endl
#define RAYA cerr << "======================\n"

void solve(){
    
    int n; cin >> n;
    vector <int> v(n);
    forn(i,n) cin >> v[i];

    while(true) {
        string op;
        cin >> op;
        if(op == "?") {
            int x;
            cin >> x;
            int maxi = 0;
            forn(i,n) {
                int aux = v[i]^x;
                maxi = max(maxi,aux);
            }
            cout << maxi << " " << (maxi^x) << endl;
        }
    }

    return;
}

int main() {
    FIN;
    ll t = 1;
    // ll t; cin>>t;
    while(t--) solve();
    return 0;
}
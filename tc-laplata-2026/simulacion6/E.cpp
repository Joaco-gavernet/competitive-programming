#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

void solve(){
    ll n; cin >> n;
    vi v(n);
    forn(i,n){
        ll x; cin >> x; x--;
        v[x]++;
    }
    ll ans=0;
    forn(i,n){
        if(v[i]>0) ans+=v[i]*(v[i]-1)*(v[i]-2)/6;
        if(i<n-1) ans+=v[i]*v[i+1]*(v[i+1]-1)/2+v[i+1]*v[i]*(v[i]-1)/2;
        if(i<n-2){
            ans+=v[i]*v[i+2]*(v[i+2]-1)/2+v[i+2]*v[i]*(v[i]-1)/2;
            ans+=v[i]*v[i+1]*v[i+2];
        }
    }
    cout << ans << "\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();

    return 0;
}
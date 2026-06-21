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
    int n, q; cin >> q >> n;
    vii v(n);
    forn(i,n) cin >> v[i].ff >> v[i].ss;
    sort(all(v));
    set <ii> s;
    forn(i,n) s.insert({v[i].ss,i});
    int cont=0, j=0;
    while(SZ(s)>0){
        ii p=*s.begin();
        cont++;
        while(j<n and v[j].ff<=p.ff) {s.erase({v[j].ss,j}); j++;}
    }
    int ans=1, k=1;
    while(k<cont){
        ans++;
        k=k*2+1;
    }
    cout << ans << "\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
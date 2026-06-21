#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
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

pair <bool, int> cal(vi &v){
    int n=SZ(v);
    sort(all(v));
    bool b=false;
    int p=0;
    forn(i,n){
        if(v[i]%2==0) p++;
        if(i+1<n and v[i]==v[i+1]-1) b=true;
    }
    return {b,p};
}

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    forn(i,n) cin >> a[i];
    forn(i,n) cin >> b[i];
    pair <bool,int> x=cal(a), y=cal(b);
    if(x!=y) cout << "No\n";
    else if(x.ff) cout << "Yes\n";
    else if(a==b) cout << "Yes\n";
    else  cout << "No\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
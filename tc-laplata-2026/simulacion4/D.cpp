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
#define RAYA cerr << "================================\n"

void solve(){
    int n; cin >> n;
    vi a(n), b(n);
    forn(i,n) cin >> a[i];
    reverse(all(a));
    forn(i,n) cin >> b[i];
    ll tot=0;
    forn(i,n){
        if(a[i]==2) a[i]=-1;
        if(b[i]==2) b[i]=-1;
        tot+=a[i]; tot+=b[i];
    }
    if(tot==0){cout << "0\n"; return;}
    vi s(4*n+1,2*n);
    s[2*n]=0;
    ll sum=0;
    ll ans=2*n;
    forn(i,n){
        sum+=a[i];
        if(sum==tot) ans=min(ans,i+1);
        s[sum+2*n]=min(s[sum+2*n],i+1);
    }
    sum=0;
    forn(i,n){
        sum+=b[i];
        if(sum==tot) ans=min(ans,i+1);
        ans=min(ans,i+1+s[tot-sum+2*n]);
    }
    cout << ans << "\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
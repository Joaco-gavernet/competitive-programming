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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n"

ll check(int x, vi &v){
    int n=SZ(v);
    ll mini=0, ans=-1e9, sum=0;
    forn(i,n) if(i!=x){
        sum+=v[i];
        ans=max(ans,sum-mini);
        mini=min(mini,sum);
    }
    return ans+max(0LL,v[x]);
}

void solve(){
    int n, k; cin >> n >> k;
    vi v(n);
    forn(i,n) cin >> v[i];
    ll mini=0, ans=-1e9, best=0, extra=0, sum=0;
    forn(i,n){
        sum=sum+v[i];
        ans=max(ans,sum-mini);
        mini=min(sum,mini);
    }
    if(ans<=0){cout << ans << "\n"; return;}
    while(k--){
        forn(i,n) {
            ll aux=check(i,v);
            if(aux+extra>ans) {ans=aux+extra; best=i;}
        }
        extra+=max(0LL,v[best]);
        v[best]=0;
    }
    cout << ans << "\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while(t--) solve();
    return 0; 
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define RAYA cerr << "========================\n"

void solve() {
    ll n; cin>>n;
    vi st(n+1,0);
    vi target(n+1,0);
    vi ramas(n+1,0);
    forn(i,n){
        char c; cin>>c;
        if(c=='1') target[i+1]=1;
    }
    ll ans=0;
    forr(i,1,n+1){
        if(st[i]<target[i] and ramas[i]==0){
            ramas[i]++;
            st[i]=1;
            ans++;
        }else if(st[i]>target[i]){
            if(ramas[i]==1) ans++;
            ramas[i]=0;
            st[i]=0;
        }
        if(st[i]>0){
            ll pos=i;
            pos+=(pos & (-pos));
            if(pos<=n){
                ramas[pos]++;
                st[pos]=1;
            }
        }
        // forn(i,n) cerr<<st[i+1];
        // cerr<<endl;
    }
    cout<<ans<<"\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}
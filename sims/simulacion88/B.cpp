#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
#define RAYA cerr << "============================\n"

ll solve(vi &v,ll n,ll m,vi &ps){
    // ll ac=0;
    // for(auto u:ps) cout<<u<<" ";
    // cout<<endl;
    ll punt=0;
    ll ans=0;
    while(punt<n){
        ll l=punt,r=n;
        ll med=(l+r)/2;
        while(l+1<r){
            // ll cand=ps[med-1];
            ll sum=ps[med+1];
            // DBG(sum);
            if(punt>0) sum-=(ps[punt]+1);
            // DBG(sum); DBG(med); 
            if(sum > m) r=med;
            else l=med;
            med=(l+r)/2;
        }
        // DBG(l); DBG(r);
        if(punt>0) ans++;
        ans+=v[punt];
        punt=r;
        // DBG(ans);
    }
    return ans;
}

int main() {
    FIN;
    string s; getline(cin,s);
    stringstream texto(s);
    vi tams;
    string aux;
    // ll w=1e6;
    while(texto>>aux){
        // DBG(aux);
        tams.pb(SZ(aux));
        // w=min(w,SZ(aux));
    }
    ll a,b; cin>>a>>b;
    ll n=SZ(tams);
    vi ps(n+1);
    forr(i,1,n+1){
        ps[i]=ps[i-1]+tams[i-1];
        if(i>1) ps[i]++;
        // DBG(ps[i]);
    }
    ps[0]=0;
    forr(i,a,b+1){
        // RAYA;
        cout<<solve(tams,n,i,ps)<<"\n";
    }
    return 0; 
}
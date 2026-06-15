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
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << endl
#define RAYA cerr << "========================\n"

void solve(){
    ll p,q,n; cin>>p>>q>>n;
    auto mcd=gcd(p,q);
    ll ans=0;
    q/=mcd; p/=mcd;
    ll sum=(q-1)*q/2;
    sum*=mcd;
    ans=sum*(n/q);
    n=n%q;
    p=p*mcd; q=q*mcd;
    if(n<=1000) forr(i,1,n+1) ans+=i*p%q; // n chico y q chico
    else if(p<=1000){ // p chico
        ans+=p*n*(n+1)/2;
        for(ll k=2; ((k-1)*q-1)/p<n; k++) ans-=(k-1)*q*(min(n,(k*q-1)/p)-((k-1)*q-1)/p);
    }
    cout << ans << "\n";
}

int main() {
    FIN;
    ll w; cin>>w;
    while(w--) solve();
    return 0; 
}

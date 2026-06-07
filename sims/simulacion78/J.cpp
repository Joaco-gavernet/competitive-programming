#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> ii;
#define NaN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"



int main() {
    NaN; 
    ll n,d; cin>>n>>d;
    vi posit(n+2,0); vi order(n+2,0); 
    vi permut(n+2,0); vi posperm(n+2,0); vi diff(n+2,0);
    forn(i,n){
        ll x; cin>>x;
        posit[x]=i+1;
        order[i+1]=x;
    }
    forn(i,n){
        ll x; cin>>x;
        posperm[x]=i+1;
        permut[i+1]=x;
    }
    ll ans=0;
    forr(i,1,n+1){
        ll elem=(posit[permut[i]]-posit[permut[i-1]]-1+n)%n;
        diff[i]=elem;
        ans+=elem;
    }
    cout<<ans<<"\n";
    forn(i,d-1){
        ll c,x,y; cin>>c>>x>>y;
        if(c==1){
            ll ax=order[x];
            ll ay=order[y];
            // DBG(ax); DBG(ay);
            ll px=posperm[ax];
            ll py=posperm[ay];
            // DBG(px); DBG(py);
            order[x]=ay; order[y]=ax; posit[ax]=y; posit[ay]=x;
        
            // DBG(posit[ax]); DBG(posit[permut[px-1]]);
            ll dx=(posit[ax]-posit[permut[px-1]]-1+n)%n;
            // DBG(dx);
            ans+=(dx-diff[px]); diff[px]=dx;
            // DBG(ans);
            
            // DBG(posit[ax]); DBG(posit[permut[px+1]]);
            if(px<n) dx=(posit[permut[px+1]]-posit[ax]-1+n)%n;
            else dx=0;
            // DBG(dx);
            ans+=(dx-diff[px+1]); diff[px+1]=dx;
            // DBG(ans);

            ll dy=(posit[ay]-posit[permut[py-1]]-1+n)%n;
            // DBG(dy);
            ans+=(dy-diff[py]); diff[py]=dy;
            // DBG(ans);
            if(py<n) dy=(posit[permut[py+1]]-posit[ay]-1+n)%n;
            else dy=0;
            // DBG(dy);
            ans+=(dy-diff[py+1]); diff[py+1]=dy;
            // DBG(ans);            
        }else{
            ll bx=permut[x];
            ll by=permut[y];
            permut[x]=by; permut[y]=bx; posperm[bx]=y; posperm[by]=x;
            
            // DBG(posit[by]); DBG(posit[permut[x-1]]);
            ll dx=(posit[by]-posit[permut[x-1]]-1+n)%n;
            ans+=(dx-diff[x]); diff[x]=dx;
            if(x<n) dx=(posit[permut[x+1]]-posit[by]-1+n)%n;
            else dx=0;
            ans+=(dx-diff[x+1]); diff[x+1]=dx;
            
            ll dy=(posit[bx]-posit[permut[y-1]]-1+n)%n;
            ans+=(dy-diff[y]); diff[y]=dy;
            if(y<n) dy=(posit[permut[y+1]]-posit[bx]-1+n)%n;
            else dy=0;
            ans+=(dy-diff[y+1]); diff[y+1]=dy;
            
            
        }
        cout<<ans<<"\n";
    }
    return 0; 
}
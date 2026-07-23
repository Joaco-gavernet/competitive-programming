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

const ll bits=64;

int main() {
    FIN;
    ll n; cin>>n;
    vi a(n+1),b(n+1);
    forn(i,n){
        ll x,y; cin>>x>>y;
        a[i+1]=x;
        b[i+1]=y;
    }
    vector<vi> dp0(n+1,vi(bits,0));
    vector<vi> dp1(n+1,vi(bits,0));
    forn(i,bits) dp0[0][i]=1;
    vi vbit(bits);
    forn(k,bits){
        ll c20=0,c21=0,c11=0;
        forr(i,1,n+1){
            // DBG(a[i]);
            // DBG(b[i]);
            ll c=a[i]&(1LL<<k);
            ll d=b[i]&(1LL<<k);
            // DBG(c);
            // DBG(d);
            if(a[i]&(1LL<<k) and b[i]&(1LL<<k)) c21++;
            else if(!(a[i]&(1LL<<k)) and !(b[i]&(1LL<<k))) c20++;
            else c11++;
        }
        // DBG(c21);
        if(c11>0) vbit[k]=2;
        else if(c21%2) vbit[k]=1;
        else vbit[k]=0;
        // DBG(k);
        // DBG(vbit[k]);
    }
    ll denom=1;
    for(auto u:vbit){
        if(u==1){
            cout<<"1/1\n";
            return 0;
        }
        if(u==2) denom*=2;
    }
    // }
    // if(denom==1){
    //     cout<<"0\1\n";
    //     return 0;
    // }
    cout<<denom-1<<'/'<<denom<<"\n";

    return 0; 
}
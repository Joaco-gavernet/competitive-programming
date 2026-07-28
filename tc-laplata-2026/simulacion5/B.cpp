#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i = a, jet = b; i < jet; i++)
#define SZ(x) int((x).size())
#define ALL(x) x.begin(), x.end()
#define mset(a,v) memset((a), (v), sizeof(a))
#define NCG ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

using pii = pair< int, int >; 

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;
const ll mod=998244353,maxn=5e5+5;
ll addm(ll a, ll b){a+=b; return a<mod?a:a-mod;}
ll mulm(ll a, ll b){return a*b%mod;}
ll fp(ll a, ll e){
    ll r=1;
    for(;e;e>>=1){
        if(e&1) r=mulm(r,a);
        a=mulm(a,a);
    }
    return r;
}
ll inv(ll a){return fp(a,mod-2);}
ll F[maxn],FI[maxn];

void calc_factorial(){
    F[0]=1;
    fore(i,1,maxn) F[i]=mulm(F[i-1],i);
    FI[maxn-1]=inv(F[maxn-1]);
    for(ll i=maxn-2; i>=0; i--){
        FI[i]=mulm(FI[i+1],i+1);
    }
}

ll comb(ll n, ll k){
    if(n<0||k<0||k>n) return 0;
    return mulm(F[n],mulm(FI[k],FI[n-k]));
}



int main() {
    NCG;
    calc_factorial();
    ll n,k; cin>>n>>k;
    ll s[n];
    fore(i,0,n) cin>>s[i];
    ll inv[n];
    fore(i,0,n) inv[s[i]]=i;
    ll u=0;
    fore(i,1,n){
        if(s[i]==n-1){
            u++; continue;
        }
        if(s[i-1]==n-1) continue;
        if(inv[s[i]+1]<inv[s[i-1]+1]) u++;
    }
    ll t=k-u-1;
    // cout<<t<<" "<<u<<"\n";
    ll rt=0;
    fore(i,0,t+1){
        rt=addm(rt,comb(n-1+i,i));
    }
    cout<<rt<<"\n";
}

// 2 1
// 0


/*
7 6
3 2 4 1 0 5 6
2 3
28



6 200000
0 1 2 3 4 5
199998 1
467822562

*/

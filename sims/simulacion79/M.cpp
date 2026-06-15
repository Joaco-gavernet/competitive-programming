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
#define SZ(x) (x).size()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

const ll MOD = 1e9+7;

ll solve(vi &v,ll ini,ll tam){
    ll cont=1; 
    forr(pos,ini+1,ini+tam) if(v[pos]==v[ini]) cont++;
    if(cont==tam) return tam;

    bool eqs=true;
    ll len=tam/2;
    map<ll,ll> h1,h2;
    forn(i,len){
        if(v[ini+i]!=v[ini+i+len]) eqs=false;
        h1[v[ini+i]]++;
        h2[v[ini+i+len]]++;
    }
    if(eqs){
        return (2*solve(v,ini,len))%MOD;
    }else{
        bool intersec=false;
        for(auto u:h1) if(h2[u.ff]!=0) intersec=true;
        if(intersec) return 0;
        else return ((solve(v,ini,len)*solve(v,ini+len,len))%MOD); 
    }
}

int main() {
    FIN;
    ll m,n; cin>>m>>n;
    ll tam=1<<m;
    vi nums(tam); forn(i,tam){cin>>nums[i];}
    ll ans=solve(nums,0,tam);
    cout<<ans<<"\n";
    return 0; 
}

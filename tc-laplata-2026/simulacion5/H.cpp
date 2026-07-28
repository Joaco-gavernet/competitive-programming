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

typedef int ll;
typedef pair<int ,int> ii;
typedef vector<ll> vv;
ll n,m;
ii dir[4]={{0,1},{0,-1},{-1,0},{1,0}};
bool cam=0;
ll addm(ll a, ll b,const ll &mo){
    a+=b;
    if(a<0) {cam=1;return a+mo;}
    if(a>=mo){cam=1;return a-mo;}
    return a;
}
ii operator+(const ii &a,const ii &b){
    cam=0;
    return {addm(a.fst,b.fst,n),addm(a.snd,b.snd,m)};
}
ii operator*(const ii &a,const ii &b){
    cam=0;
    return {a.fst+b.fst,a.snd+b.snd};
}

bool cy=0;
const ll maxn=1505;
bitset<maxn*maxn> tab;
bitset<maxn*maxn> vis;
ii cuad[maxn][maxn];
void dfs(ii u, ii f){
    vis[u.fst*m+u.snd]=1;
    for(auto p:dir){
        ii v=u+p;
        bool _c=cam;
        ii nc=cuad[u.fst][u.snd];
        if(_c) nc=nc*p;
        if(tab[v.fst*m+v.snd]||v==f) continue;
        if(!vis[v.fst*m+v.snd]) {
            cuad[v.fst][v.snd]=nc;
            dfs(v,u);
        }
        else if(vis[v.fst*m+v.snd]&&cuad[v.fst][v.snd]!=nc){
            cy=1;
        }
    }
}

int main() {
    NCG;
    cin>>n>>m;
    ii S;
    fore(i,0,n)fore(j,0,m){
        char c; cin>>c;
        tab[i*m+j]=(c=='#');
        if(c=='S')S={i,j};   
    }
    dfs(S,{-1,-1});
    cout<<(cy?"Yes\n":"No\n");
    return 0;
}
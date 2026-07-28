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
#define show(x) {for(auto [a,b]:x)cerr << "( "<<dame(a).fst << " "<<dame(a).snd<<", "<<dame(b).fst<<" "<<dame(b).snd<<") ";;cout<<endl;}
#define RAYA cerr << "==========================\n"


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
const ll maxn=405;

vi Q[maxn][maxn];  
ll n,m;
bool tab[maxn][maxn];
void aniadir(ll i, ll j, ii &q){
    if(i>=0&&i<n&&j>=0&&j<m) Q[i][j].pb(q);
}
ll cnt[8*maxn];
ii dame(ll x){return {x/m,x%m};}

void pon(vi *ups, ll i, ll j, ll a, ll id){
    ii p=dame(a);
    if(j==p.snd){
        if(p.fst>i)ups[0].pb({a,id});
        else ups[1].pb({a,id});
    }
    else if(i+j==p.fst+p.snd) {
        if(i<p.fst) ups[2].pb({a,id});
        else ups[3].pb({a,id});
    }
    else{ //i-j==p.fst-p.snd
        if(i<p.fst) ups[4].pb({a,id});
        else ups[5].pb({a,id});
    }
}
int main() {
    NCG;
    cin>>n>>m;
    fore(i,0,n){
        string s; cin>>s;
        fore(j,0,m) tab[i][j]=(s[i]=='1');
    }
    fore(i,0,n)fore(j,0,m){
        if(tab[i][j]) continue;
        ii q={i*m+j,i*m+j};
        fore(k,j+1,m){
            if(tab[i][k]) break;
            q.snd++;
            ll d=k-j;
            aniadir(i+d,j,q);
            aniadir(i+d,k,q);
            aniadir(i-d,j,q);
            aniadir(i-d,k,q);
            if(!(d&1)){
                aniadir(i+d/2,j+d/2,q);
                aniadir(i-d/2,j+d/2,q);
            }
        }
        q.snd=i*m+j;
        fore(k,i+1,n){
            if(tab[k][j]) break;
            q.snd+=m;
            ll d=k-i;
            if(!(d&1)){
                aniadir(i+d/2,j+d/2,q);
                aniadir(i+d/2,j-d/2,q);
            }
        }
    }
        RAYA;

    ll rt=0;
    vi up[6];
    fore(i,0,n)fore(j,0,m){
        if(tab[i][j]) continue;
        cout<<i<<" "<<j<<"::";
        show(Q[i][j]);
        ll sz=SZ(Q[i][j]);
        fore(t,0,sz)cnt[i]=0;
        fore(t,0,6) up[i].clear();
        fore(t,0,sz){
            auto [a,b]=Q[i][j][t];
            pon(up,i,j,a,t);
            pon(up,i,j,b,t);
        }
        fore(t,0,6) sort(ALL(up[t]));
        fore(t,0,3) reverse(ALL(up[2*t+1]));
        ll u=0;
        fore(k,i+1,m){
            if(tab[k][j]||u==SZ(up[0])) break;
            while(up[0][u].fst==k*m+j)
                cnt[up[0][u++].snd]++;
        }
        u=0;
        for(ll k=i-1; k>=0; k--){
            if(tab[k][j]||u==SZ(up[1])) break;
            while(up[1][u].fst==k*m+j)
                cnt[up[1][u++].snd]++;
        }
        u=0;
        for(ll d=1; i+d<n&&j-d>=0; d++){
            if(tab[i+d][j-d]||u==SZ(up[2])) break;
            while(up[2][u].fst==(i+d)*m+j-d)
                cnt[up[2][u++].snd]++;
        }
        u=0;
        for(ll d=1; i-d>=0&&j+d<m; d++){
            if(tab[i-d][j+d]||u==SZ(up[3])) break;
            while(up[3][u].fst==(i-d)*m+(j+d))
                cnt[up[3][u++].snd]++;
        }
        u=0;
        for(ll d=1; i+d<n&&j+d<m; d++){
            if(tab[i+d][j+d]||u==SZ(up[4])) break;
            while(up[4][u].fst==(i+d)*m+j+d)
                cnt[up[4][u++].snd]++;
        }
        u=0;
        for(ll d=1; i-d>=0&&j-d>=0; d++){
            if(tab[i-d][j-d]||u==SZ(up[5])) break;
            while(up[5][u].fst==(i-d)*m+j-d)
                cnt[up[5][u++].snd]++;
        }
        fore(t,0,sz)if(cnt[t]==2) rt++;
    }
    cout<<rt<<"\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

vector<vc> mapeo={
    {'0','0','0','0'},
    {'0','0','0','1'},
    {'0','0','1','0'},
    {'0','0','1','1'},
    {'0','1','0','0'},
    {'0','1','0','1'},
    {'0','1','1','0'},
    {'0','1','1','1'},
    {'1','0','0','0'},
    {'1','0','0','1'},
    {'1','0','1','0'},
    {'1','0','1','1'},
    {'1','1','0','0'},
    {'1','1','0','1'},
    {'1','1','1','0'},
    {'1','1','1','1'},
};

vc jer={'W','A','K','J','S','D'};

int dy[]={0,0,-1,1};
int dx[]={-1,1,0,0};

void bfswhite(ll x,ll y,ll h,ll w,vector<vc> &grid,vector<vb> &visto){
    queue<ii> next;
    next.push({x,y});
    visto[x][y]=true;
    while(SZ(next)){
        ii prox=next.front();
        next.pop();
        ll i=prox.ff; ll j=prox.ss;
        forn(k,4){
            int xi=i+dx[k];
            int yi=j+dy[k];
            if(xi>=0 and xi<h and yi>=0 and yi<w and !visto[xi][yi] and grid[xi][yi]=='0'){
                next.push({xi,yi}); visto[xi][yi]=true;
            }
        }
    }
    return;
}

void bfsblack(ll x,ll y,ll h,ll w,vector<vc> &grid,vector<vb> &visto,ll &cont){
    queue<ii> next;
    next.push({x,y});
    visto[x][y]=true;
    while(SZ(next)){
        ii prox=next.front();
        next.pop();
        ll i=prox.ff; ll j=prox.ss;
        forn(k,4){
            int xi=i+dx[k];
            int yi=j+dy[k];
            if(xi>=0 and xi<h and yi>=0 and yi<w and !visto[xi][yi] and grid[xi][yi]=='1'){
                next.push({xi,yi}); visto[xi][yi]=true;
            }
            if(xi>=0 and xi<h and yi>=0 and yi<w and !visto[xi][yi] and grid[xi][yi]=='0'){
                cont++; bfswhite(xi,yi,h,w,grid,visto);
            }
        }
    }
    return;
}

bool solve(int ids) {
    ll h,w; cin>>h>>w;
    if(h==0 and w==0) return false;
    cout << "Case " << ids << ": ";
    vector<vc> grid(h+2);
    forn(i,4*w+2) grid[0].pb('0');
    forn(i,4*w+2) grid[h+1].pb('0');
    forr(r,1,h+1){
        grid[r].pb('0');
        forn(i,w) {
            char c; cin>>c;
            ll pos;
            if(c>='a') pos=c-'a'+10;
            else pos=c-'0';
            // DBG(mapeo[pos][0]);
            forn(x,4) grid[r].pb(mapeo[pos][x]);
        }
        grid[r].pb('0');
    }
    w*=4;
    w+=2;
    h+=2;
    bool prim=true;
    vector<vb> visto(h,vb(w,false));
    vc ans;
    forn(i,h) forn(j,w){
        // DBG(grid[i][j]);
        if(grid[i][j]=='1' and !visto[i][j]){
            ll cont=0;
            // DBG(cont);
            bfsblack(i,j,h,w,grid,visto,cont);
            // DBG(cont);
            if(prim) cont--;
            prim=false;
            ans.pb(jer[cont]);
        }
    }
    // RAYA;
    sort(all(ans));
    forn(i,SZ(ans)) cout<<ans[i];
    cout<<"\n";
    return true; 
}

int main() {
    FIN;
    bool ans = true; 
    int i = 1; 
    while (ans) ans = solve(i++);
    return 0;
}
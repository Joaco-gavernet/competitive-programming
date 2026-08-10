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



void bfswhite(ll x,ll y,ll h,ll w,vector<vc> &grid,vector<vb> &visto){
    queue<ii> next;
    next.push({x,y});
    visto[x][y]=true;
    while(SZ(next)){
        ii prox=next.front();
        next.pop();
        ll i=prox.ff; ll j=prox.ss;
        if(i>0 and !visto[i-1][j] and grid[i-1][j]=='0'){next.push({i-1,j}); visto[i-1][j]=true;}
        if(i<(h-1) and !visto[i+1][j] and grid[i+1][j]=='0'){next.push({i+1,j}); visto[i+1][j]=true;}
        if(j>0 and !visto[i][j-1] and grid[i][j-1]=='0'){next.push({i,j-1}); visto[i][j-1]=true;}
        if(j<(w-1) and !visto[i][j+1] and grid[i][j+1]=='0'){next.push({i,j+1}); visto[i][j+1]=true;}
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
        if(i>0 and !visto[i-1][j] and grid[i-1][j]=='1'){next.push({i-1,j}); visto[i-1][j]=true;}
        if(i<(h-1) and !visto[i+1][j] and grid[i+1][j]=='1'){next.push({i+1,j}); visto[i+1][j]=true;}
        if(j>0 and !visto[i][j-1] and grid[i][j-1]=='1'){next.push({i,j-1}); visto[i][j-1]=true;}
        if(j<(w-1) and !visto[i][j+1] and grid[i][j+1]=='1'){next.push({i,j+1}); visto[i][j+1]=true;}
        if(i>0 and !visto[i-1][j] and grid[i-1][j]=='0'){cont++; bfswhite(i-1,j,h,w,grid,visto);}
        if(i<(h-1) and !visto[i+1][j] and grid[i+1][j]=='0'){cont++; bfswhite(i+1,j,h,w,grid,visto);}
        if(j>0 and !visto[i][j-1] and grid[i][j-1]=='0'){cont++; bfswhite(i,j-1,h,w,grid,visto);}
        if(j<(w-1) and !visto[i][j+1] and grid[i][j+1]=='0'){cont++; bfswhite(i,j+1,h,w,grid,visto);}
    }
    return;
}

bool solve(int ids) {
    ll h,w; cin>>h>>w;
    if(h==0 and w==0) return false;
    cout << "Case " << ids << ": ";
    vector<vc> grid(h+2);
    forn(i,8*w+2) grid[0].pb('0');
    forn(i,8*w+2) grid[h+1].pb('0');
    forr(r,1,h+1){
        grid[r].pb('0');
        forn(i,w) forn(k,2){
            char c; cin>>c;
            ll pos;
            if(c>='a') pos=c-'a'+10;
            else pos=c-'0';
            // DBG(mapeo[pos][0]);
            forn(x,4) grid[r].pb(mapeo[pos][x]);
        }
        grid[r].pb('0');
    }
    w*=8;
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
            if(prim and cont>0) cont--;
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
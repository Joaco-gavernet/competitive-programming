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


ll n,m,k;

ll cont=0;

ll dfs(ll i,ll j,vector<vector<char>> &grid,vector<vi> &visto){
    visto[i][j]=1;
    ll hijos=0;
    if(i-1>0 and grid[i-1][j]=='.' and !visto[i-1][j]) hijos+=dfs(i-1,j,grid,visto);
    if(i+1<=n and grid[i+1][j]=='.' and !visto[i+1][j]) hijos+=dfs(i+1,j,grid,visto);
    if(j-1>0 and grid[i][j-1]=='.' and !visto[i][j-1]) hijos+=dfs(i,j-1,grid,visto);
    if(j+1<=m and grid[i][j+1]=='.' and !visto[i][j+1]) hijos+=dfs(i,j+1,grid,visto);
    if(hijos==0 and cont<k){
        grid[i][j]='X';
        cont++;
        return 0;
    }else return 1;
}

int main() {
    FIN;
    cin>>n>>m>>k;
    vector<vector<char>> grid(n+2,vector<char>(m+2,'#'));
    forn(i,n) forn(j,m) cin>>grid[i+1][j+1];
    vector<vi> deg(n+2,vi(m+2,0));
    bool done=false;
    forr(i,1,n+1) forr(j,1,m+1){
        if(grid[i][j]=='.' and !done){
            dfs(i,j,grid,deg);
            done=true;
        }
    }
    // dfs(1,1,grid,deg);
    forr(i,1,n+1){
        forr(j,1,m+1){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }

    return 0; 
}
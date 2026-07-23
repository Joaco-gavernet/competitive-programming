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


int main() {
    FIN;
    ll n,m,k; cin>>n>>m>>k;
    vector<vector<char>> grid(n+2,vector<char>(m+2,'#'));
    forn(i,n) forn(j,m) cin>>grid[i+1][j+1];
    vector<vi> deg(n+2,vi(m+2,0));
    vector<queue<ii>> proxs(5,queue<ii>());
    forr(i,1,n+1) forr(j,1,m+1) if(grid[i][j]=='.'){
        if(grid[i-1][j]=='.') deg[i][j]++;
        if(grid[i+1][j]=='.') deg[i][j]++;
        if(grid[i][j+1]=='.') deg[i][j]++;
        if(grid[i][j-1]=='.') deg[i][j]++;
        proxs[deg[i][j]].push({i,j});
    }
    // RAYA;
    forn(i,k){
        forr(size,1,5) {
            if(SZ(proxs[size])){
                ii c=proxs[size].front(); proxs[size].pop();
                while(SZ(proxs[size]) and deg[c.ff][c.ss]!=size){
                    c=proxs[size].front(); proxs[size].pop();
                }
                if(deg[c.ff][c.ss]!=size) continue;
                grid[c.ff][c.ss]='X';
                deg[c.ff][c.ss]=0;
                // DBG(c.ff); DBG(c.ss);
                if(grid[c.ff-1][c.ss]=='.'){
                    deg[c.ff-1][c.ss]--;
                    proxs[deg[c.ff-1][c.ss]].push({c.ff-1,c.ss});
                }
                if(grid[c.ff+1][c.ss]=='.'){
                    deg[c.ff+1][c.ss]--;
                    proxs[deg[c.ff+1][c.ss]].push({c.ff+1,c.ss});
                }
                if(grid[c.ff][c.ss-1]=='.'){
                    deg[c.ff][c.ss-1]--;
                    proxs[deg[c.ff][c.ss-1]].push({c.ff,c.ss-1});
                }
                if(grid[c.ff][c.ss+1]=='.'){
                    deg[c.ff][c.ss+1]--;
                    proxs[deg[c.ff][c.ss+1]].push({c.ff,c.ss+1});
                }
                break;
            }
        }
        // DBG(i);
    }
    forr(i,1,n+1){
        forr(j,1,m+1){
            cout<<grid[i][j];
        }
        cout<<"\n";
    }

    return 0; 
}
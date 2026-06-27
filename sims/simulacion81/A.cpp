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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"


int main() {
    FIN;
    ll n,m; cin>>n>>m;
    vector<vi> grid(n,vi(m));
    vi acrow(n),accol(m);
    forn(i,n) forn(j,m){
        char c; cin>>c;
        if(c=='.') grid[i][j]=1;
        acrow[i]+=grid[i][j];
        accol[j]+=grid[i][j];
    }
    ll ans=0;
    //Case 4 in row
    forn(i,n) if(acrow[i]>=4){
        ll x=acrow[i];
        ans+=(x*(x-1)*(x-2)*(x-3));
    }
    // DBG(ans);
    //Case 4 in col
    forn(i,m) if(accol[i]>=4){
        ll x=accol[i];
        ans+=(x*(x-1)*(x-2)*(x-3));
    }
    // DBG(ans);
    //Case 3 in same row
    forn(i,n) forn(j,m){
        if(acrow[i]>=3 and accol[j]>=2 and grid[i][j]==1){
            ll x=acrow[i]; ll y=accol[j];
            ans+=(2*(x-1)*(x-2)*(y-1)); //(i,j) pivot
        }
    }
    // DBG(ans);
    //Case 3 in same col
    forn(i,n) forn(j,m){
        if(acrow[i]>=2 and accol[j]>=3 and grid[i][j]==1){
            ll x=acrow[i]; ll y=accol[j];
            ans+=(2*(x-1)*(y-2)*(y-1)); //(i,j) pivot
        }
    }
    // DBG(ans);
    //Case 3 pairs of 2
    //Choosing towers 2 and 3 in pivot row
    forn(row,n){
        ll acs=0; 
        forn(col,m) if(grid[row][col]==1) acs+=(accol[col]-1);
        forn(col,m) if(grid[row][col]==1){
            acs-=(accol[col]-1);
            ll x=accol[col]-1;
            ans+=(2*acs*x);
        }
    }
    // DBG(ans);
    //Choosing towers 2 and 3 in pibot col
    forn(col,m){
        ll acs=0; 
        forn(row,n) if(grid[row][col]==1) acs+=(acrow[row]-1);
        forn(row,n) if(grid[row][col]==1){
            acs-=(acrow[row]-1);
            ll x=acrow[row]-1;
            ans+=(2*acs*x);
        }
    }  
    // DBG(ans);
    //Final
    cout<<ans<<"\n";
    return 0; 
}
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
#define ss second
#define ff first
#define DBG(x) cerr << #x << " = " << x <<endl
#define RAYA cerr << "======================\n"

void solve(){
    ll n,m; 
    cin>>n>>m;
    // if(n==1 and m>3){cout<<"No\n"; return;}
    // if(m==1 and n>3){cout<<"No\n"; return;}
    bool trans=false;
    if((n%3)!=0){
        trans=true;
        swap(n,m);
    }
    if((n%3)==0 and (m%3)==0 and n>m){
        trans=true;
        swap(n,m);
    }
    vector<vi> ans(n,vi(m,-1));
    vector<vi> pattern(3);
    pattern[0]={0,0,2,2,1,1};
    pattern[1]={1,2,0,1,2,0};
    pattern[2]={2,1,1,0,0,2};
    // RAYA;
    if(m==4 and n>=9){
        trans^=1;
        swap(n,m);
        vector<vi> ans2(n,vi(m,-1));
        // RAYA;
        forn(col,m){
            ans2[0][col]=pattern[0][col%6];
            ans2[1][col]=pattern[1][col%6];
            ans2[2][col]=pattern[1][col%6];
            ans2[3][col]=pattern[2][col%6];
        }
        cout<<"Yes\n";
        if(!trans){
            forn(i,n){
                forn(j,m) cout<<ans2[i][j];
                cout<<"\n";
            }
        }else{
            forn(i,m){
                forn(j,n) cout<<ans2[j][i];
                cout<<"\n";
            }
        }
        return;
    }else if(m>=3){
        forn(col,m) for(ll row=0;row<n/3;row+=2){
            ans[row*3][col]=pattern[0][col%6];
            ans[row*3+1][col]=pattern[1][col%6];
            ans[row*3+2][col]=pattern[2][col%6];
            if(row+1<n/3){
                ans[(row+1)*3][col]=pattern[2][col%6];
                ans[(row+1)*3+1][col]=pattern[1][col%6];
                ans[(row+1)*3+2][col]=pattern[0][col%6];
            }
        }
    }else{
        if(n>6){
            cout<<"No\n";
            return;
        }else if(n==6){
            forn(i,m) ans[0][i]=0;
            forn(i,m) ans[1][i]=0;
            forn(i,m) ans[2][i]=1;
            forn(i,m) ans[3][i]=1;
            forn(i,m) ans[4][i]=2;
            forn(i,m) ans[5][i]=2;
        }else{
            forn(i,m) ans[0][i]=0;
            forn(i,m) ans[1][i]=1;
            forn(i,m) ans[2][i]=2;
        }
    }
    // RAYA;3
    cout<<"Yes\n";
    if(!trans){
        forn(i,n){
            forn(j,m) cout<<ans[i][j];
            cout<<"\n";
        }
    }else{
        forn(i,m){
            forn(j,n) cout<<ans[j][i];
            cout<<"\n";
        }
    }
    return;
}
int main() {
    FIN;
    ll t; cin>>t;
    while(t--)solve();
    return 0;
}
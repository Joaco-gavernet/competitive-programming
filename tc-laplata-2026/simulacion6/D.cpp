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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"


int main() {
    FIN;
    ll n,m; cin>>n>>m;
    vector<bitset<200>> matrix(n);
    forn(i,n) forn(j,m){
        ll c; cin>>c;
        if(c==0) matrix[i][j]=0;
        if(c==1) matrix[i][j]=1;
    }
    forn(pref,m+1){
        // DBG(pref);
        bitset<200> opcols;
        forn(i,pref) if(matrix[0][i]==1) opcols[i]=1;
        forr(i,pref,m) if(matrix[0][i]==0) opcols[i]=1;
        forn(i,n) matrix[i]^=opcols;
        ll lastbit=matrix[0][m-1];
        bitset<200> opfils;
        bool puedo=true;
        forr(i,1,n){
            bool up=false,down=false;
            forn(j,m-1){
                if(matrix[i][j]==0 and matrix[i][j+1]==1) up=true;
                if(matrix[i][j]==1 and matrix[i][j+1]==0) down=true;
            }
            if(up and down){
                puedo=false; break;
            }
            if(down){
                opfils[i]=1;
                matrix[i]=~(matrix[i]);
                if(lastbit>matrix[i][0]){
                    // DBG(i); DBG(lastbit);
                    puedo=false;
                    break;
                }
            }else{
                if(lastbit>matrix[i][0] and up){
                    // DBG(i); DBG(lastbit);
                    puedo=false;
                    break;
                }else if(lastbit!=matrix[i][0]){
                    opfils[i]=1;
                    matrix[i]=~(matrix[i]);
                }
            }
            lastbit=matrix[i][m-1];
        }

        // forn(i,n){
        //     forn(j,m){
        //         cerr<<matrix[i][j];
        //     }
        //     cerr<<endl;
        // }

        if(puedo){
            cout<<"YES\n";
            forn(i,n) cout<<opfils[i];
            cout<<"\n";
            forn(i,m) cout<<opcols[i];
            cout<<"\n";
            // forn(i,n){
            //     forn(j,n){
            //         if((opfils[i] ^ opcols[j]) == 1) cout<<"1";
            //         else cout<<"0";
            //     }
            //     cout<<"\n";
            // }
            return 0;
        }
        forr(i,1,n) if(opfils[i]) matrix[i]=~(matrix[i]);
        forn(i,n) matrix[i]^=opcols;
    }
    cout<<"NO\n";
    return 0;
}
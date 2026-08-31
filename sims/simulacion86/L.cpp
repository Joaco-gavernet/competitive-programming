#include <bits/stdc++.h> 
using namespace std; 

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second 
#define DBG(x) cerr << #x <<  " = " << x << endl
#define RAYA cerr << "==================\n"

void solve(){
    int n, m; cin >> n >> m;
    if(n==2){
        forn(i,n){
            forn(j,m-1) cout << 0 << " ";
            cout << 1 << "\n";
        }
    }
    else if(m>=4){
        forn(i,n){
            forn(j,m){
                if(j==max(0LL,m-1-i)) cout << 1 << " ";
                else cout << 0 << " ";
            }
            cout << "\n";
        }
    }else if(m==3){
        if(n==3){
            cout<< 0 << " " << 0 << " " << 1 << "\n";
            cout<< 0 << " " << 1 << " " << 0 << "\n";
            cout<< 1 << " " << 0 << " " << 0 << "\n";
        }else if(n>=6){
            forn(_,2) cout<< 0 << " " << 0 << " " << 1 << "\n";
            forn(_,2) cout<< 0 << " " << 1 << " " << 0 << "\n";
            forn(_,n-4) cout<< 1 << " " << 0 << " " << 0 << "\n";
        }else if(n==5){
            forn(_,1) cout<< 0 << " " << 0 << " " << 1 << "\n";
            forn(_,2) cout<< 0 << " " << 1 << " " << 0 << "\n";
            forn(_,2) cout<< 1 << " " << 0 << " " << 0 << "\n";
        }else if(n==4){
            forn(_,1) cout<< 0 << " " << 0 << " " << 1 << "\n";
            const double um=0.5;
            forn(_,1) cout<< um << " " << um << " " << 0 << "\n";
            forn(_,1) cout<< um << " " << 0 << " " << um << "\n";
            forn(_,1) cout<< 0 << " " << um << " " << um << "\n";
        }
    }else{
        forn(i,n/2) cout << 1<< " " << 0 << "\n";
        forn(i,n-n/2) cout << 0 << " " << 1 << "\n";
    }
}

int main() {
    FIN;
    cout<<fixed<<setprecision(11);
    int t=1;// cin >> t;
    while(t--) solve();
    return 0; 
}
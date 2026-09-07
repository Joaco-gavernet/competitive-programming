#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

void solve(){
    ll n, m; cin >> n >> m;
    bool s=false;
    if(m%4==1 or m%4==2) {s=true; swap(n,m);}
    if(m%4==1 or m%4==2){cout << "No\n"; return;}
    cout << "Yes\n";
    vi v(m+1);
    v[1]=1;
    forr(i,1,m+1) v[i]=v[i-1]+i;
    vi p;
    ll tot=v[m]/2, k=m;
    int j=m;
    while(tot>0){
        while(v[j]>tot) j--;
        while(tot-v[j]<k-j) j--;
        tot-=v[j]; k-=j; p.pb(j);
    }
    if(!s){
        forn(i,n){
            int d=0;
            for(auto t : p){
                forn(j,t) cout << d << " ";
                d=1-d;
            }
            cout << "\n";
        }
    }
    else{
        int d=0;
        for(auto t : p){
            forn(i,t){
                forn(j,n) cout << d << " ";
                cout << "\n";
            }
            d=1-d;
        }
    }
}

int main() {
    FIN; 
    int t; cin >> t;
    while(t--) solve();
    return 0; 
}
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



int main() {
    FIN;
    ll n; cin>>n;
    vector<char> soil(n+2,'$');
    vector<bool> cc(n+2,true);
    forr(i,1,n+1){
        char c; cin>>c;
        soil[i]=c;
        if(c=='L'){
            cc[i]=false;
            cc[i-1]=false;
            cc[i+1]=false;
        }
    }
    forr(i,1,n+1) if(cc[i]) soil[i]='C';
    forr(i,1,n+1) cout<<soil[i];
    cout<<"\n";
    return 0; 
}
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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"

int main() {
    FIN;
    vi comp={4,9,25,49};
    vi primos={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
    string s;
    for(auto u:comp){
        cout<<u<<endl;
        cin>>s;
        if(s=="yes"){
            cout<<"composite"<<endl;
            return 0;
        }
    }
    ll cont=0;
    for(auto u:primos){
        cout<<u<<endl;
        cin>>s;
        if(s=="yes") cont++;
        if(cont>1){
            cout<<"composite"<<endl;
            return 0;
        }
    }
    cout<<"prime"<<endl;

    return 0;
}
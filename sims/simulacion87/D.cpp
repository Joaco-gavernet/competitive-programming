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


int main() {
    FIN; 
    string s; cin>>s;
    ll ct=0, cd=0;
    forn(i,5){
        if(s[i]=='T') ct++;
        if(s[i]=='D') cd++;
    }
    if(ct>=3) cout<<"T1\n";
    if(cd>=3) cout<<"DRX\n";
    return 0; 
}
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
    cout<<fixed<<setprecision(10);
    ll n,h; cin>>n>>h;
    long double ans=h;
    ans=ans/((long double)sqrtl(n));
    forr(k,1,n){
        long double extra=sqrtl(k);
        long double pr=ans*extra;
        cout<<pr<<" ";
    }
    cout<<"\n";
    return 0;
}
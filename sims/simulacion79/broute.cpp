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
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define SZ(x) (x).size()
#define DBG(x) cerr << #x << " = " << endl
#define RAYA cerr << "========================\n"


int main() {
    FIN;
    int n; cin >> n;
    vi x1(n), x2(n), y1(n), y2(n);
    forn(i,n) cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    forn(i,n) forn(j,n) if(i!=j){
        bool y=false, x=false;
        if(y1[j]<y1[i] and y1[i]<y2[j]) y=true;
        if(y1[j]<y2[i] and y2[i]<y2[j]) y=true;
        if(x1[i]<x1[j] and x1[j]<x2[i]) x=true;
        if(x1[i]<x2[j] and x2[j]<x2[i]) x=true;
        if(x and y){cout << "1\n"; return 0;}
    } 
    cout << "0\n";
    return 0; 
}

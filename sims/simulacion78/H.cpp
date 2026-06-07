#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> ii;
#define NaN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"



int main() {
    NaN; 
    int n; cin >> n;
    vi v(n);
    forn(i,n) cin >> v[i];
    ll a=v[0], b=v[0], d=1e18;
    if(v[0]!=v[n-1]) d=min(d,abs(v[0]-v[n-1]));
    bool flip=false;
    ll s=0;
    forr(i,1,n){
        if(i<n-1){
            if(flip) v[i]=s-v[i];
            else v[i]=s+v[i];
        }
        if(v[i]<b){
            flip=!flip;
            s=b*2-s;
            v[i]=b*2-v[i];
            if(i!=n-1) v[n-1]=b*2-v[n-1];
        }
        if(a!=v[n-1]) d=min(d,abs(a-v[n-1]));
        b=v[i];
    }
    forr(i,1,n-1) if(v[i]*2-a!=v[n-1]) d=min(d,abs(v[n-1]-(v[i]*2-a)));
    forn(i,n-1) if(v[i]!=v[i+1]) d=min(d,v[i+1]-v[i]);
    if(d!=0) cout << v[n-1]-(a-1)/(d*2)*(d*2) << "\n";
    else cout << b << "\n";
    return 0; 
}
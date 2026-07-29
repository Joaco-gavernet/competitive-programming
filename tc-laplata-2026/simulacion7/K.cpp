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
    ll n, k; cin >> n >> k;
    vi v(n); forn(i,n) cin >> v[i];
    ll neg=0, e=0;
    if(v[n-1]>=0) e=1;
    int last=-1;
    vi q;
    forn(i,n) if(v[i]<0){
        neg=1; k--;
        if(last!=-1 and i-last-1>0) q.pb(i-last-1);
        last=i;
    }
    if(neg==0){
        cout<<"0\n";
        return 0;
    }
    // for(auto u : q) cout << u << endl;
    if(k<0) {cout << "-1\n"; return 0;}
    ll ans=2*SZ(q)+e+neg;
    sort(all(q));
    for(auto u : q) if(u<=k){
        ans-=2;
        k-=u;
    }
    if(e and k>=n-1-last) ans--;
    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

vi z_function(string s) {
    ll n = SZ(s); 
    vi z(n);
    for (ll i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]); 
        while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1; 
    }
    return z; 
}

void solve() {
    string s; cin >> s;
    ll n=SZ(s);
    ll ans=0;
    forr(i,1,n-4){
        string aux=s.substr(i,n-i)+"$"+s;
        //cout << aux << endl;
        vi z=z_function(aux);
        //for(auto u : z) cout << u << " ";
        //cout << endl;
        vi a(n);
        forn(j,i) if(j+z[n+1-i+j]>=i) a[i-j]++;
        //forn(i,n) cout << a[i] << " ";
        //cout << endl;
        forr(j,1,n) a[j]+=a[j-1];
        forr(j,1,n) a[j]+=a[j-1];
        //forn(i,n) cout << a[i] << " ";
        //cout << endl;
        forr(j,i+3,n) if(z[n+1-i+j]>=2){
            //DBG(j); DBG(min(z[n+1-i+j]-1,j-i-2));
            ans+=a[min(z[n+1-i+j]-1,j-i-2)];
        }
    }
    cout << ans << "\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}
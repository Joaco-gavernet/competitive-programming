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


struct Hash {
    const ll P = 1777771;
    const ll MOD[2] = {999727999, 1070777777};
    const ll PI[2] = {325255434, 10018302}; 
    vi h[2], pi[2]; 
    Hash(string& s) {
        forn(k,2) h[k].resize(SZ(s) + 1), pi[k].resize(SZ(s) + 1); 
        forn(k,2) {
            h[k][0] = 0; pi[k][0] = 1; 
            ll p = 1;
            forr(i,1,SZ(s) + 1) {
                h[k][i] = (h[k][i-1] + p * s[i-1]) % MOD[k];
                pi[k][i] = (1LL*pi[k][i-1] * PI[k]) % MOD[k]; 
                p = (p * P) % MOD[k]; 
            }
        }
    }
    ll get(ll s, ll e) {
        e++;
        ll h0 = (h[0][e]-h[0][s] + MOD[0]);
        h0 = (1LL * h0 * pi[0][s]) % MOD[0]; 
        ll h1 = (h[1][e] - h[1][s] + MOD[1]); 
        h1 = (1LL * h1 * pi[1][s]) % MOD[1];
        return (h0 << 32) | h1; 
    }
};

void solve() {
    string t; cin>>t;
    ll n=SZ(t);
    // DBG(n);
    Hash checker(t);
    ll ans=0;
    forr(pref1,1,((n-3)/3)+1) forr(pref2,1,((n-3*pref1-1)/2)+1){
        ll id1=checker.get(0,pref1-1);
        ll id2=checker.get(pref1,pref1+pref1-1);
        ll id3=checker.get(pref1+pref1,pref1+pref1+pref2-1);
        ll id5=checker.get(n-1-(pref2-1)-1-(pref1-1),n-1-(pref2-1)-1);
        ll id6=checker.get(n-1-(pref2-1),n-1);
        if(id1==id2 and id2==id5 and id3==id6) ans++;
    }
    cout<<ans<<"\n";
}

int main() {
    FIN;
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}
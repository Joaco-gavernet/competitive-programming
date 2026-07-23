#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===============================\n"


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
            forr(i,1,SZ(s)+1) {
                h[k][i] = (h[k][i-1] + p * s[i-1]) %MOD[k];
                pi[k][i] = (1LL*pi[k][i-1]*PI[k]) %MOD[k];
                p = (p * P) % MOD[k];
            }
        }
    }
    ll get(ll s, ll e) {
        e++;
        ll h0 = (h[0][e]-h[0][s]+MOD[0]);
        h0 = (1LL*h0*pi[0][s]) % MOD[0];
        ll h1 = (h[1][e]-h[1][s]+MOD[1]);
        h1 = (1LL*h1*pi[1][s]) % MOD[1];
        return (h0<<32)|h1; 
    }
};

vi d1;
vi d2;
void manacher(string& s) {
    ll l = 0, r = -1, n = SZ(s);
    d1.resize(n), d2.resize(n);
    forn(i, n) {
        ll k = (i > r ? 1 : min(d1[l + r - i], r - i));
        while (i + k < n and i - k >= 0 and s[i + k] == s[i - k]) k++;
        d1[i] = k--;
        if (i + k > r) l = i - k, r = i + k;
    }
    l = 0, r = -1;
    forn(i,n) {
        ll k = (i > r ? 0 : min(d2[l + r - i+1], r - i + 1));
        k++;
        while (i + k <= n and i -k >= 0 and s[i + k - 1] == s[i - k]) k++;
        d2[i] = --k;
        if (i + k - 1 > r) l = i -k, r = i + k - 1;
    }
}

int main() {
    FIN;
    int n; string s; cin >> n >> s;
    manacher(s);
    Hash h(s);
    vi v(n+1);
    forn(i,n) v[i+1]=v[i]+s[i]-'a'+1;
    ll ans=0;
    set <ll> g;
    forn(i,n){
        int l=i-d1[i]+1, r=i+d1[i]-1;
        while(r>=l and g.find(h.get(l,r))==g.end()){
            g.insert(h.get(l,r));
            ans+=v[r+1]-v[l];
            l++; r--;
        } 
        l=i-d2[i]; r=i+d2[i]-1;
        while(r>l and g.find(h.get(l,r))==g.end()){
            g.insert(h.get(l,r));
            ans+=v[r+1]-v[l];
            l++; r--;
        }
    }
    cout << ans << "\n";
    return 0; 
}
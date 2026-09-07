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

const ll MAXN=1e6+5;
const ll INF = 1LL<<60; 

struct Hash {
    const ll P = 1'777'771;
    const ll MOD[2] = {999727999, 1070'777'777}; 
    const ll PI[2] = {325255434, 10018302}; 
    vi h[2], pi[2]; 
    Hash(string& s) {
        forn(k,2) h[k].resize(SZ(s) + 1), pi[k].resize(SZ(s) + 1);
        forn(k,2) {
            h[k][0] = 0; pi[k][0] = 1;
            ll p = 1;
            forr(i,1,SZ(s) + 1) {
                h[k][i] = (h[k][i-1] + p * s[i - 1]) % MOD[k];
                pi[k][i] = (1LL*pi[k][i-1] * PI[k]) % MOD[k]; 
                p = (p * P) % MOD[k]; 
            }
        }
    }
    ll get(ll s, ll e) {
        e++;
        ll h0 = (h[0][e] - h[0][s] + MOD[0]); 
        h0 = (1LL * h0 * pi[0][s]) % MOD[0]; 
        ll h1 = (h[1][e] - h[1][s] + MOD[1]); 
        h1 = (1LL * h1 * pi[1][s]) % MOD[1]; 
        return (h0 << 32) | h1; 
    }
};

vi d1, d2; // d1 impar, d2 par
void manacher(string& s) {
    ll l = 0, r = -1, n = SZ(s);
    d1.clear(); d2.clear();
    d1.resize(n), d2.resize(n); 
    forn(i,n) {
        ll k = (i > r ? 1 : min(d1[l + r - i], r - i)); 
        while (i + k < n and i - k >= 0 and s[i + k] == s[i - k]) k++;
        d1[i] = k--;
        if (i + k > r) l = i - k, r = i + k; 
    }
    l = 0, r = -1;
    forn(i,n) {
        ll k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1));
        k++; 
        while (i + k <= n and i - k >= 0 and s[i + k - 1] == s[i - k]) k++;
        d2[i] = --k;
        if (i + k - 1 > r) l = i - k, r = i + k - 1; 
    }
}

vi min_prime; 
vi criba(ll n) {
    vb prime(n + 1, true); 
    min_prime.resize(n + 1, INF);
    vi primos; 
    for (ll p = 2; p * p <= n; p++) {
        if (!prime[p]) continue; 
        for (ll i = p * p; i <= n; i += p) {
            prime[i] = false; 
            min_prime[i] = min(min_prime[i], p); 
        }
    }
    forr(i, 2, n + 1) if (prime[i]) primos.pb(i), min_prime[i] = i; 
    return primos; 
}

vi find_divisors(ll n, vi& primos) {
    vector<ii> factor;
    for (ll prime : primos) {
        int cont = 0;
        while (n % prime == 0) {
            cont ++;
            n /= prime; 
        }
        if (cont > 0) factor.pb({prime, cont}); 
    }
    if (n > 1) factor.pb({n, 1}); 
    vi divisores = {1}; 
    for (auto [p, exp] : factor) {
        int tam = SZ(divisores); 
        forn(i,exp) {
            forn(j,tam) {
                int pos = SZ(divisores) - tam; 
                divisores.pb(divisores[pos] * p);
            }
        }
    }
    sort(all(divisores)); 
    return divisores; 
}

int main() {
    FIN;
    vector <vi> divs(MAXN);
    forr(i,1,MAXN) for(int j=i; j<MAXN; j+=i) divs[j].pb(i);
    int t; cin >> t;
    set <ll> pal;
    map <ll,ll> m;
    while(t--){
        string s; cin >> s;
        int n=SZ(s);
        manacher(s);
        Hash h(s);
        forn(i,n){
            int l=i-d1[i]+1, r=i+d1[i]-1;
            while(r>=l and pal.find(h.get(l,r))==pal.end()){
                pal.insert(h.get(l,r));
                for(auto d : divs[r-l+1]) if(h.get(l,r-d)==h.get(l+d,r)){
                    m[h.get(l,l+d-1)]=max(m[h.get(l,l+d-1)],(r-l+1)/d);
                    break;
                }
                l++; r--;
            }
            l=i-d2[i]; r=i+d2[i]-1;
            while(r>=l and pal.find(h.get(l,r))==pal.end()){
                pal.insert(h.get(l,r));
                for(auto d : divs[r-l+1]) if(h.get(l,r-d)==h.get(l+d,r)){
                    m[h.get(l,l+d-1)]=max(m[h.get(l,l+d-1)],(r-l+1)/d);
                    break;
                }
                l++; r--;
            }
        }
    }
    ll ans=0;
    for(auto [h,c] : m) ans+=c*c;
    cout << ans << "\n";
    return 0; 
}
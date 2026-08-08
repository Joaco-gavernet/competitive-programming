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
#define RAYA cerr << "=======================\n"


const ll INF = 1LL<<60;
const ll MOD = 1e9+7; 
const ll MAXN = 1e6+5; 

vi min_prime; 
vi criba(ll n) {
    vb prime(n + 1, true);
    min_prime.resize(n+1, INF);
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

ll be(ll b, ll e, ll m = MOD) {
    ll r = 1; b %= m;
    while (e) { if (e&1LL) r = r * b % m; b = b * b % m; e /= 2; }
    return r; 
}


int main() {
    FIN;

    int n; cin >> n; 
    vi a(n); forn(i,n) cin >> a[i]; 
    vi crib = criba(MAXN);

    vi cnt(MAXN);
    forn(i,n) {
        unordered_map<ll,ll> h;
        while (a[i] > 1) {
            h[min_prime[a[i]]] ^= 1; 
            a[i] /= min_prime[a[i]]; 
        }
        for (auto [k, v] : h) if (v == 1) cnt[k]++; 
    }

    ll tot = 1; 
    forn(p,MAXN) if (min_prime[p] == p) {
        ll mn = min(cnt[p], n - cnt[p]);
        tot *= be(p, mn);
        tot %= MOD; 
    }
    cout << tot << '\n'; 

    return 0; 
}
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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

const ll INF = 1LL<<60; 
const ll MAXN = 2e6+5;
const ll MOD = 1e9+7;
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
};

int main() {
    FIN;
    criba(MAXN);
    ll n; cin >> n;
    vi p(n);
    forn(i,n) cin >> p[i];
    sort(all(p));
    vi e(MAXN);
    int u=0;
    vi check, cub(MAXN);
    for(int i=n-1; i>=0; i--){
        if(e[p[i]]==0) e[p[i]]=1;
        else{
            ll k=p[i]-1;
            while(k>1){
                ll q=min_prime[k], cont=0;
                while(min_prime[k]==q){cont++; k/=q;}
                if(e[q]<cont){
                    cub[q]=1;
                    e[q]=cont;
                }
                else if(e[q]==cont) cub[q]++;
            }
            check.pb(p[i]-1);
        }
    }
    
    for(auto k : check){
        bool b=true;
        while(k>1){
            ll q=min_prime[k], cont=0;
            while(min_prime[k]==q){cont++; k/=q;}
            if(e[q]>cont) continue;
            else if(cub[q]==1) b=false;
        }
        if(b) u=1;
    }
    ll ans=1;
    forn(i,MAXN) forn(j,e[i]) ans=ans*i%MOD;
    cout << (ans+u)%MOD << "\n";
    return 0;
}
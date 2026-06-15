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
#define DBG(x) cerr << #x << " = " << endl
#define RAYA cerr << "========================\n"


int main() {
    FIN;
    ll n, k; cin >> n >> k;
    vector <long double> x(n), y(n);
    forn(i,n) cin >> x[i] >> y[i];
    long double ans=0;
    cout << setprecision(10) << fixed;
    forr(d,1,n){
        if(k>d+1) continue;
        long double p=k*(k-1);
        p/=n-k+1; p/=n-k+2;
        forn(i,k-2) p*=((long double)(d-1-k+3+i))/(n-k+3+i);
        forn(i,n){
            ll j=(i+d)%n;
            ans+=p*(x[i]*y[j]-x[j]*y[i]);
        }
    }
    cout << ans/2 << "\n";

    return 0; 
}

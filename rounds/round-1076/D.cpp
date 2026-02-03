#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================" << endl
#define ff first
#define ss second

int main() {
    FIN;

    int n; cin >> n; 
    vi a(n); forn(i,n) cin >> a[i];
    vi b(n); forn(i,n) cin >> b[i]; 

    sort(all(a)); 
    vi pref(n+1); forn(i,n) pref[i+1] = pref[i] + b[i];  
    
    ll x = 0, l = 0, r = n-1; 
    ll best = 0; 
    forn(l,n) {
        cerr << x << ' ' <<  l << ' ' << r << '\n'; 
        while (l < n and a[l] < x) l++;
        int ops = n - l + 1; 
        while (r > 0 and ops < pref[r]) r--;
        best = max(best, x * r); 
        if (l + 1 < n) x = a[l + 1] - 1; 
        else break; 
    }
    cout << best << '\n'; 
    

    return 0; 
}
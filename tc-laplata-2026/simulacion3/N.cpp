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


int main() {
    FIN;

    int n; cin >> n;
    vi a(n), b(n); forn(i,n) cin >> a[i], b[i] = a[i]; 
    
    sort(all(b)); 
    int diffs = 0;
    forn(i,n) diffs += (a[i] != b[i]);

    if (diffs <= 2) cout << "YES\n";
    else cout << "NO\n"; 

    return 0; 
}
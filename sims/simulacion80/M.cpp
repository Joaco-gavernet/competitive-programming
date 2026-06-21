#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ss second
#define ff first
#define DBG(x) cerr << #x << " = " << x <<endl
#define RAYA cerr << "======================\n"


int main() {
    FIN;
    int n; cin >> n;
    vector <vi> v(n,vi(n));
    forn(i,n){
        ll x; cin >> x;
        forn(j,n) v[i][j]=x;
        v[i][i]=(x+1)%998244353;
    }
    forn(i,n){
        forn(j,n) cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
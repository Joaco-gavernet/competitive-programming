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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

const ll INF = 1e9;

int main() {
    FIN;
    int n; cin >> n; 
    vi where(n, -1);
    vi p(n); forn(i,n) cin >> p[i], p[i]--, where[p[i]] = i; 
    vector<vi> interv(n,vi(n,INF));
    forn(i,n) interv[i][i]=0;
    // RAYA;
    forn(i,n-1) interv[i][i+1]=abs(where[i]-where[i+1]);
    // RAYA;
    forr(dist,2,n){
        // DBG(dist);
        forn(start,n-dist){
            ll ultima=start+dist;
            forr(pivot,start+1,ultima){
                interv[start][ultima]=min(interv[start][ultima],interv[start][pivot]+interv[pivot][ultima]);
                interv[start][ultima]=min(interv[start][ultima],interv[start][ultima-1]+abs(where[start]-where[ultima]));
            }
            // DBG(interv[start][ultima]);
        }
    }
    cout<<interv[0][n-1]<<'\n';
    return 0; 
}
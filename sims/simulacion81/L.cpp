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


int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0}; 

int main() {
    FIN;

    int r, c, n, p; cin >> r >> c >> n >> p; 
    vector<vi> G(r, vi(c));
    forn(i,r) forn(j,c) cin >> G[i][j];

    int y = -1, x = -1; 
    forn(i,r) forn(j,c) if (G[i][j] == p) {
        x = j, y = i;
        break;
    }
    set<ll> st;
    forn(step,p) {
        int nxt = -1;
        forn(j,4) {
            int xn = x + dx[j];
            int yn = y + dy[j];
            if (xn < 0 or xn >= c) continue;
            if (yn < 0 or yn >= r) continue;
            if (G[yn][xn] == 0 or G[yn][xn] + step > n) continue; 
            st.insert(G[yn][xn] + step); 
            if (p - step - 1 == G[yn][xn]) nxt = j;
        }
        if (nxt == -1) break;
        x += dx[nxt];
        y += dy[nxt];
    }
    cout << SZ(st) << '/' << n - 1 << '\n'; 
    return 0; 
}
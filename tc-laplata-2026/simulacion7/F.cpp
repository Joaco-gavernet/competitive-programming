#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1}; 

int main() {
    FIN;

    int n, m; cin >> n >> m;
    vector<string> tab(n); forn(i,n) cin >> tab[i]; 

    vi sz; // size of each component
    vi comp(n * m, -1); // id of the component for each node
    vb visto(n * m); 

    function<void(int, int, int)> dfs = [&](int y, int x, int id) {
        visto[y * m + x] = true;
        comp[y * m + x] = id;
        sz[id]++; 
        forn(i,4) {
            int yi = y + dy[i];
            int xi = x + dx[i]; 
            if (yi < 0 or n <= yi) continue;
            if (xi < 0 or m <= xi) continue; 
            if (tab[yi][xi] == '*') continue;
            if (visto[yi * m + xi]) continue; 
            dfs(yi, xi, id); 
        }  
    };

    forn(y,n) {
        forn(x,m) {
            if (visto[y * m + x] == false and tab[y][x] == '.') {
                // cout << y << ' ' << x << '\n';
                sz.pb(0); 
                dfs(y, x, SZ(sz) - 1); 
            }
        }
    }
    // for (auto x : sz) cout << x << ' ';
    // cout << '\n';

    // for (auto x: comp) cout << x << ' ';
    // cout << '\n';
    // RAYA; 


    vector<string> ans = tab; 
    forn(y,n) {
        forn(x,m) {
            if (tab[y][x] == '*') {
                ll tot = 0;
                set<ll> st; 
                forn(i,4) {
                    int yi = y + dy[i];
                    int xi = x + dx[i]; 
                    if (yi < 0 or n <= yi) continue;
                    if (xi < 0 or m <= xi) continue; 
                    if (tab[yi][xi] == '*') continue;
                    st.insert(comp[yi * m + xi]); 
                }
                for (auto x : st) tot += sz[x]; tot++;
                ans[y][x] = '0' + (tot % 10);
            }
        }
    }

    forn(i,n) cout << ans[i] << '\n';

    return 0;
}
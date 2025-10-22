#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl

int dy[] = {0,1}; 
int dx[] = {1,0};

const int MOD = 1e9+7; 

void solve() {
    int h, w; cin >> h >> w; 
    vector<string> tab(h); forn(i,h) cin >> tab[i]; 
    vector<vi> dp(h, vi(w)); 
    dp[0][0] = 1; 
    forn(y,h) {
        forn(x,w) {
            if (tab[y][x] == '#') continue; 
            forn(k,2) {
                int yi = y +dy[k]; 
                int xi = x +dx[k]; 
                if (yi < 0 or yi >= h) continue; 
                if (xi < 0 or xi >= w) continue; 
                if (tab[yi][xi] == '#') continue; 
                (dp[yi][xi] += dp[y][x]) %= MOD; 
            }
        }
    }
    cout << dp[h-1][w-1] << '\n'; 
}


int main(){
    FIN;
    int t = 1; 
    // cin >> t;
    while (t--) solve();
    return 0;
}

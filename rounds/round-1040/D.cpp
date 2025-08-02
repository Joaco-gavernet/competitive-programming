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


void solve() {
    int n; cin >> n; 
    vi p(n); forn(i,n) cin >> p[i]; 
    const int N = 2*n; 

    ll invs = 0; 
    vb x(N+1); 
    forn(i,n) {
        int l = p[i], r = N -p[i]; 
        int cont = 0; 
        for (int j = l; j <= r; j++) if (x[j]) cont++; 
        int range = (N -p[i] -1) -(p[i] +1) +1; 
        range = max(range, 0); 
        range /= 2; range++; 
        if (cont <= range /2 or l == r) x[p[i]] = true, invs += cont; 
        else x[N -p[i]] = true, invs += range -cont; 
    } 
    cout << invs << '\n'; 
}


int main(){
    FIN;
    int t = 1; 
    cin >> t;
    while (t--) solve();
    return 0;
}

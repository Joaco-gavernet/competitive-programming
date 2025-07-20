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
    vector<ii> v(n);
    multiset<ll> hor, ver; 
    forn(i,n) {
        cin >> v[i].fst >> v[i].snd; 
        hor.insert(v[i].fst);
        ver.insert(v[i].snd);
    }
    if (n == 1) {
        cout << "1\n";
        return; 
    }

    ll best = 1e18+5; 
    forn(i,n+1) {
        if (i < n) {
            hor.erase(hor.find(v[i].fst)); 
            ver.erase(ver.find(v[i].snd)); 
        }

        ll l = *hor.begin(); 
        ll r = *hor.rbegin(); 
        ll up = *ver.rbegin(); 
        ll down = *ver.begin(); 

        ll area = (r-l+1) *(up -down+1); 
        if (area == n-1) {
            area = (r-l+1) * (up -down +2); 
            area = min(area, (r-l+2) *(up -down +1)); 
        }
        best = min(best, area); 
        if (i < n) {
            hor.insert(v[i].fst); 
            ver.insert(v[i].snd); 
        }
    }
    cout << best << '\n'; 
}


int main(){
    FIN;
    int t = 1; 
    cin >> t;
    while (t--) solve();
    return 0;
}

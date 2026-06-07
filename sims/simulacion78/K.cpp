#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll, ll> ii;
#define NaN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"

int check(vi& h, int st, int en) {
    int tot = 0;
    forr(i,st,en+1) tot += h[i];
    return tot;
}

void use(vi& h, int st, int en) {
    forr(i,st,en+1) {
        if (h[i] > 0) {
            h[i]--;
            return;
        }
    }
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi h(10);
    for (char c : s) h[c - '0']++;
    ll tot = 0;

    // all possible starting with 0 (and not using 1s)
    
    // all possible starting with 1
    
    cout << tot << '\n'; 
}

int main() {
    NaN; 
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}
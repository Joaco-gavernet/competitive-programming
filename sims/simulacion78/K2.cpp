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

void solve() {
    int n; cin >> n;
    string st; cin >> st;
    vi h(10);
    for (char c : st) h[c - '0']++;
    ll hr=min(h[0],n-h[0])+(h[0]-min(h[0],n-h[0]))/2;
    ll bajos=0;
    for(int i=9; i>=1; i--){
        ll d=min(h[i],h[0]);
        h[i]-=d; h[0]-=d;
        if(i<6) bajos+=d;
    }
    hr+=h[1]/2;
    bajos+=(h[0]+h[1])/2;
    h[1]=h[1]%2;
    h[0]=h[0]%2;
    ll ch=0, g=0;
    forr(i,0,6) ch+=h[i];
    forr(i,6,10) g+=h[i];
    ll ms=min(ch,g)+(ch-min(ch,g))/2;
    if(ms>=hr) cout << hr << "\n";
    else{
        if(ch>g) cout << (hr+ms)/2 << "\n";
        else{
            g=g-ch;
            ll d=min(bajos,min(g/2,(hr-ms)/3));
            ms+=2*d;
            hr-=d;
            cout << (hr+ms)/2 << "\n";
        }
    }
}

int main() {
    NaN; 
    int t; cin >> t;
    while (t--) solve(); 
    return 0; 
}
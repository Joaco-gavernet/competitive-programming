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

string ans;

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    vi v(3);
    string t="RGB";

    forn(i,n) forn(j,3) if(s[i]==t[j]) v[j]++;
    forn(i,3) if(v[i]==n){ans+=t[i]; return;}
    if(v[0]*v[1]*v[2]>0){ans+=t; return;}
    forn(i,3) forr(j,i+1,3) if(v[i]>=2 and v[j]>=2) {ans+=t;; return;}
    if(n==2) forn(i,3) if(v[i]==0) {ans+=t[i];return;}
    forn(i,3) if(v[i]>=2) {ans+=t[(i+1)%3]; ans+=t[(i+2)%3]; return;}
}

int main() {
    FIN;
    solve();
    sort(all(ans));
    cout << ans << "\n";
    return 0;
}
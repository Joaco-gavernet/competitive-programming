#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"


int main() {
    FIN;
    int n, m; cin >> n >> m;
    vector <ii> v(m);
    forn(i,m){
        cin >> v[i].ff;
        v[i].ss=i+1;
    }
    vi ans;
    vi q;
    sort(all(v)); reverse(all(v));
    forn(_,1001) for(int i=m-1; i>0; i--) if(v[i].ff>0){
        v[i].ff--; q.pb(v[i].ss);
    }
    int j=0;
    while(j<SZ(q) and v[0].ff>0){
        ans.pb(v[0].ss); v[0].ff--;
        ans.pb(q[j]); j++;
        while(j<SZ(q) and ans[SZ(ans)-1]!=q[j] and SZ(q)-j>v[0].ff) {ans.pb(q[j]); j++;}
    }
    while(SZ(ans)>n) ans.pop_back();
    if(SZ(ans)<n) {cout << "-1\n"; return 0;}
    if(ans[0]==ans[n-1]){
        if(ans[1]==v[1].ss) {cout << "-1\n"; return 0;}
        ans[0]=v[1].ss;
    }
    forn(i,n) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"


typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

bool solve(int ids) {
    int dx, dy, n, q; cin >> dx >> dy >> n >> q;
    if(dx==0 or dy==0 or q==0) return false;
    cout << "Case " << ids << ":\n";
    vector <pair<ll,ii>> ans(q);
    vii c(n);
    forn(i,n) cin >> c[i].ff >> c[i].ss;
    vi d(q); 
    indexed_set s[4];
    vii ox(n), oy(n);
    forn(i,n){
        s[1].insert({c[i].ff+c[i].ss,i});
        ox[i]={c[i].ff,i}; oy[i]={c[i].ss,i};
    }
    forn(i,q) cin >> d[i];
    sort(all(ox)); sort(all(oy));
    int a=0, b=0;
    forr(y,1,dy+1){
        while(a<n and oy[a].ff==y){s[1].erase({c[oy[a].ss].ff+c[oy[a].ss].ss,oy[a].ss}); s[3].insert({c[oy[a].ss].ff-c[oy[a].ss].ss,oy[a].ss}); a++;}
        forr(x,1,dx+1){
            while(b<n and ox[b].ff==x){
                if(c[ox[b].ss].ss>y) {s[1].erase({c[ox[b].ss].ff+c[ox[b].ss].ss,ox[b].ss}); s[0].insert({-c[ox[b].ss].ff+c[ox[b].ss].ss,ox[b].ss});}
                else {s[3].erase({c[ox[b].ss].ff-c[ox[b].ss].ss,ox[b].ss}); s[2].insert({-c[ox[b].ss].ff-c[ox[b].ss].ss,ox[b].ss});}
                b++;
            }
            forn(t,q){
                ll tot=0;
                auto pt=s[1].lower_bound({d[t]+1+x+y,-1});
                if(pt==s[1].end()) tot+=SZ(s[1]);
                else tot+=ll(s[1].order_of_key(*pt));
                pt=s[0].lower_bound({d[t]+1-x+y,-1});
                if(pt==s[0].end()) tot+=SZ(s[0]);
                else tot+=ll(s[0].order_of_key(*pt));
                pt=s[3].lower_bound({d[t]+1+x-y,-1});
                if(pt==s[3].end()) tot+=SZ(s[3]);
                else tot+=ll(s[3].order_of_key(*pt));
                pt=s[2].lower_bound({d[t]+1-x-y,-1});
                if(pt==s[2].end()) tot+=SZ(s[2]);
                else tot+=ll(s[2].order_of_key(*pt));
                ans[t]=max(ans[t],{tot,{-y,-x}});
            }
        }
        b=0;
        forn(i,n){
            if(c[i].ss>y) {s[1].insert({c[i].ff+c[i].ss,i}); s[0].erase({-c[i].ff+c[i].ss,i});}
            else {s[3].insert({c[i].ff-c[i].ss,i}); s[2].erase({-c[i].ff-c[i].ss,i});}
        }
    }
    forn(i,q) cout << ans[i].ff << " " << "(" << -ans[i].ss.ss << "," << -ans[i].ss.ff << ")\n";
    return true; 
}

int main() {
    FIN;
    bool ans = true; 
    int i = 1; 
    while (ans) ans = solve(i++);
    return 0;
}
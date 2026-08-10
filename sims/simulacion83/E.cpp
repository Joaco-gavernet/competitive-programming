#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds; 

typedef int ll;
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


struct st2d {
    int n=1001; vector<vi> st; ll NEUT = 0;
    ll op(ll a, ll b) { return a + b; }
    st2d(){ st.resize(2*n + 5, vi(2*n+5, 0)); }
    void upd(int x, int y, ll v) {
        st[x + n][y + n] = v; 
        for (int j = y + n; j > 1; j >>= 1) st[x + n][j>>1] = op(st[x + n][j], st[x + n][j ^ 1]); 
        for (int i = x + n; i > 1; i >>= 1) for (int j = y + n; j; j >>= 1) st[i>>1][j] = op(st[i][j], st[i^1][j]); 
    }
    ll query(int x0, int x1, int y0, int y1) {
        ll r = NEUT; x1++, y1++; 
        for (int i0 = x0 + n, i1 = x1 + n; i0 < i1; i0 >>= 1, i1 >>= 1) {
            int t[4], q = 0;
            if (i0&1) t[q++] = i0++;
            if (i1&1) t[q++] = --i1; 
            forn(k,q) for (int j0 = y0 + n, j1 = y1 + n; j0 < j1; j0 >>= 1, j1 >>= 1) {
                if (j0&1) r = op(r, st[t[k]][j0++]);
                if (j1&1) r = op(r, st[t[k]][--j1]); 
            }
        }
        return r; 
    }
};

struct querie{
    ll sid, x, y, d;
    bool operator < (querie p) const { return d < p.d; }
};

bool solve(int ids) {
    int dx, dy, n, q; cin >> dx >> dy >> n >> q;
    if(dx==0 or dy==0 or q==0) return false;
    cout << "Case " << ids << ":\n";
    vii c(n);
    int xx[4]={-1,1,-1,1}, yy[4]={1,1,-1,-1};
    forn(i,n) cin >> c[i].ff >> c[i].ss;
    forn(_,q){
        int d; cin >> d;
        pair<ll,ii> ans;
        st2d s[4];
        vector <querie> qr;
        forr(x,1,dx+1) forr(y,1,dy+1) forn(j,4) qr.pb({j,x,y,d+x*xx[j]+y*yy[j]});
        sort(all(qr));
        vector <vii> v(4,vii(n));
        forn(j,4){
            forn(i,n) v[j][i]={c[i].ff*xx[j]+c[i].ss*yy[j],i};
            sort(all(v[j]));
        }
        vector<vi> tab(vector<vi>(dx+1,vi(dy+1)));
        vi k(4);
        for(auto [si,x,y,d] : qr){
            while(k[si]<n and v[si][k[si]].ff<=d){s[si].upd(c[v[si][k[si]].ss].ff,c[v[si][k[si]].ss].ss,1); k[si]++;}
            if(si==0) tab[x][y]+=s[si].query(1,x,y,dy);
            if(si==1) tab[x][y]+=s[si].query(x+1,dx,y,dy);
            if(si==2) tab[x][y]+=s[si].query(1,x,1,y-1);
            if(si==3) tab[x][y]+=s[si].query(x+1,dx,1,y-1);
        }
        forr(x,1,dx+1) forr(y,1,dy+1) ans=max(ans,{tab[x][y],{-y,-x}});
        cout << ans.ff << " " << "(" << -ans.ss.ss << "," << -ans.ss.ff << ")\n";
    }
    return true; 
}

int main() {
    FIN;
    bool ans = true; 
    int i = 1; 
    while (ans) ans = solve(i++);
    return 0;
}
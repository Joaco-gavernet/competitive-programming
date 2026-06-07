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


const ll MAXN = 2e5+5;
ll k, s; 

struct query {
    int l, r, ind; 
    bool operator < (query q) const {
        return r < q.r; 
    }
};
struct mo {
    const int block = 448;
    vector<vector<query>> q;
    vi ans;
    vector<multiset<ll>> cont;
    vb bound;
    mo() {
        ans.resize(MAXN), cont.resize(MAXN), bound.resize(MAXN);
        q.resize(MAXN/block+5);
    }
    void read_queries(int m) {
        ans.resize(m, 0);
        forn(i,m) {
            int l, r; cin >> l >> r;
            if(r-l+1<k) bound[i]=false;
            else {
                bound[i]=true;
                l--, r--; 
                q[l / block].pb({l, r, (int)i});
            }
        }
    }
    void add(ll &sum, ll val, ll id) {
        if (SZ(cont[id]) == 0) sum+=val;
        else if(*cont[id].rbegin()<val) sum+=val-*cont[id].rbegin();
        cont[id].insert(val);
    }
    void erase(ll &sum, ll val, ll id) {
        cont[id].erase(cont[id].find(val));
        if (SZ(cont[id]) == 0) sum-=val;
        else if(*cont[id].rbegin()<val) sum-=val-*cont[id].rbegin();
    }
    void get_mo(vi &v) {
        ll sum = s;
        forn(i,q.size()) {
            sort(all(q[i]));
            int l, r; l = r = block * i;
            for (query u : q[i]) {
                while (r <= u.r) add(sum, v[r],r%k), r++;
                while (l <= u.l) erase(sum, v[l],l%k), l++;
                while (l > u.l) l--, add(sum, v[l],l%k);
                if(sum>0) ans[u.ind] = (sum+k-1)/k;
                else ans[u.ind]=sum/k;
            }
            while (l < r) erase(sum, v[l],l%k), l++; 
        }
    }
};


int main() {
    NaN; 
    ll n; cin >> n >> k >> s;
    vi v(n);
    ll last=s;
    forr(i,k,n){
        ll x; cin >> x;
        v[i]=v[i-k]+x-last;
        last=x;
    }
    int q; cin >> q;
    mo moo;
    moo.read_queries(q);
    moo.get_mo(v);
    forn(i,q){
        if(moo.bound[i]) cout << moo.ans[i] << "\n";
        else cout << "unbounded\n";
    }
    return 0; 
}
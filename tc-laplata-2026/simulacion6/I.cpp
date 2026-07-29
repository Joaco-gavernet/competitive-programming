#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

#define DBGV(v) for(auto _:v) cerr<<_<<" "; cerr << endl

const ll INF = 1e18;


int main() {
    FIN;
    ll n; cin>>n;
    vi nums(n);
    forn(i,n) cin>>nums[i];
    vi prevrep(n,-INF);
    vi proxrep(n,INF);
    vi lastap(n,INF);
    set<ii> st;
    forn(i,n){
        st.insert({nums[i],i});
    }
    st.insert({INF,INF});
    for(ll pos=n-1;pos>=0;pos--){
        if(lastap[nums[pos]]<INF){
            proxrep[pos]=lastap[nums[pos]];
            prevrep[lastap[nums[pos]]]=pos;
        }
        lastap[nums[pos]]=pos;
    }
    vi rr(n),rl(n);
    rl[0]=0; rr[n-1]=n-1;
    forr(i,1,n) rl[i]=max(rl[i-1],prevrep[i]+1);
    for(ll i=n-2;i>=0;i--) rr[i]=min(rr[i+1],proxrep[i]-1);
    DBGV(rl); DBGV(rr); 
    set<ll> elems;
    forn(i,n+1) elems.insert(i+1);
    ll ans=0;
    ll r=0,p;
    elems.erase(nums[0]);
    forn(i,n){
        p=rr[i]+1;
        ll mex;
        while(r+1<p){
            mex=*(elems.begin());
            if(mex == 1 + r-i+1) ans++;
            DBG(r);
            // RAYA;
            ii pmex=*(st.lower_bound({mex,i}));
            if(pmex.ff == mex){
                DBG(pmex.ff);
                DBG(pmex.ss);
                while(r<pmex.ss){
                    elems.erase(nums[r+1]);
                    r++;
                    p=min(p,rr[r]+1);
                }
            }else break;
            DBG(r); DBG(p);
        }
        mex=*(elems.begin());
        if(mex == 1 + r-i+1) ans++;
        elems.insert(nums[i]);
        DBG(ans);
        RAYA;
    }
    cout<<ans<<"\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef long double ld;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"

const ld EPS = 1e-3;

struct inter{
    ld l, r; ll c;
    bool operator < (inter c) const{return l<c.l;}
};

int main() {
    FIN;
    ll n,q; cin>>n>>q;
    vector<pair<ld,ll>> queries;
    vi ans(q), restar(n*n+1);
    forr(l,1,n+1) forr(r,1,l) restar[(r-l)*(r-l)+r*r]+=(n+1-l)*(n+1-l);
    //forn(i,n*n+1) cout << restar[i] << " ";
    //cout << endl;
    forn(i,q){
        string s; cin>>s;
        ll t=SZ(s);
        if(s[t-1]=='0' and s[t-2]=='0'){
            ll num=stoi(s.substr(0,t-3));
            //Calculo raiz
            ll l=0,r=n+1;
            while(l+1<r){
                ll med=(l+r)/2;
                if(med*med > num) r=med;
                else l=med;
            }
            if(l*l==num and l< n){ans[i]=-1; continue;}
            if(l == n){ans[i]=1; continue;}
            ans[i]-=restar[num];
        }
        else if(s[t-1]=='0' and s[t-2]=='5'){
            ll num=stoi(s.substr(0,t-3));
            num=num*2+1;
            ll l=0,r=n+1;
            while(l+1<r){
                ll med=(l+r)/2;
                if(med*med > num) r=med;
                else l=med;
            }
            if(l*l==num and l<=n) ans[i]-=(n+1-l)*(n+1-l);
        }
        queries.pb({stod(s),i});
        // DBG(queries[i].ff);
    }
    vector <inter> v;
    forr(l,1,n+1){
        //cout << 0.5*l*l << " " << l*l << " " << (n+1-l)*(n+1-l) << endl;
        v.pb({0.5*l*l,ld(l*l),2*(n+1-l)*(n+1-l)});
    }
    forn(l,n) forn(d,(n-l)/2+1){
        //cout << (l*l) << " " << ld(2*(d+l)*d+l*l) << " " << 4*(n-l-2*d) << endl; 
        if(l>0){
            if(4*(n-l-2*d)!=0) v.pb({ld(l*l),ld(2*(d+l)*d+l*l),8*(n-l-2*d)});
            else v.pb({ld(l*l),ld(2*(d+l)*d+l*l),2});
        }
        else{
            if(4*(n-l-2*d)!=0) v.pb({ld(l*l),ld(2*(d+l)*d+l*l),4*(n-l-2*d)});
            else v.pb({ld(l*l),ld(2*(d+l)*d+l*l),1});
        }
    }
    sort(all(v)); sort(all(queries));
    int j=0;
    ll cont=0;
    priority_queue <pair<ld,ll>> p;
    //forn(i,q) cout << ans[i] << " ";
    //cout << endl;
    for(auto [ar,i] : queries){
        //cout << ar << endl;
        //DBG(cont);
        while(j<SZ(v) and v[j].l<=ar+EPS){cont+=v[j].c; p.push({-v[j].r,v[j].c}); j++;}
        //DBG(cont); DBG(SZ(p)); DBG(p.top().ff);
        while(SZ(p)>0 and -p.top().ff<ar+EPS){cont-=p.top().ss; p.pop();}
        //DBG(cont); DBG(SZ(p));
        //RAYA;
        ans[i]+=cont;
    }
    forn(i,q) cout << ans[i] << "\n";
    //cout << endl;
    return 0; 
}
#include <bits/stdc++.h>
using namespace std; 

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
using ld = long double;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"


int main() {
    FIN; 
    ll n,m; cin>>n>>m;
    ll sn=0; ll sm=0;
    vector<ii> intsa,intsb;
    bool disca=true,discb=true;
    forn(i,n){
        ll x,y; cin>>x>>y;
        if(y>x) disca=false;
        sn+=(y-x);
        intsa.pb({x,y});
    }
    forn(i,m){
        ll x,y; cin>>x>>y;
        if(y>x) discb=false;
        sm+=(y-x);
        intsb.pb({x,y});
    }
    if(disca) sn=n;
    if(discb) sm=m;
    sort(all(intsa)); sort(all(intsb));
    ld pfija=1; pfija/=sn; pfija/=sm;   //Prob base de cada intervalo
    ld um=0.5
    ls term1a=0,term2a=0,term1b=0,term2b=0;
    vi candsa,candsb;
    for(auto u:intsa){
        candsa.pb(u.ss);
    }
    for(auto u:intsb){
        candsb.pb(u.ss);
    }
    ll suma=0,ca=0;
    ll sumb=0,cb=0;
    ll tot=n+m;
    ll pa=0; ll pb=0;
    ld ans=0;
    forn(i,tot){
        if(pa<n and pb<m){
            if(candsa[pa]<=candsb[pb]){
                ld aux=0,t2=0,t1=0;
                if(disca){
                    t1=candsa[pa].ss; t2=1;
                    term2a+=candsa[pa];
                    suma+=candsa[pa];
                    ca++;
                    if(discb){
                        ans+=(cb*candsa[pa]-sumb);
                    }else{
                        t2*=term2b/2;
                        t1*=term1b;
                        aux=t1-t2;
                        ans+=aux;
                    }
                }
                else{
                    t2=intsa[pa].ss-intsa[pa].ff;
                    t1=(intsa[pa].ss)*(intsa[pa].ss)-(intsa[pa].ff)*(intsa[pa].ff);
                    term1a+=t2; term2a+=t1;
                    t2*=term2b; if(!discb) t2/=2;
                    t1*=term1b/2;
                    aux=t1-t2;
                    ans+=aux;
                }          
                
                pa++;
            }else{
                ld aux=0,t2=0,t1=0;
                if(discb){
                    t1=candsb[pb].ss; t2=1;
                    term2b+=candsb[pb];
                    sumb+=candsb[pb];
                    cb++;
                    if(disca){
                        ans+=(ca*candsb[pb]-suma);
                    }else{
                        t2*=term2a/2;
                        t1*=term1a;
                        aux=t1-t2;
                        ans+=aux;
                    }
                }
                else{
                    t2=intsb[pb].ss-intsb[pb].ff;
                    t1=(intsb[pb].ss)*(intsb[pb].ss)-(intsb[pb].ff)*(intsb[pb].ff);
                    term1b+=t2; term2b+=t1;
                    t2*=term2a; if(!disca) t2/=2;
                    t1*=term1a/2;
                    aux=t1-t2;
                    ans+=aux;
                }  

                pb++;
            }
        }else if(pa<n){
            ld aux=0,t2=0,t1=0;
            if(disca){
                t1=candsa[pa].ss; t2=1;
                term2a+=candsa[pa];
                suma+=candsa[pa];
                ca++;
                if(discb){
                    ans+=(cb*candsa[pa]-sumb);
                }else{
                    t2*=term2b/2;
                    t1*=term1b;
                    aux=t1-t2;
                    ans+=aux;
                }
            }
            else{
                t2=intsa[pa].ss-intsa[pa].ff;
                t1=(intsa[pa].ss)*(intsa[pa].ss)-(intsa[pa].ff)*(intsa[pa].ff);
                term1a+=t2; term2a+=t1;
                t2*=term2b; if(!discb) t2/=2;
                t1*=term1b/2;
                aux=t1-t2;
                ans+=aux;
            }  
            pa++;
        }else{
            ld aux=0,t2=0,t1=0;
            if(discb){
                t1=candsb[pb].ss; t2=1;
                term2b+=candsb[pb];
                sumb+=candsb[pb];
                cb++;
                if(disca){
                    ans+=(ca*candsb[pb]-suma);
                }else{
                    t2*=term2a/2;
                    t1*=term1a;
                    aux=t1-t2;
                    ans+=aux;
                }
            }
            else{
                t2=intsb[pb].ss-intsb[pb].ff;
                t1=(intsb[pb].ss)*(intsb[pb].ss)-(intsb[pb].ff)*(intsb[pb].ff);
                term1b+=t2; term2b+=t1;
                t2*=term2a; if(!disca) t2/=2;
                t1*=term1a/2;
                aux=t1-t2;
                ans+=aux;
            }  
            pb++;
        }
    }
    ans*=pfija;
    cout<<fixed<<setprecision(10);
    cout<<ans<<"\n";
    return 0; 
}
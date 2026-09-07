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
    cout<<fixed<<setprecision(10);
    ll n,m; cin>>n>>m;
    ll sn=0; ll sm=0;
    vector<ii> intsa,intsb;
    // ll sn=0; ll sm=0;
    bool disca=true,discb=true;
    forn(i,n){
        ll x,y; cin>>x>>y;
        if(y>x){
            disca=false;
        }
        sn+=(y-x);
        intsa.pb({x,y});
    }
    forn(i,m){
        ll x,y; cin>>x>>y;
        if(y>x){
            discb=false;
        }
        sm+=(y-x);
        intsb.pb({x,y});
    }
    if(disca) sn=n;
    if(discb) sm=m;
    if(!disca and discb){
        swap(n,m);
        swap(intsa,intsb);
        swap(disca,discb);
        swap(sn,sm);
    }
    ld ans=0;
    ld pfija=1; pfija/=sn; pfija/=sm;
    if(disca and discb){    //ambos discretos
        ll psum=0;
        ll tot=0;
        forn(i,m) tot+=intsb[i].ss;
        ll posb=0;
        forn(i,n){
            while(posb<m and intsb[posb].ss < intsa[i].ss){
                psum+=intsb[posb].ss;
                posb++;
            }
            ans+=(posb*intsa[i].ss-psum);
            ans+=((tot-psum)-(m-posb)*intsa[i].ss);
            // cout<<ans<<"\n";
        }
        ans*=pfija;
        cout<<ans<<"\n";
    }else if(disca){    //solo a discreto
        ll posb=0;
        forn(i,n){
            ld sumaizq=0;
            ld sumaizq2=0;
            ld sumader=0;
            ld sumader2=0;
            forn(i,m){
                sumader2+=(ld)(intsb[i].ss*intsb[i].ss-intsb[i].ff*intsb[i].ff)/2;
                sumader+=(intsb[i].ss-intsb[i].ff);
            }
            while(posb<m and intsb[posb].ss < intsa[i].ff){
                sumaizq+=(intsb[posb].ss-intsb[posb].ff);
                sumader-=(intsb[posb].ss-intsb[posb].ff);
                sumaizq2+=(ld)(intsb[i].ss*intsb[i].ss-intsb[i].ff*intsb[i].ff)/2;
                sumader2-=(ld)(intsb[i].ss*intsb[i].ss-intsb[i].ff*intsb[i].ff)/2;
                posb++;
            }
            DBG(sumader);
            DBG(sumader2);
            ld va=intsa[i].ff;
            ans+=(va*sumaizq-sumaizq2);
            if(posb<m){
                ld lb=intsb[posb].ff;
                ld rb=intsb[posb].ss;
                // cout<<lb<<"\n";
                // cout<<rb<<"\n";
                // cout<<va<<"\n";
                // cout<<ans<<" ";
                
                if(lb<va){
                    ans+=(va*(va-lb)-(ld)(va*va-lb*lb)/2);
                    // cout<<ans<<" ";
                    ans+=((ld)(rb*rb-va*va)/2-va*(rb-va));
                    // cout<<ans<<" ";
                    sumader-=(intsb[posb].ss-intsb[posb].ff);
                    sumader2-=(ld)(intsb[i].ss*intsb[i].ss-intsb[i].ff*intsb[i].ff)/2;
                }
                ans+=(sumader2-va*sumader);
                // cout<<ans<<"\n";
            }
        }
        ans*=pfija;
        cout<<ans<<"\n";
    }else{  //los 2 continuos
        vector <ii> event;
        forn(i,n) {event.pb({intsa[i].ff,1}); event.pb({intsa[i].ss,-1});}
        forn(i,m) {event.pb({intsb[i].ff,1}); event.pb({intsb[i].ss,-1});}
        sort(all(event));
        ll cont=0, l;
        for(auto [x,t] : event){
            cont+=t;
            if(t==1 and cont==2) l=x;
            if(t==-1 and cont==1) ans+=ld(x-l)*(x-l)*(x-l)/3;
        }
        int i=0;
        set <ii> ints;
        ll  sa=0, s=0, d=0, c=0, s2=0, a2=0;
        forn(j,m){
            while(i<n and intsa[i].ff<=intsb[j].ff){
                 ints.insert({intsa[i].ss,intsa[i].ff});
                sa+=intsa[i].ff; 
                a2+=intsa[i].ff*intsa[i].ff;
                c++; i++;
            }
            while(SZ(ints)>0){
                ii z=*ints.begin();
                if(z.ff>intsb[j].ff) break;
                sa-=z.ss;
                a2-=z.ss*z.ss;
                s2+=z.ff*z.ff+z.ss*z.ss;
                s+=z.ff+z.ss;
                d+=z.ff-z.ss;
                c--;
            }
            ans+=0.5*(intsb[j].ss-intsb[j].ff)*(intsb[j].ff+intsb[j].ss)*d;
            ans+=0.5*(intsb[j].ss-intsb[j].ff)*(intsb[j].ff+intsb[j].ss)*(c*intsb[j].ff-sa);
            ans+=0.5*(intsb[j].ss-intsb[j].ff)*s2;
            ans+=0.5*(intsb[j].ss-intsb[j].ff)*(c*intsb[j].ff*intsb[j].ff-a2);
        }
        ans*=pfija;
        cout<<ans<<"\n";
    }
    return 0; 
}

// vector<ii> intdivb;
        // vector<ii> intdiva;
        // ll posb=0;
        // forn(i,n){
        //     while(posb<m and intsb[posb].ss<=intsa[i].ff){intdivb.pb(intsb[posb]); posb++;}
        //     if(posb==m) break;
        //     ll lb=intsb[posb].ff; ll rb=intsb[posb].ss;
        //     ll la=intsa[i].ff; ll ra=intsa[i].ss;
        //     if(lb>=ra) continue;
        //     if(lb<la){
        //         intdivb.pb({lb,la});
        //         if(rb<ra){
        //             intdivb.pb({la,rb});
        //             intdiva.pb({la,rb});
        //             posb++;
        //             intdiva.pb({rb,ra});
        //         }else{
        //             intdiva.pb({la,ra});
        //             intdivb.pb({la,ra});
        //             // intdivb.pb({ra,rb});
        //             if(rb>ra) intsb[posb].ff=ra;
        //             else posb++;
        //         }
        //     }else{
        //         if(lb>la){
        //             intdiva.pb({la,lb});
        //         }
        //         if(rb<ra){
        //             intdiva.pb({lb,rb});
        //             intdivb.pb({lb,rb});
        //             posb++;
        //             intdiva.pb({rb,ra});
        //         }else{
        //             intdiva.pb({lb,ra});
        //             intdivb.pb({lb,ra});
        //             if(rb>ra) intsb[posb].ff=ra;
        //             else posb++;
        //             // intdivb.pb({ra,rb});
        //         }
        //     }
        // }
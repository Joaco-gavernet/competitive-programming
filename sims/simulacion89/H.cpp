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
#define RAYA cerr << "=========================\n"

void solve(){
    ll lm,rm,lb,rb; cin>>lm>>rm>>lb>>rb;
    ll cantm=rm-lm+1;
    ll cantb=rb-lb+1;
    ll r=min(cantm,cantb/2+1);
    ll l=0;
    ll offset=(lm-lb);    //que tanta ventaja tiene la suma de los m contra los b
    //lm y lb arrancan en 0
    //con los numeros del 0 al 2k-1, quiero sumar una escalera
    //que termine en cantm-1-offset y sea lo mas grande posible
    ll med=(l+r)/2;
    while(l+1<r){
        //DBG(med);
        ll chico=(cantm-1)-(med-1);
        ll d=lm+rm-2*lb-med+1;
        if(med%2){
            ll corte=(3*(med/2))+1;
            if(corte<=d) l=med;
            else r=med;
        }else{
            ll corte=(3*(med/2));
            if(corte<=d) l=med;
            else r=med;
        }
        med=(l+r)/2;
    }
    cout<<l<<'\n';
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0; 
}
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
#define DBG(x) cerr << #x <<  " = " << x << endl
#define RAYA cerr << "==================\n"



int main() {
    FIN;
    ll n,m; cin>>n>>m;
    vector<vi> vers(n,vi(m));
    vector<vi> tl(n,vi(m));
    vector<vi> ml(n,vi(m));
    forn(i,n) forn(j,m){
        string s; cin>>s;
        string ver=s.substr(0,2);
        if(ver=="OK") vers[i][j]=0;
        if(ver=="WA") vers[i][j]=1;
        if(ver=="TL") vers[i][j]=2;
        if(ver=="ML") vers[i][j]=3;
        if(ver=="RE") vers[i][j]=4;
        ll pos=3;
        ll tiempo=0,memoria=0;
        while(s[pos]!='/'){
            tiempo*=10;
            tiempo+=(s[pos]-'0');
        }
        tl[i][j]=tiempo;
        pos++;
        while(s[pos]!='/'){
            memoria*=10;
            memoria+=(s[pos]-'0');
        }
        ml[i][j]=memoria;
    }
    vector<pair<ll,ii>> result(m);
    forn(j,m){
        ll mt=0,mm=0;
        // bool fin=false;
        forn(i,n){
            if(vers[i][j]>0){
                result[j]={vers[i][j],{tl[i][j],ml[i][j]}};
                // fin=true;
                break;
            }
            else mt=max(mt,tl[i][j]);
            else mm=max(mm,ml[i][j]);
        }
        result[j]={0,{mt,mm}};
        // if(fin) continue;
    }
    vector<bool> done(m,false);
    forn()



    return 0; 
}
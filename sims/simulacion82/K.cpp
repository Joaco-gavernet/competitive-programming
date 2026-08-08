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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=======================\n"

void solve(){
    vector<pair<ll,char>> cards(5);
    forn(i,5){
        char n,p; cin>>n>>p;
        cards[i].ss=p;
        if(n=='T') cards[i].ff=10;
        else if(n=='J') cards[i].ff=11;
        else if(n=='Q') cards[i].ff=12;
        else if(n=='K') cards[i].ff=13;
        else if(n=='A') cards[i].ff=14;
        else cards[i].ff=(n-'0');
    }
    pair<ll,char> mine1,mine2;
    mine1=cards[0];
    mine2=cards[1];
    if(mine1>mine2) swap(mine1,mine2);
    sort(all(cards));
    //Check str flush
    bool sf=true;
    bool posroyal=false;
    forr(i,1,5){
        if(cards[i].ff!=cards[i-1].ff+1 or cards[i].ss!=cards[i-1].ss){
            if(i==4 and cards[i].ff==14 and cards[0].ff==2 and cards[i].ss==cards[i-1].ss){
                sf=true;
                cards[4].ff=1;
                sort(all(cards));
                posroyal=true;
                break;
            }else{
                sf=false;
                break;
            }
        }
    }
    if(sf and cards[0].ff==10){ //Case royal
        cout<<"allin\n";
        return;
    }
    if(!sf){    //Not straight. always lose
        cout<<"check\n";
        return;
    }
    //If sflush i have to check next 4 stairs
    vb notmines(15,true);
    notmines[mine1.ff]=false;
    notmines[mine2.ff]=false;
    ll tope=cards[4].ff+1;
    ll cont=0;
    bool puede=false;
    while(cont<4 and tope<=14){
        if(notmines[tope] and notmines[tope-1] and notmines[tope-2] and notmines[tope-3] and notmines[tope-4]){
            puede=true;
        }
        cont++;
        tope++;
    }
    if(posroyal){
        tope=14;
        if(notmines[tope] and notmines[tope-1] and notmines[tope-2] and notmines[tope-3] and notmines[tope-4]){
            puede=true;
        }
    }
    if(puede){
        cout<<"check\n";
        return;
    }else{
        cout<<"allin\n";
        return;
    }
    return;
}

int main() {
    FIN;
    ll t; cin>>t;
    while(t--) solve();
    return 0; 
}
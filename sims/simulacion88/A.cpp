#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"

ll decode(vector<string> &pant,ll col){
    if(pant[0][col]=='.' and pant[0][col+4]=='.') return -1;
    if(pant[0][col]=='.' and pant[0][col+4]=='x') return 1;
    if(pant[0][col+1]=='.') return 4;
    if(pant[6][col]=='.') return 7;
    if(pant[3][col+2]=='.') return 0;
    bool a=(pant[1][col]=='x');
    bool b=(pant[1][col+4]=='x');
    bool c=(pant[5][col]=='x');
    bool d=(pant[5][col+4]=='x');
    if(a and b and c and d) return 8;
    if(a and b and !c and d) return 9;
    if(a and !b and c and d) return 6;
    if(a and d) return 5;
    if(b and d) return 3;
    if(b and c) return 2;
    return -2;
}

void imprimir(vi &ans,ll n){
    string v=".....";
    string m="x...x";
    string x="xxxxx";
    string l="x....";
    string r="....x";
    vector<vector<string>> nums;
    nums.pb({x,m,m,m,m,m,x});
    nums.pb({r,r,r,r,r,r,r});
    nums.pb({x,r,r,x,l,l,x});
    nums.pb({x,r,r,x,r,r,x});
    nums.pb({m,m,m,x,r,r,r});
    nums.pb({x,l,l,x,r,r,x});
    nums.pb({x,l,l,x,m,m,x});
    nums.pb({x,r,r,r,r,r,r});
    nums.pb({x,m,m,x,m,m,x});
    nums.pb({x,m,m,x,r,r,x});
    forn(pos,7){
        forn(i,n-1){
            cout<<nums[ans[i]][pos]<<".";
        }
        cout<<nums[ans[n-1]][pos];
        cout<<"\n";
    }
    return;
}

int main() {
    FIN;
    vector<string> pant(7);
    forn(i,7) cin>>pant[i];
    ll n=SZ(pant[0]);
    // DBG(n);
    n++; n/=6;
    // DBG(n);
    ll a=0,b=0;
    bool fina=false;
    ll cont=0;
    while(!fina){
        ll dig=decode(pant,cont*6);
        if(dig==-1) fina=true;
        else{a*=10; a+=dig;}
        cont++;
        // RAYA;
        // DBG(cont);
    }
    while(cont<n){
        ll dig=decode(pant,cont*6);
        b*=10; b+=dig;
        cont++;
        // RAYA;
    }
    // DBG(a); 
    // DBG(b); 
    ll sum=a+b;
    vi ans;
    while(sum>0){
        ll c=sum%10;
        sum-=sum%10; sum/=10;
        ans.pb(c);
    }
    // RAYA;
    reverse(all(ans));
    imprimir(ans,SZ(ans));
    return 0; 
}
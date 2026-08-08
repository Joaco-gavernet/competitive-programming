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

const ll MOD = 998244353;

int main() {
    FIN;
    string s; cin>>s;
    ll n=SZ(s);
    vi ss(n);
    vector<vi> histo(n+1,vi(62,0));
    forr(i,1,n+1){
        histo[i]=histo[i-1];
        char c=s[i-1];
        if(c<='z' and c>='a') c=c-'a';
        if(c<='Z' and c>='A') c=c-'A'+26;
        else c=(c-'0')+52;
        ss[i-1]=c;
        histo[i][c]++;
    }
    ll contduplrep=0;
    ll ans=0;
    vector<vi> pairs3(62,vi(62,0));
    vector<vi> pairs4(62,vi(62,0));
    forn(i,n){
        ll c=ss[i];
        forn(prox,62) if(prox!=c){  //Medio 34
            ll cant = i - histo[i][c] - histo[i][prox];
            ll cantidades = (cant*(cant-1))/2 - contduplrep;
            cantidades+=(histo[i][c]*(histo[i][c]-1)/2);
            cantidades+=(histo[i][prox]*(histo[i][prox]-1)/2);
            pairs3[c][prox]=(pairs3[c][prox]+cantidades)%MOD;
        }
        contduplrep=(contduplrep+histo[i][c])%MOD;
        forn(prev,62) if(prev!=c){  //Viendo desde la cuarta posicion
            pairs4[prev][c]=(pairs4[prev][c]+pairs3[prev][c])%MOD;
        }
        forn(prev,62) if(prev!=c){  //Viendo desde la quinta posicion
            ll aux=pairs4[c][prev];
            ll extras=(histo[n][prev]-histo[i+1][prev]);
            aux=(aux*extras)%MOD;
            ans=(ans+aux)%MOD;
        }
    }
    cout<<ans<<"\n";

    return 0; 
}
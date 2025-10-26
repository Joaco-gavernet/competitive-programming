#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

const ll MOD = 998244353;

ll be(ll x, ll y){
  if(y==0) return 1;
  ll p=be(x,y/2)%MOD;
  p=(p*p)%MOD;
  return (y%2==0)? p : (x*p)%MOD;
}

vi fact={1};

void solve(){
  string s; cin>>s;
  ll n=SZ(s);
  vector<vi> ps(n+1,vi(26,0));
  forn(i,n){
    ps[i+1]=ps[i];
    ps[i+1][s[i]-'a']++;
  }
  ll q; cin>>q;
  forn(i,q){
    string op; cin>>op;
    if(op=="INSIDE"){
      ll l,r; cin>>l>>r;
      string w; cin>>w;
      vi histo(26,0);
      forn(x,SZ(w)) histo[w[x]-'a']++;
      vi comp(26,0);
      ll cont=0;
      forn(x,26){
        comp[x]=ps[r][x]-ps[l-1][x];
        if(comp[x]==histo[x]) cont++;
      }
      if(cont==26) cout<<"YES\n";
      else cout<<"NO\n";
    }else{
      ll l,r; cin>>l>>r;
      ll tam=r-l+1;
      ll coc=1;
      forn(x,26){
        ll aux=ps[r][x]-ps[l-1][x];
        if(aux>1) coc=(coc*fact[aux])%MOD;
      }
      //DBG(tam);
      ll ans=fact[tam];
      ans=(ans*be(coc,MOD-2))%MOD;
      cout<<ans<<"\n";
    }
    //RAYA;
  }

}


int main() {
  FIN; 
  forn(i,1e6+5) fact.pb((fact[i]*(i+1))%MOD);
  ll t; cin>>t;
  while(t--) solve();
  
  return 0; 
} 

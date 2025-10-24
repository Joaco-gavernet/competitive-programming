#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================" << endl
#define ff first
#define ss second

const ll INF=1e18+7;

vi min_prime;

vi criba(ll n) {
  vb prime(n+1, true); 
  min_prime.resize(n+1, INF); 
  vi primos;
  for (ll p = 2; p*p <= n; p++) {
    if (!prime[p]) continue;
    for (ll i = p*p; i <= n; i+= p) {
      prime[i] = false;
      min_prime[i] = min(min_prime[i], p);
    }
  }
  forr(i, 2, n+1) {
    if (prime[i]) primos.pb(i), min_prime[i] = i;
  }
  return primos; 
}

int main() {
  FIN;
  vi primos=criba(1e5);
  ll n; cin>>n;
  string s; cin>>s;
  ll k; cin>>k;
  vi costos(26,0);
  forn(i,k){
    char c; cin>>c;
    ll x; cin>>x;
    costos[c-'A']=x;
  }
  ll p;
  ll pot=0;
  for(auto u:primos) if(n%u==0){
    p=u;
    ll n2=n;
    while(n2%u==0 and n2>1){
      pot++;
      n2/=u;
    }
    break;
  }
  vi fact={1};
  ll aux=1;
  forn(i,pot){aux*=p; fact.pb(aux);}
  
  vector<vii> histo(pot+1,vii(n,vi(26,0)));
  vii indecisos(pot+1,vi(n,0));
  forn(i,n) forn(potencia,pot+1){
    if(s[i]=='?') indecisos[potencia][i%fact[potencia]]++;
    else histo[potencia][i%fact[potencia]][s[i]-'A']++;
  }

  vii dp(pot+1,vi(n,0));
  ll ans=0;
  ll cont=0;
  for(ll potencia=pot; potencia>=0; potencia--){
    //DBG(potencia);
    cont++;
    ll ansfila=0;
    forn(elem,fact[potencia]){
      //DBG(elem);
      ll anselem=0;
      ll amount=(n/fact[potencia]);
      forn(letra,26){ 
        if(histo[potencia][elem][letra]+indecisos[potencia][elem]==amount){
          dp[potencia][elem]=max(costos[letra]*amount*cont,dp[potencia][elem]);
        }
      }
      ll contaux=0;
      if(potencia<pot) for(ll extra=elem;extra<fact[potencia+1]; extra+=fact[potencia]){
        contaux+=dp[potencia+1][extra];
      }
      dp[potencia][elem]=max(contaux,dp[potencia][elem]);
      anselem=dp[potencia][elem];
      //DBG(anselem);
      ansfila+=anselem;
    }

    ans=max(ans,ansfila);
  }

  cout<<ans<<"\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"


struct Hash {
  const ll P = 1'777'771;
  const ll MOD[2] = {999727999, 1070777777};
  const ll PI[2] = {325255434, 10018302};

  vi h[2], pi[2];
  Hash(string &s) {
    forn(k,2) h[k].resize(SZ(s) +1), pi[k].resize(SZ(s) +1); 
    forn(k,2) {
      h[k][0] = 0; pi[k][0] = 1;
      ll p = 1; 
      forr(i,1,SZ(s) +1) {
        h[k][i] = (h[k][i-1]+p*s[i-1]) %MOD[k];
        pi[k][i] = (1LL*pi[k][i-1]*PI[k]) %MOD[k];
        p = (p*P) %MOD[k];
      }
    }
  }
  ll get(ll s, ll e) {
    e++;
    ll h0 = (h[0][e] -h[0][s] +MOD[0]);
    h0 = (1LL*h0*pi[0][s]) %MOD[0];
    ll h1 = (h[1][e] -h[1][s] +MOD[1]);
    h1 = (1LL*h1*pi[1][s]) %MOD[1];
    return (h0<<32)|h1; 
  }
};


int main() {
  FIN;
  string p; cin>>p;
  ll k=SZ(p);
  p+=p;
  ll n; cin>>n;
  Hash comp(p);
  map<ll,ll> visto;
  ll ans=0;
  forn(i,k){
    forr(len,1,k+1){
      ll cant=0;
      ll h=comp.get(i,i+len-1);
      if(!visto[h] and i+len-1<n){
        cant=1;
        visto[h]=1;
        if(len==k) cant+=(n-(i+len));
      }
      ans+=cant;
    }
  }
  cout<<ans<<"\n";
  return 0; 
}

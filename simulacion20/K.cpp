#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(c) int((c).size())


struct Hash {
  const ll P = 1777771;
  const ll MOD[2] = {999727999, 1070777777};
  const ll PI[2] = {325255434, 10018302};
  
  vector<ll> h[2], pi[2];
  Hash (string &s) {
    forn(k,2) h[k].resize(s.size()+1), pi[k].resize(s.size()+1);
    forn(k,2) {
      h[k][0] = 0; pi[k][0] = 1;
      ll p = 1;
      forr(i,1,s.size()+1) {
	h[k][i] = (h[k][i-1]+p*s[i-1]) %MOD[k];
	pi[k][i] = (1LL*pi[k][i-1] * PI[k]) %MOD[k];
	p = (p*P)%MOD[k];
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
  string s;
  cin >> s; 
  Hash h(s);
  int n = int(s.size());
  string respuesta = s;
  int l =0;
  int r = n;
  while (r-l > 1){
      int med = (l+r)/2;
      med--;
      map <ll, int> cont;
      for (int i=0; i<(n-med); i++) cont[h.get(i, i+med)]++;
      bool listo=false;
      for (int j=0; j<(n-med); j++){
	if(cont[h.get(j, j+med)] == 1){
	  listo=true;
	  respuesta = s.substr(j, med+1);
	  break;
	}
      }
      med++;
      if(listo) r = med;
      else l = med;
  }
  cout << respuesta;
  FIN; 
  
  
  return 0;
}

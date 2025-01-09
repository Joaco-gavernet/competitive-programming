#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
const double EPS=1e-10;



int main() {
  FIN;
  cout<<fixed<<setprecision(7);
  vector<vector<char>> mat(7,vector<char>(24));
  forn(i,7){
    forn(j,24){
      cin>>mat[i][j];
    }
  }
  ll d,h; cin>>d>>h;
  double ansmax=0;
  forn(mask,128){
    vi act(7,0); ll cont=0;
    ll n=mask;
    ll pos=0;
    while(n){
      if(n%2){
	cont++;
	act[pos]++;
      }
      pos++;
      n/=2;
    }
    if(cont>=d){
      vi horas(24,0);
      forn(i,7){
	if(act[i]){
	  forn(j,24){
	    if(mat[i][j]=='.') horas[j]++;
	  }
	}
      }
      sort(all(horas));
      reverse(all(horas));
      ll sum=0;
      forn(i,h) sum+=horas[i];
      ll proxh=h;
      if(h<24){
	double cact=(double)sum/(proxh*cont); 
	double cprox=(double)(sum+horas[proxh])/((proxh+1)*cont);
	while(proxh<24 and cact<cprox){
	  sum+=horas[proxh];
	  proxh++;
	  cact=(double)sum/(proxh*cont); 
	  cprox=(double)(sum+horas[proxh])/((proxh+1)*cont);
	}
	ansmax=max(ansmax,cact);
      }
      else ansmax=max(ansmax,(double)sum/(h*cont));
    }
  }
  cout<<ansmax<<"\n";
  return 0;
}

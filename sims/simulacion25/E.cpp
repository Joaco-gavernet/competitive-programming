#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n" 


ll gcd(ll a,ll b){
  if(b==0) return a;
  else return gcd(b,a%b);
}

int main() {
  FIN; 
  ll n; cin>>n;
  vector<double> x(n);
  int posmin=0; 
  forn(i,n) {
    string s; cin >> s; 
    x[i] = stold(s);
    if(x[i]<x[posmin]) posmin=i; 
  }
  swap(x[0],x[posmin]);
  vector<ll> rec(n);
  int r1=1;
  double d,dp;
  ll mcd,sum=0;
  while(r1<10001){
    d=(double)r1/x[0];
    rec[0]=r1;
    mcd=rec[0];
    sum=rec[0]*rec[0];
    forr(i,1,n){
      if(d*x[i]-floor(d*x[i])>=0.5) rec[i]=ceil(d*x[i]);
      else rec[i]=floor(d*x[i]);
      mcd=gcd(mcd,rec[i]);
      sum+=(rec[i]*rec[i]);
    }
    //~ if(r1==5){
      //~ for(auto u:rec) cout<<u<<" ";
    //~ }
    if(mcd==1){
      dp = sqrt(sum);
      //~ cout<<dp<<endl;
      bool corte=true;
      forn(i,n){
	double aux=(double)rec[i]/dp;
	//~ if(aux<0) aux=aux*(-1);
	if(abs(aux-x[i])>1e-6){corte=false; break;} 
      }
      if(corte){
	swap(rec[0],rec[posmin]);
	forn(i,n){
	  cout<<rec[i]<<"\n";
	}
	//~ cout<<"\n";
	return 0;
      }
    }
    r1++;
  }
  return 0;
}

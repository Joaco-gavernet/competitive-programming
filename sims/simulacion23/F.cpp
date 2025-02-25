#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = 1e9+7;
const int INF = -1;
const int MOD = -1;

int main() {
  FIN; 
  ll r,s,h; cin>>r>>s>>h;
  ll m1=0,m2=0,m3=0;
  long double difmax=MAXN;
  long double dif;
  long double elem=2*r*acos(-1);
  ll d=(elem)/(s*h);
  elem=elem /(s*h);
  if(elem-d>=0.5){
    //~ d++;
    for(int n1=2; n1<=250; n1++){
      for(int c=2; c*n1<=500; c++){
	for(int k=2; k*c*n1<=1000; k++){
	  long double e1=1,e2=1,e3=1;
	  e1=e1/n1;
	  e2=e2/(c*n1);
	  e3=e3/(c*k*n1);
	  dif=d+1-e1+e2-e3;
	  long double aux=elem-dif;
	  if(aux<0) aux=aux*(-1);
	  if(aux<difmax){
	    difmax=aux; m1=n1; m2=c*n1; m3=k*c*n1;
	  }
	}
      }
    }
    cout<<m1<<" "<<m2<<" "<<m3<<"\n";
  }else{
    for(int n1=2; n1<=250; n1++){
      for(int c=2; c*n1<=500; c++){
	for(int k=2; k*c*n1<=1000; k++){
	  long double e1=1,e2=1,e3=1;
	  e1=e1/n1;
	  e2=e2/(c*n1);
	  e3=e3/(c*k*n1);
	  dif=d+e1-e2+e3;
	  long double aux=elem-dif;
	  if(aux<0) aux=aux*(-1);
	  if(aux<difmax){
	    difmax=aux; m1=n1; m2=c*n1; m3=k*c*n1;
	  }
	}
      }
    }
    cout<<m1<<" "<<m2<<" "<<m3<<"\n";
  }
  return 0;
}

#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"

const long double eps=1e-10;

int main() {
  FIN;
  int d; cin>>d;
  ll anspos=0,ansneg=0;
  long double p; cin>>p;
  long double pinv=1;
  pinv=pinv/p;
  vector<int> dat(d); forn(i,d) cin>>dat[i];
  vector<int> difs(d-1); forn(i,d-1) difs[i]=dat[i+1]-dat[i];
  forn(i,d-1){
    long double sum2=difs[i],sumc2=difs[i]*difs[i];
    long double cont2=1;
    forr(j,i+1,d-1){
      sum2=sum2+difs[j]; 
      sumc2=sumc2+(difs[j]*difs[j]);
      cont2=cont2+1;
      long double A2=sum2/cont2;
      long double D2=(sumc2/cont2)-(A2*2*sum2/cont2)+(A2*A2);
      D2=sqrtl(D2);
      //~ frac2=sqrtl(frac2)
      long double frac2=A2;
      if(D2>0) frac2=A2/D2;
      //~ DBG(A2); DBG(frac2);
      if(A2>0){
	if(D2==0 or frac2-eps>=p) anspos++;
      }else if(A2<0){
	if(D2==0 or frac2<=(((-1)*p)-eps)) ansneg++;
      }
    }
  }
  cout<<anspos<<" "<<ansneg<<"\n";
  return 0; 
}

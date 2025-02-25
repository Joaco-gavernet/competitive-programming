#include <bits/stdc++.h>
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end() 

const double eps=1e-14;


int main() {
  FIN;
  cout<< fixed << setprecision(2);
  long double sum=0,maxi=0,mini=21;
  // vector <double> t(4);
  forn(i,4){
    long double aux; cin>>aux;
    sum+=aux;
    if(maxi + eps < aux)maxi=aux;
    if(mini - eps > aux) mini=aux;
  }
  // sort(all(t));
  long double f=0;
  cin >> f;
  f=(f*3);
  double cota=f-(sum-maxi-mini);
  if(maxi<=cota) cout << "infinite\n";
  else if(mini>cota) cout << "impossible\n";
  else cout << cota << "\n";
  return 0;
}  

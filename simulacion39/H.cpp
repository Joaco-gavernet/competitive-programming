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




int main() {
  FIN;
  int n;
  cin >> n;
  if(n==1){
    ll a;
    cin >> a;
    cout << a << "\n";
    return 0;
  }
  vi v;
  ll unos=0, dos=0;
  forn(i,n) {
    ll a;
    cin >> a;
    if(a==1) unos++;
    else if(a==2) dos++;
    else v.pb(a);
  }
  sort(all(v));
  vector <string> bloques;
  forn(i,min(unos,dos)){
    bloques.pb("(1+2)");
  }
  ll m=min(unos,dos);
  unos-=m; dos-=m;
  while(unos>=3){
    bloques.pb("(1+1+1)");
    unos-=3;
  }
  while(dos>0){ bloques.pb("2"); dos--;}
  if(unos==2) bloques.pb("(1+1)");
  if(unos==1){
    if(SZ(bloques)!=0) {bloques[0][SZ(bloques[0])-1]='+'; bloques[0]+="1)";}
  }
  forn(i,SZ(bloques)){
    if(i!=0) cout << "*";
    cout << bloques[i];
  }
  forn(i,SZ(v)){
    if(i==0){
      if(SZ(bloques)==0){
	if(unos==1) cout << "(1+" << v[i] << ")";
	else cout << v[i]; 
      }
      else cout << "*" << v[i];
    }
    else cout << "*" << v[i];
  }
  cout << "\n";
  return 0;
}

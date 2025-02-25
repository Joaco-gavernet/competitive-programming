#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

vi usage(10),recovery(10),start(10);
vi ciclo(10);
vi usejim(10),recjim(10);
ll tprev,tact;

void usemachine(int m){
  ll ti=tact-start[m];
  ll last=(ti/ciclo[m])*ciclo[m]+start[m];
  ll mom=ti%ciclo[m];
  if(tact-start[m]<0){
    tprev=tact+usejim[m];
    tact=tprev+recjim[m];
    start[m]=max(tprev,start[m]);
  }else if(mom>=usage[m]){
    tprev=tact+usejim[m];
    tact=tprev+recjim[m];
    start[m]=max(tprev,last+ciclo[m]);
  }else{
    tprev=tact+(usage[m]-mom)+usejim[m];
    tact=tprev+recjim[m];
    start[m]=max(tprev,last+ciclo[m]);
  }
  return;
}

int main() {
  FIN; 
  tact=0;
  tprev=0;
  forn(i,10){
    cin>>usejim[i]>>recjim[i];
  }
  forn(i,10){
    cin>>usage[i]>>recovery[i]>>start[i];
    ciclo[i]=usage[i]+recovery[i];
  }
  forn(i,3){
    forn(j,10){
      usemachine(j);
    }
  }
  cout<<tprev<<"\n";
  return 0;
}

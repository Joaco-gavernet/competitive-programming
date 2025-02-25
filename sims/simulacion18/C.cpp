#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define SZ(x) int((x).size())
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;

int main() {
  FIN;
  int n; cin>>n;
  vector<bool> visto(1e7+5,false);
  //~ int sig=1;
  forn(ix,n){
    string s; cin>>s;
    if(s[0]=='-') continue;
    if(SZ(s)<=7){
      int pot10=1;
      int nro=0;
      forn(i,SZ(s)){
	nro+=pot10*(s[SZ(s)-1-i]-'0');
	pot10*=10;
      }
      //~ if(nro==sig){visto[nro]=true; sig++;}
      visto[nro]=true;
    }
  }
  int punt=0;
  while(visto[punt]) punt++;
  cout<<punt<<"\n";
  return 0;
}

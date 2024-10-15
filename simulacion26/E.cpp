#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) v.find(x) != v.end()
#define all(v) (v).begin(),(v).end()

const ll MAXN = 1LL<<50;

int main() {
  FIN; 
  vector<ll> p2(50,1);
  forr(i,1,50) p2[i]=p2[i-1]*2;
  string s; cin>>s;
  char c=s[SZ(s)-1],prev='$';
  forn(i,SZ(s)){
    c=s[SZ(s)-1-i];
    if(c=='O' and prev=='O'){cout<<"INVALID"<<"\n"; return 0;}
    if(c=='E' and i==0){cout<<"INVALID\n"; return 0;}
    if(c!='O' and c!='E'){cout<<"INVALID\n"; return 0;}
    prev=c;
  }
  ll rta=MAXN;
  for(ll exp=4; exp<47; exp+=2){
    bool corte=false;
    ll ans=p2[exp];
    forn(i,SZ(s)){
      c=s[SZ(s)-1-i];
      if(c=='E'){
	ans=ans*2;
	if(ans<0){corte=true; break;}
      }
      if(c=='O'){
	if(((ans-1)%3)){corte=true; break;}
	ans=(ans-1)/3;
      }
    }
    if(!corte) rta=min(rta,ans);
  }
  cout<<rta<<"\n";
  return 0;
}

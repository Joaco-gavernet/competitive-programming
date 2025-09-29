#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================\n"

const ll MOD=1e4+7;

ll ac(string s,ll n){
  ll cp=n/2;
  ll ans=0;
  if(n%2){
    ans=1;
    forn(i,cp) ans=(ans*10)%MOD;
    return ans;
  }
  ll pos=0;
  char pd=s[pos],sd=s[pos+1]; 
  while(pos<n){
    if(sd<pd){
      ll extra=1;
      forn(i,cp-1) extra=(extra*10)%MOD;
      extra=(extra*(pd-'0'))%MOD;
      ans=(ans+extra)%MOD;
      return ans;
    }
    if(sd>pd){
      ll extra=1;
      forn(i,cp-1) extra=(extra*10)%MOD;
      extra=(extra*(pd-'0'+1))%MOD;
      ans=(ans+extra)%MOD;
      return ans;
    }
    ll extra=1;
    forn(i,cp-1) extra=(extra*10)%MOD;
    extra=(extra*(pd-'0'))%MOD;
    ans=(ans+extra)%MOD;
    pos+=2;
    if(pos<n) pd=s[pos]; sd=s[pos+1]; cp--;
  }
  ans++;
  return ans;
}

int main() {
  FIN;
  string l,r; cin>>l>>r;
  ll n1=SZ(r); ll n2=SZ(l);
  ll sup=ac(r,n1);
  ll inf=ac(l,n2);
  //Check si l es twin
  if(n2%2==0){
    bool es=true;
    forn(i,n2/2) if(l[2*i]!=l[2*i+1]){es=false; break;}
    if(es) inf=(inf-1+MOD)%MOD;
  }
  cout<<(sup-inf+MOD)%MOD<<"\n";

  return 0;
}
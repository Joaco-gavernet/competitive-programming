#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "======================\n"


void solve() {
  int h, w, k; cin >> h >> w >> k; 
  ll n=w*h;
  vi num(n,0);
  vector<string> tab(h); forn(i,h) cin >> tab[i];
  forn(i,h) forn(j,w){
    if(tab[i][j]=='#') num[i*w+j]=1;
    else num[i*w+j]=0;
    // DBG(i*w+j);
  }
  //Validacion
  ll sum=n-k;
  ll check=0;
  check+=((n/2)+(n/4)+(n/8)+(n/16)+(n/32)+(n/64));
  check-=((k/2)+(k/4)+(k/8)+(k/16)+(k/32)+(k/64));
  check-=((sum/2)+(sum/4)+(sum/8)+(sum/16)+(sum/32)+(sum/64));
  if(check==0){cout<<"risky"<<endl; return;}

  ll pairs=0;
  ll firstind=n+1;
  ll secondind=n+1;
  ll firstcero=n+1;
  ll firstuno=n+1;
  ii ori={-1,-1},dest={-1,-1};
  forn(i,n/2){
    if(num[2*i]!=num[2*i+1]){
      pairs++;
      if(secondind==n+1) secondind=firstind;
      firstind=min(firstind,i);
    }else{
      if(num[2*i]==0) firstcero=min(firstcero,i);
      else firstuno=min(firstuno,i);
    }
  }
  if(pairs==0){
    ll pos=2*firstuno;
    ori={pos/w,pos%w};
    ll posd=2*firstcero;
    dest={posd/w,posd%w};    
  }else if(pairs==2){
    if(firstind==0 and ((secondind<firstcero or secondind<firstuno)) and 
    (secondind<n+1 and (num[2*secondind]==num[2*(secondind-1)] or secondind==firstind+1)) and 
    (firstind <=n/2 and num[2*firstind]==num[2*(firstind+1)])){
      ll pos=2*firstind;
      ori={pos/w,pos%w};
      ll posd=2*secondind;
      dest={posd/w,posd%w}; 
    }else{
      ll pos=2*secondind;
      ori={pos/w,pos%w};
      ll posd=pos+1;
      dest={posd/w,posd%w}; 
    }
  }else{
    ll pos=2*firstind; if(num[pos]==0) pos++;
    ori={pos/w,pos%w};
    ll posd=2*firstind+1; if(num[posd]==1) posd--;
    dest={posd/w,posd%w}; 
  }
  cout<<ori.ff+1<<" "<<ori.ss+1<<endl;
  cout<<dest.ff+1<<" "<<dest.ss+1<<endl;
}

int main() {
  // FIN;
  int t; cin >> t; 
  while (t--) solve();
  return 0; 
}
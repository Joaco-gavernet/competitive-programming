#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=======================" << endl 
#define ff first
#define ss second


int main() {
  FIN;
  ll n; cin>>n;
  vi ans(n,0);
  vi left(n/2+1,2);
  ll pos=0;
  if(n==2){
    cout<<"! 1 1"<<endl;
    return 0;
  }
  while(pos<n){
    if(pos+3<n){
      cout<<"? "<<pos+1<<" "<<pos+2<<endl;
      ll a,b; cin>>a>>b; if(a>b) swap(a,b);
      cout<<"? "<<pos+1<<" "<<pos+3<<endl;
      ll c,d; cin>>c>>d; if(c>d) swap(c,d);
      cout<<"? "<<pos+1<<" "<<pos+4<<endl;
      ll e,f; cin>>e>>f; if(e>f) swap(e,f);

      if(a==c and b==d){
        if(a==e){
          ans[pos]=a; ans[pos+3]=f;
          ans[pos+1]=b; ans[pos+2]=d;
        }else if(a==f){
          ans[pos]=a; ans[pos+3]=e;
          ans[pos+1]=b; ans[pos+2]=d;
        }else if(b==e){
          ans[pos]=b; ans[pos+3]=f;
          ans[pos+1]=a; ans[pos+2]=c;
        }else{
          ans[pos]=b; ans[pos+3]=e;
          ans[pos+1]=a; ans[pos+2]=c;
        }
      }else{
        if(a!=c) swap(c,d);
        if(a!=c) swap(a,b);
        if(a!=c) swap(c,d);
        ans[pos]=a; ans[pos+1]=b; ans[pos+2]=d;
        if(a==e) ans[pos+3]=f; else ans[pos+3]=e;
      }

      pos+=4;
    }else while(pos<n){
      cout<<"? "<<1<<" "<<pos+1<<endl;
      ll a,b; cin>>a>>b;
      if(a==ans[0]) ans[pos]=b; else ans[pos]=a;
      pos++;
    }
  }
  cout<<"! ";
  forn(i,n) cout<<ans[i]<<" ";
  cout<<endl;


  return 0; 
}
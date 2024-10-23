#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi;
typedef pair<ll,ll> ii; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "=================================\n"


int main() {
  FIN; 
  int n; cin>>n;
  vector<vi> v(n,vi(n,0));
  forn(i,n){
    forn(j,n){
      char c; cin>>c;
      v[i][j]=c-'0';
    }
  }
  vector<vi> f(n,vi(n,0));
  forr(x,1,n){
    forn(i,n-x){
      int j=i+x;
      int ans=v[i][j];
      forr(d,1,x){
	ans-=(f[i][i+d]*v[i+d][i+x]);
      }
      ans=((ans%10)+10)%10;
      if(ans==1) f[i][j]=1;
    }
  }
  forn(i,n){
    forn(j,n){
      cout<<f[i][j];
    }
    cout<<"\n";
  }
  return 0; 
}


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
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===========================\n"
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << '\n'



int main() {
  FIN;
  int n, c, b; cin >> n >> c >> b;
  vi v(b);
  forn(i,b){
    cin >> v[i];
    v[i]--;
  }
  ll cont=0;
  vi ans(n);
  forn(i,b){
    for(int j=v[i]-1; j>-1; j-=2){
      if(i>0 and j<=v[i-1]) break;
      ans[j]=1;
      cont+=2;
      if(j==0) cont--;
    }
  }
  for(int j=v[b-1]+1; j<n; j+=2){
    ans[j]=1;
    cont+=2;
    if(j==n-1) cont--;
  }
  if(cont%2!=c%2){
    if(v[0]!=0) ans[0]=1-ans[0];
    else if(v[b-1]!=n-1) ans[n-1]=1-ans[n-1];
    else{
      forr(i,1,b) if(v[i]-v[i-1]>3){
        ans[v[i]-2]=1;
        break;
      }
    }
    cont--;
  }
  forr(i,1,n-1) if(cont>c and ans[i]==1 and ans[i-1]==0 and ans[i+1]==0){ans[i]=0; cont-=2;}
  //cout << cont << "\n";
  forn(i,n) cout << ans[i];
  cout << "\n";
  return 0;
}


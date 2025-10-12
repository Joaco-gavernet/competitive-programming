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
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=============================\n"



int main() {
  FIN;
  ll n,m; cin>>n>>m;
  vector<vector<char>> mat(n+2,vector<char>(m+2,'$'));
  forr(i,1,n+1) forr(j,1,m+1) cin>>mat[i][j];
  vector<ii> cruces;
  forr(i,1,n+1) forr(j,1,m+1) {
    if(mat[i][j]=='+') cruces.pb({i,j});
  }
    ll ans=0;
  for(auto in:cruces){
    ll x=in.first; ll y=in.second;
    ll cont=1;
    while(1){
      if(mat[x][y+cont]!='-') break;
      if(mat[x][y-cont]!='-') break;
      if(mat[x+cont][y]!='|') break;
      if(mat[x-cont][y]!='|') break;
      if(mat[x+cont][y+cont]!= 92) break;
      if(mat[x-cont][y-cont]!= 92) break;
      if(mat[x+cont][y-cont]!= '/') break;
      if(mat[x-cont][y+cont]!= '/') break;
      cont++;
    }
    ans=max(ans,cont-1);
  }
  cout<<ans<<"\n";

  return 0; 
}
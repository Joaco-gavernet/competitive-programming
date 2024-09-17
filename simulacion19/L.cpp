#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << (c) << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << " "; cerr << endl
#define RAYA cerr << " ============================= " << endl
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;
const int MOD = -1;
const int MAXN = -1;

int main() {
  FIN;
  int n,m; cin>>n>>m;
  vector<string> mat(n);
  forn(i,n) cin>>mat[i];
  vector<vector<int>> der(n,vector<int>(m,1));
  forn(i,n){
    forr(j,1,m){
      if(mat[i][m-1-j]==mat[i][m-j]) der[i][m-1-j]=der[i][m-j]+1;
      else der[i][m-1-j]=1;
    }
  }
  
  //~ for(auto u:der){
    //~ for(auto v:u) cout<<v<<" ";
    //~ cout<<endl;
  //~ }
  vector<vector<pair<int,int>>> ns(n,vector<pair<int,int>>(m,{-1,n}));
  int ans=0;
  forn(col,m){
    forr(i,1,n){
      int pos=i-1;
      while(pos>=0 and der[pos][col]>=der[i][col]) pos=ns[pos][col].first;
      if(pos>=0) ns[i][col].first=pos;
    }
    for(int i=n-2; i>=0;i--){
      int pos=i+1;
      while(pos<=n-1 and der[pos][col]>=der[i][col]) pos=ns[pos][col].second;
      if(pos<n) ns[i][col].second=pos;
    }
    forn(i,n){
      if(ns[i][col].second-ns[i][col].first-1 >= der[i][col]) ans=max(ans,der[i][col]);
    }
  }
  cout<<ans*ans<<"\n";
  return 0;
}

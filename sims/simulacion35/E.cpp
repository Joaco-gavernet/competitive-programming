#include <bits/stdc++.h> 
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define SZ(x) int((x).size())
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
const ll INF=(1LL)<<30;

int main() {
  FIN; 
  int r,c,n; cin>>r>>c>>n;
  vector<vector<vi>> dp(11,vector<vi>(r+2,vi(c,INF)));
  vector<vi> tab(r+2,vi(c,INF));
  vector<vector<bool>> esp(r+2,vector<bool>(c,false));
  forn(i,r){
    forn(j,c){
      cin>>tab[i+1][j];
      if(tab[i+1][j]==-1) tab[i+1][j]=INF;
    }
  }
  forr(i,1,r-1){
    forr(j,1,c-1){
      if(tab[i][j]<INF and tab[i+2][j]<INF and tab[i+1][j-1]<INF and tab[i+1][j+1]<INF){
	if(tab[i][j]>tab[i+1][j] and tab[i+2][j]>tab[i+1][j] and tab[i+1][j-1]<tab[i+1][j] and tab[i+1][j+1]<tab[i+1][j]){
	  esp[i+1][j]=true;
	}
      }
    }
  }
  forn(i,r){
    if(esp[i+1][0]){
      dp[1][i+1][0]=tab[i+1][0];
    }else dp[0][i+1][0]=tab[i+1][0];
  }
  forr(col,1,c){
    forn(i,r){
      if(esp[i+1][col]){
	forn(x,10){
	  dp[x+1][i+1][col]=min(dp[x+1][i+1][col],dp[x][i+1][col-1]+tab[i+1][col]);
	  dp[x+1][i+1][col]=min(dp[x+1][i+1][col],dp[x][i][col-1]+tab[i+1][col]);
	  dp[x+1][i+1][col]=min(dp[x+1][i+1][col],dp[x][i+2][col-1]+tab[i+1][col]);
	}
      }else{
	forn(x,11){
	  dp[x][i+1][col]=min(dp[x][i+1][col],dp[x][i+1][col-1]+tab[i+1][col]);
	  dp[x][i+1][col]=min(dp[x][i+1][col],dp[x][i][col-1]+tab[i+1][col]);
	  dp[x][i+1][col]=min(dp[x][i+1][col],dp[x][i+2][col-1]+tab[i+1][col]);
	}
      }
    }
  }
  ll ans=INF;
  forn(i,r){
    if(dp[n][i+1][c-1]<INF) ans=min(ans,dp[n][i+1][c-1]);
  }
  if(ans<INF) cout<<ans<<"\n";
  else cout<<"impossible\n";
  return 0; 
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

ll n,k; 

vi ships;

ll solve(vector<vector<char>> &mat, ll x,ll y,ll len,ll ori,ll cant, ll remx){
  ll ans=0;
  
  if(ori==0){
    ll valid=0;
    forn(pos,len) if(mat[x][y+pos]!='X' and mat[x][y+pos]!='#'){valid++; if(mat[x][y+pos]=='O') remx--;}
    if(valid==len){
      if(cant<k){
        vector<char> auxlen;
        forn(pos,len){auxlen.pb(mat[x][y+pos]); mat[x][y+pos]='#';}
        forn(row,n) forn(col,n-ships[cant]+1){
          if(mat[row][col]=='.' or mat[row][col]=='O') ans+=solve(mat,row,col,ships[cant],0,cant+1,remx);
          // DBG(ans);
          if((mat[col][row]=='.' or mat[col][row]=='O') and ships[cant]>1) ans+=solve(mat,col,row,ships[cant],1,cant+1,remx);
          // DBG(ans);
        }
        forn(pos,len) mat[x][y+pos]=auxlen[pos];
        // if(len == 2) cerr << x << " "  << y << " " << ori << " "<< ans <<endl; 
        return ans;
      }else if(remx==0) return 1; else return 0;
    }else return ans;
  }else{
    ll valid=0;
    forn(pos,len) if(mat[x+pos][y]!='X' and mat[x+pos][y]!='#'){valid++; if(mat[x+pos][y]=='O') remx--;}
    if(valid==len){
      if(cant<k){
        vector<char> auxlen;
        forn(pos,len){auxlen.pb(mat[x+pos][y]); mat[x+pos][y]='#';}
        forn(row,n) forn(col,n-ships[cant]+1) {
          if(mat[row][col]=='.' or mat[row][col]=='O') ans+=solve(mat,row,col,ships[cant],0,cant+1,remx);
          // DBG(ans);
          if((mat[col][row]=='.' or mat[col][row]=='O') and ships[cant]>1) ans+=solve(mat,col,row,ships[cant],1,cant+1,remx);
          // DBG(ans);
        }
        forn(pos,len) mat[x+pos][y]=auxlen[pos];
        // if(len == 2) cerr << x << " "  << y << " " << ori << " "<< ans <<endl; 
        return ans;
      }else if(remx==0) return 1; else return 0;
    }else return ans;
  }
  return 0;
}

int main() {
  FIN;
  cin>>n>>k;
  vector<vector<char>> mat(n,vector<char>(n));
  ll contx=0;
  forn(i,n) forn(j,n){
    cin>>mat[i][j];
    if(mat[i][j]=='O') contx++;
  }
  forn(i,k){
    ll x; cin>>x; 
    ships.pb(x);
  }
  sort(all(ships)); reverse(all(ships));
  ll ans=0;
  forn(row,n) forn(col,n-ships[0]+1){
    ans+=solve(mat,row,col,ships[0],0,1,contx);
    if(ships[0]>1) ans+=solve(mat,col,row,ships[0],1,1,contx);
  }
  cout<<ans<<"\n";
  return 0;
}
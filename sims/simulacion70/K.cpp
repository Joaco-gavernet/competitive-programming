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

int main() {
  FIN;
  ll h,w,k,i,t; cin>>h>>w>>k>>i>>t;
  vector<vector<char>> ans(h,vector<char>(w));
  ans[0][0]='K'; ans[0][1]='I'; ans[0][2]='T';
  k--; i--; t--;
  forr(j,3,w){
    if(k){
      ans[0][j]='K';
      k--;
    }else if(t){
      ans[0][j]='T';
      t--;
    }else{
      ans[0][j]='I';
      i--;
    }
  }
  forr(x,1,h) forn(j,w){
    if(k){
      ans[x][j]='K';
      k--;
    }else if(t){
      ans[x][j]='T';
      t--;
    }else{
      ans[x][j]='I';
      i--;
    }
  }
  forn(i,h){
    forn(j,w) cout<<ans[i][j];
    cout<<"\n";
  }
  return 0; 
}
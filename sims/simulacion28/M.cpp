#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back

int main() {
  FIN; 	
  int r,c; cin>>r>>c;
  vector<vector<int>> mat(r,vector<int>(c));
  forn(i,r){
    forn(j,c){
      cin>>mat[i][j];
    }
  }
  vector<int> fi,ci;
  forn(i,r){
    ll sum=0;
    forn(j,c) sum+=mat[i][j];
    if(sum%2) fi.pb(i);
  }
  forn(i,c){
    ll sum=0;
    forn(j,r) sum+=mat[j][i];
    if(sum%2) ci.pb(i);
  }
  while(SZ(fi) and SZ(ci)){
    int x=fi[SZ(fi)-1],y=ci[SZ(ci)-1];
    fi.pop_back();
    ci.pop_back();
    mat[x][y]++;
  }
  while(SZ(fi)){
    int x=fi[SZ(fi)-1],y=fi[SZ(fi)-2];
    fi.pop_back();
    fi.pop_back();
    mat[x][0]++;
    mat[y][0]++;
  }
  while(SZ(ci)){
    int x=ci[SZ(ci)-1],y=ci[SZ(ci)-2];
    ci.pop_back();
    ci.pop_back();
    mat[0][x]++;
    mat[0][y]++;
  }
  forn(i,r){
    forn(j,c){
      cout<<mat[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0; 
}

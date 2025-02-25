#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"
#define pb push_back
#define SZ(x) int((x).size())


int main() {
  FIN; 
  int n,m; cin>>n>>m;
  vector<vector<int>> mat(n,vector<int> (m));
  forn(i,n){
    forn(j,m){
      cin>>mat[i][j];
    }
  }
  string sa="0",sb="1";
  if(mat[0][0]==1) sb="0";
  int c=0,f=0,a=1,b=1;
  while(b<m and mat[0][b]==0){
    sb+='1'; b++;
  }
  if(b<m){sb+='0'; b++;}
  //~ RAYA;
  while(a<n and mat[a][0]==0){
    //~ DBG(a);
    sa+='0'; a++;
  }
  if(a<n){sa+='1'; a++;}
  //~ RAYA;
  while(a<n or b<m){
    if(b<m and b<=a){
      f++;
      //~ DBG(f);
      char ch=('0'+(sa[f]%2));
      while(b<m-1 and mat[f][b]==mat[f][b-1]){sb=sb+ch; b++;}
      if(b<m){sb+=sa[f];  b++;}
    }else{
      c++;
      //~ DBG(c);
      char ch=('0'+(sb[c]%2));
      while(a<n-1 and mat[a-1][c]==mat[a][c]){sa=sa+ch; a++;}
      if(a<n){sa+=sb[c];  a++;}
    }
  }
  
  cout<<sa<<"\n"<<sb<<"\n";
  
  return 0; 
}

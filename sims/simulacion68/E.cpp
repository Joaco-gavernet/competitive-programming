#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<char> vc;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)


int main() {
  FIN;
  ll n; cin>>n;
  ll m=(2*n)-1;
  vector<vc> grid(n,vc(m));
  vector<vc> ans(n,vc(m,'#'));
  ll contc=0;
  forn(i,n) forn(j,m){
    char c; cin>>c;
    if(c=='C') contc++;
    if(c=='#') ans[i][j]='#';
    else ans[i][j]='B';
    grid[i][j]=c;
  }
  if(contc%2){cout<<"impossible\n"; return 0;}
  if(n==2){
    if(contc==4){cout<<"impossible\n"; return 0;}
    if(contc==2){
      if(grid[0][1]=='C') ans[0][1]='A';
      else if(grid[1][0]=='C') ans[1][0]='A';
      else if(grid[1][2]=='C') ans[1][2]='A';
      //Imprimo rta
      forn(i,n){
        forn(j,m){
          cout<<ans[i][j];
        }
        cout<<"\n";
      }
      return 0;
    }
  }
  if(contc==6 and grid[0][n-1]=='C' and grid[1][n-1]=='C' and grid[n-1][0]=='C' and grid[n-1][1]=='C' and grid[n-1][m-2]=='C' and grid[n-1][m-1]=='C'){
    cout<<"impossible\n"; return 0;
  } 

  ll target=contc/2;
  ll cont=0;

  //Primera fila
  forn(i,m){
    ans[n-1][i]='A';
    if(grid[n-1][i]=='C') cont++;
    if(cont==target) break;
  }

  //Caso borde
  if(cont==target and ans[n-1][m-1]!=ans[n-1][m-2]){
    if(grid[n-1][m-1]=='.') ans[n-1][m-1]='A';
    else if(grid[n-1][0]=='.'){
      ll aux=0;
      ans[n-1][m-1]='A';
      while(grid[n-1][aux]=='.'){
        ans[n-1][aux]='B';
        aux++;
      }
      ans[n-1][aux]='B';
    }else{
      //Marcar por columnas
      ll col=1;
      bool hecho=false;
      while(col<m-2){
        ll fil=n-2;
        while(fil>=0 and grid[fil][col]!='#'){
          if(grid[fil][col]=='C'){
            if(fil==1 and col==n-1){
              ans[fil][col]='A';
              ans[fil-1][col]='A';
              ans[n-1][m-2]='B';
              ll ultima=m-3;
              while(grid[n-1][ultima]=='.'){
                ans[n-1][ultima]='B';
                ultima--;
              }
              ans[n-1][ultima]='B';
            }else{
              ans[fil][col]='A';
              ans[n-1][m-2]='B';
            }
            hecho=true; break;
          }else ans[fil][col]='A';
          fil--;
        }
        if(hecho) break;
        else col++;
      }
      if(!hecho and col==m-2){
        ans[n-2][m-2]='A';
        ans[n-1][m-2]='B';
      }
    }
  }

  //Si no llegue a emparejar todas
  ll fil=n-2;
  while(cont<target){
    ll l=(n-1)-fil;
    ll r=(m-1)-l;
    // DBG(cont); DBG(target);
    while(l<=r){
      // RAYA;
      ans[fil][l]='A';
      if(grid[fil][l]=='C') cont++;
      l++;
      if(cont==target) break;
      // RAYA;
      if(ans[fil][r]=='B'){
        ans[fil][r]='A';
        if(grid[fil][r]=='C') cont++;
        r--;
        if(cont==target) break;
      }
      // RAYA;
    }
    if(cont==target) break;
    fil--;
  }


  //Imprimo rta
  forn(i,n){
    forn(j,m){
      cout<<ans[i][j];
    }
    cout<<"\n";
  }

  return 0;
}
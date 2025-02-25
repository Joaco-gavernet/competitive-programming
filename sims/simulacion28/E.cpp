#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)


int main() {
  FIN; 
  int n; cin>>n;
  ll co0=0,co1=0;
  char c0='*',c1='*';
  vector<vector<char>> v(n,vector<char>(n)); 
  forn(i,n){
    forn(j,n){
      cin>>v[i][j];
      if(v[i][j]=='1') co1++;
      else co0++;
    }
  }
  cerr<<n<<endl;
  if(co0>co1) {
    c1='o';
  }else if (co0<co1) {
    c0='o';
  }else{
    cerr<<n<<endl;
    if(v[0][0]=='0') c1='o';
    else c0='o';
  }
  forn(i,n){
    forn(j,n){
      if(v[i][j]=='1') cout<<c1;
      else cout<<c0;
    }
    cout<<"\n";
  }
  return 0; 
}

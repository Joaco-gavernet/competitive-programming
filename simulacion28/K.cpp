#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define pb push_back


const int MAXN=105;



int main() {
  FIN; 
  int t; cin>>t;
  while(t--){
    vector<vector<int>> g(MAXN),d(MAXN);
    int n,a,b; cin>>n>>a>>b;
    if(a+b>n) cout<<"No"<<"\n";
    else{
      cout<<"Yes\n";
      //~ int pc=0,pd=1;
      forn(i,n){
	forn(j,a){
	  g[i].pb((i+j)%n); 
	  //~ pc=(pc+1)%n;
	}
      }
      forn(i,n){
	forn(j,b){
	  int x= (i+j+1)%n;
	  //~ cerr<<x<<n<<endl;
	  d[i].pb(x); 
	  //~ pd=(pd+1)%n;
	}
      }
      forn(i,n){
	forn(j,a) cout<<g[i][j]+1<<" ";
	cout<<"\n";
      }
      forn(i,n){
	forn(j,b) cout<<d[i][j]+1<<" ";
	cout<<"\n";
      }
    }
  }
  return 0; 
}

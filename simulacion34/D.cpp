#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define pb push_back

int main() {
  FIN;
  int n,w,h,s; cin>>n>>w>>h>>s;
  //~ vector<vector<string>> pixels(n,vector<string>(h));
  vector<char> car(n);
  vector<int> sw(n,0);
  //~ cout<<s<<"\n";
  int cmax=0;
  forn(i,n){
    cin>>car[i];
    forn(j,h){
      int ff=0;
      vector<char> auxi(w);
      forn(x,w) cin>>auxi[x];
      forn(k,w){
	if(k==0 and auxi[k]=='#') ff++;
	else if(k!=0){
	  if(auxi[k]!=auxi[k-1]) ff++;
	}
	if(k==w-1 and auxi[k]=='#') ff++;
      }
      sw[i]=max(sw[i],ff);
      //~ cout<<sw[i]<<"\n";
    }
  }
  int smax=sw[0];
  forr(i,1,n){
    if(smax<sw[i]){
      cmax=i;
      smax=sw[i];
    }
  }
  forn(i,(s+smax-1)/smax) cout<<car[cmax];
  cout<<"\n";
  return 0; 
}

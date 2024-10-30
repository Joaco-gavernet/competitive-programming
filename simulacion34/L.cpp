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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"


int main() {
  FIN;
  
  int t; cin>>t;
  while(t--){
    int n; cin>>n;
    vector<int> perm1(n),perm2(n);
    forn(i,n) perm1[i]=i+2;
    perm1[n-1]=1;
    forn(i,n) perm2[i]=i+1;
    perm2[0]=2; perm2[1]=1;
    
    cout<<"? ";
    forn(i,n) cout<<perm1[i]<<" ";
    cout<<endl;
    
    vector<int> ans1(n),ans2(n),sucesor(n,0);
    forn(i,n){
      cin>>ans1[i];
      sucesor[i]=ans1[i];
    }
    
    cout<<"? ";
    forn(i,n) cout<<perm2[i]<<" ";
    cout<<endl;
    
    int p1=0,p2=0;
    forn(i,n){
      cin>>ans2[i];
      if(ans2[i]!=i+1){
	if(p1==0) p1=ans2[i];
	else p2=ans2[i];
      }
    }
    
    //~ forn(i,n){
      //~ DBG(i+1);
      //~ DBG(sucesor[i]);
    //~ }
    
    if(sucesor[p1-1]!=p2) swap(p1,p2);
    int imp=p1;
    cout<<"! ";
    forn(i,n){
      cout<<imp<<" ";
      imp=sucesor[imp-1];
    }
    cout<<endl;
  }
  return 0; 
}

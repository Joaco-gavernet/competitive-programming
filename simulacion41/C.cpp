#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"



int main() {
  FIN; 
  ll n,m; cin>>n>>m;
  string s,t; cin>>s>>t;
  if(n==1){
    cout<<1<<"\n";
    return 0;
  }else if(n==2){
    cout<<2<<"\n";
    return 0; 
  }
  if(s[0]!=t[0] or s[n-1]!=t[m-1]) cout<<2<<"\n";
  else cout<<3<<"\n";
  return 0; 
} 

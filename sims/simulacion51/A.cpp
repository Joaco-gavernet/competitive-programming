#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())


int main() {
  string s; cin>>s;
  ll n; cin>>n;
  while(n--){
    string p; cin>>p;
    if(SZ(p)%SZ(s)!=0){cout<<"No\n"; continue;}
    bool ans=true;
    forn(i,SZ(p)){
      if(p[i]!=s[i%SZ(s)]) ans=false;
    }
    if(ans) cout<<"Yes\n";
    else cout<<"No\n";
  }
  return 0; 
}
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) v.find(x) != v.end()


int main() {
  FIN; 
  int n; cin>>n;
  vector<pair<int,int>> v(n),v2;
  forn(i,n){
    int aux; cin>>aux;
    v[i]={aux,i};
  }
  v2=v;
  sort(v.begin(),v.end());
  vector<int> ans; int m=0;
  forn(i,n){
    m=max(m,v2[i].first);
    if((m==v[i].first) and (v[i].second==i)) ans.pb(v[i].first);
  }
  cout<<SZ(ans)<<" ";
  forn(i,min(100,SZ(ans))) cout<<ans[i]<<" ";
  cout<<"\n";
  return 0;
}

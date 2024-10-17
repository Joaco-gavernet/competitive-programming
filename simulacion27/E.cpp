#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++) 
#define DBG(x) cerr << #x << " = " << x << endl
#define esta(x,v) (v).find(x) != (v).end()


int main() {
  FIN; 

  int n; cin >> n; 
  vector<ll> v(n); forr(i,0,n) cin >> v[i]; 
  multiset<int> mst; 
  forr(i,0,n) {
    if (esta(v[i]+1,mst)) mst.erase(mst.find(v[i]+1)); 
    mst.insert(v[i]); 
  }

  cout << int(mst.size()) << endl; 


  return 0; 
}

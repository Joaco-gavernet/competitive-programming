#include <bits/stdc++.h> 
using namespace std; 

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define esta(x,v) (v).find(x) != (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"


int main() {
  FIN; 
  
  int n;
  cin >> n;
  map <string,ll> m;
  forn(i,n){
    string s; cin >> s;
    m[s]++;
  }
  ll ans=0; string s;
  for(auto [k,c] : m){
    if(c>ans){
      ans=c;
      s=k;
    }
  }
  cout << s << "\n";
  return 0; 
} 

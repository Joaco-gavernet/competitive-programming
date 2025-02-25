#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++) 

int main() {
  
  int n; cin >> n;
  vector<string> v(n); 
  forr(i,0,n) cin >> v[i]; 
  vector<int> vi(n); 
  forr(i,0,n) vi[i] = (int(v[i][0] -'0') -7)*60 + (v[i][2] -'0')*10 + v[i][3] -'0'; 
  //~ forr(i,0,n) cerr << vi[i] << ' ';
  //~ cerr << endl; 
  
  bool valid = false; // hay un par a distancia menor/igual que 10
  bool done = false; // ya se cumple
  forr(i,1,n) {
    if (vi[i] - vi[i-1] <= 10) valid = true;
    if (i >= 2 and vi[i] -vi[i-2] <= 10) {
      //~ cerr << i << endl; 
      done = true;
      break;
    }
  }
  
  //~ cerr << done << endl;
  //~ cerr << valid << endl; 
  if (done) cout << 0 << endl;
  else if (valid) cout << 1 << endl; 
  else cout << 2 << endl; 
  

  return 0; 
}

#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++) 

int main() {
  FIN; 

  string s;
  getline(cin, s); 
  for (auto c : s) {
    if (c == '9') {
      cout << 'F' << endl; 
      return 0; 
    }
  }
  cout << 'S' << endl; 

  return 0; 
}

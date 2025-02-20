#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 


struct tup {
  int id, p, t; 
  bool operator < (tup b) {
    if (p == b.p) return t < b.t; 
    else return p < b.p; 
    return false; 
  } 
}; 

int main() {
  int t; cin >> t; 
  while (t--) {
    int n; cin >> n; 
    vector<tup> v(n); 

    for (int i = 0; i < n; i++) cin >> v[i].id, v[i].t = i; 
    for (int i = 0; i < n; i++) cin >> v[i].p; 
    sort(v.begin(), v.end()); 

    for (int i = 0; i < n; i++) cout << v[i].id << ' ';
    cout << '\n'; 


  } 

  return 0; 
} 

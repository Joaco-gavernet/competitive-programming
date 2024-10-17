#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++) 
#define DBG(x) cerr << #x << " = " << x << endl
#define esta(x,v) (v).find(x) != (v).end()

int main() {
  FIN; 

  int n, x, y; cin >> n >> x >> y; 
  if (x == 1<<(n-1) and y == 1<<(n-1)) {
    cout << "0\n"; 
    return 0; 
  }

  pair<int,int> ops[] = {{0, 0}, {0, 1<<n}, {1<<n, 1<<n}, {1<<n, 0}}; 
  int best = 0; 
  forr(i,1,4) {
    if (pow(ops[i].first -x, 2) + pow(ops[i].second -y, 2) < pow(ops[best].first -x, 2) + pow(ops[best].second -y, 2)) 
      best = i; 
  }
  DBG(best); 

  ll movs = 0; 

  cout << movs << '\n'; 


  return 0; 
}

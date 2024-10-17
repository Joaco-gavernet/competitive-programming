#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++) 
#define DBG(x) cerr << #x << " = " << x << endl
#define esta(x,v) (v).find(x) != (v).end()
#define SZ(x) int((x).size())

int main() {
  FIN; 

  int n; cin >> n; 
  ll mary = 0, john = 0; 
  multiset<int> played; 
  forr(i,0,2) {
    int x; cin >> x; played.insert(x); 
    if (x >= 10) john += 10; 
    else john += x; 
  }
  forr(i,0,2) {
    int x; cin >> x; played.insert(x); 
    if (x >= 10) mary += 10; 
    else mary += x; 
  }
  vi cards(n); forr(i,0,n) cin >> cards[i], played.insert(cards[i]); 
  forr(i,0,n) {
    ll val = (cards[i] >= 10 ? 10 : cards[i]); 
    john += val, mary += val; 
  }
  if (mary < john) {
    ll mi = 24 -john; 
    if (mi > 10) {
      cout << "-1\n"; 
      return 0; 
    }
    while (played.count(mi) == 4) mi++; 
    if (mary +mi <= 23) cout << mi << endl; 
    else cout << "-1\n"; 
  } else {
    ll mi = 23 -mary; 
    if (mi > 10) {
      cout << "-1\n"; 
      return 0; 
    }
    if (played.count(mi) == 4) cout << "-1\n"; 
    else cout << mi << endl; 
  }


  return 0; 
}

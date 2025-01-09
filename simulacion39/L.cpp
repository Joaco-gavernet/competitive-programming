#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"



void hundir(int xi, int yi, int n, int &k) {
  int dx = 1; 
  string ans = "hit"; 
  while (dx < 5 and xi + dx <= n) {
    cout << (xi +dx) << ' ' << yi << endl;
    cin >> ans; 
    if (ans == "sunk") {
      k--; 
      if (k == 0) return; 
    }
    dx++; 
  }
  dx = 1, ans = "hit"; 
  while (dx < 5 and xi -dx > 0) {
    cout << (xi -dx) << ' ' << yi << endl;
    cin >> ans; 
    if (ans == "sunk") {
      k--; 
      if (k == 0) return; 
    }    
    dx++; 
  }
  int dy = 1; 
  ans = "hit"; 
  while (dy < 5 and yi +dy <= n) {
    cout << xi << ' ' << (yi +dy) << endl;
    cin >> ans; 
    if (ans == "sunk") {
      k--; 
      if (k == 0) return; 
    } 
    dy++; 
  }
  dy = 1, ans = "hit"; 
  while (dy < 5 and yi -dy > 0) {
    cout << xi << ' ' << (yi -dy) << endl;
    cin >> ans; 
    if (ans == "sunk") {
      k--;       
      if (k == 0) return; 
    } 
    dy++; 
  }
} 

int main() {
  FIN;
  
  int n, k; cin >> n >> k;
  string ans; 
  for (int x = 1; x <= n; x += 5) {
    int xi = x, yi = 1;
    while (yi <= n and xi <= n) { 
      cout << xi << ' ' << yi << endl;
      cin >> ans;
      if (ans == "hit") hundir(xi, yi, n, k);
      if (k == 0) return 0;
      xi++, yi++; 
    } 
  }
  for (int y = 6; y <= n; y += 5) {
    int yi = y, xi = 1;
    while (yi <= n and xi <= n) {
      cout << xi << ' ' << yi << endl;
      cin >> ans;
      if (ans == "hit") hundir(xi, yi, n, k);
      if (k == 0) return 0;
      xi++, yi++; 
    }
  }
  
  
  return 0;
}

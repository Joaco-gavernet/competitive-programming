#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = 1e6+5;
const int INF = -1;
const int MOD = -1;


void check(string &s, vi &ans) {
  int parent = -1; 
  string aux; 
  for (char c: s) {
    if (c == ' ') continue; 
    if (c != '(' and c != ')') aux += c; 
    else if (c == '(') {
      if (SZ(aux)) {
        ans[stoi(aux)] = parent; 
        parent = stoi(aux); 
      }
      aux = ""; 
    } else {
      if (SZ(aux)) ans[stoi(aux)] = parent; 
      else parent = ans[parent]; 
      aux = ""; 
    }
  }
  if (SZ(aux)) ans[stoi(aux)] = parent; 
}

int main() {
  FIN; 

  string first, second; 
  getline(cin, first); 
  getline(cin, second); 

  vi fparent(MAXN, 0), sparent(MAXN, 0); 
  check(first, fparent); 
  check(second, sparent); 

  forn(i,MAXN) {
    if (fparent[i] != sparent[i]) {
      cout << "No\n"; 
      return 0;
    }
  }

  cout << "Yes\n"; 
  return 0;
}

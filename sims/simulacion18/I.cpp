#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;

int main() {
  FIN;
  
  int a,b,c; cin >> a >> b >> c;
  
  ll n = floor((double)(a+1)*(b+1)/(c+1) -1);
  cout << n << endl;
  
  return 0;
}

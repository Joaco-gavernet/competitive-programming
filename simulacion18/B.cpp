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
  int n; cin>>n; 
  map<string,int> m;
  string s;
  forn(i,n){
    cin>>s;
    m[s]++;
  }
  for(auto u:m){
    if(u.second>n/2){cout<<u.first<<"\n"; return 0;}
  }
  cout<<"NONE\n";
  return 0;
}

#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << endl 
#define RAYA cerr << "========================\n" 


int main() {
  FIN; 
  ll t; cin>>t;
  while(t--){
    ll a,b; cin>>a>>b;
    cout<<14-a-b<<"\n";
  }
  return 0; 
} 

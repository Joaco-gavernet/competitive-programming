#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"



int main() {
  FIN;
  ll n; cin>>n;
  if(n==2){cout<<"-1\n"; return 0;}
  ll tam=(n+1)/2;
  cout<<tam<<"\n";
  if(n%2){
    forn(i,tam-1){
      cout<<"o";
      forn(i,tam-1) cout<<".";
      cout<<"\n";
    }
    forn(i,tam) cout<<"o";
    cout<<"\n";
  }else{
    forn(i,tam-2){
      cout<<"o";
      forn(i,tam-1) cout<<".";
      cout<<"\n";
    }
    cout<<"oo";
    forn(i,tam-2) cout<<".";
    cout<<"\n";
    forn(i,tam) cout<<"o";
    cout<<"\n";
  }

  return 0; 
}

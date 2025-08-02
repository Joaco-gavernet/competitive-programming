#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '


int main() {
  FIN;
  ll A,B,C,D,E;
  cout<<"1 0 0"<<endl;
  cin>>A;
  cout<<"0 1 0"<<endl;
  cin>>B;
  cout<<"0 0 1"<<endl;
  cin>>C;
  cout<<"1 1 1"<<endl;
  cin>>D;
  cout<<"2 3 4"<<endl;
  cin>>E;
  ll x,y,z;
  if(A+B+C==D){
    x=A; y=B; z=C;
  }else if(2*A+3*B+4*C == E){
    x=A; y=B; z=C;
  }else if(2*D+B+2*C == E){
    y=B; z=C; x=(D-y-z);
  }else if(3*D+C-A == E){
    z=C; x=A; y=(D-z-x); 
  }else if(4*D-3*A-B){
    y=B; x=A; z=(D-B-A);
  }
  cout<<x<<" "<<y<<" "<<z<<endl;
  return 0;
}
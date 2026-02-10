#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"

const ll INF = 1e9+7;

int main() {
  FIN;
  ll n; cin>>n;
  ll minx=INF,miny=INF,maxx=0,maxy=0;
  forn(i,n){
    ll x,y; cin>>x>>y;
    minx=min(minx,x);
    miny=min(miny,y);
    maxx=max(maxx,x);
    maxy=max(maxy,y);
  }
  cout<<4<<"\n";
  cout<<minx<<" "<<miny<<"\n";
  cout<<maxx<<" "<<miny<<"\n";
  cout<<maxx<<" "<<maxy<<"\n";
  cout<<minx<<" "<<maxy<<"\n";
  return 0; 
}

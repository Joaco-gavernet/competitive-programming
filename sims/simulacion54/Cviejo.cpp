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
  ll r,c; cin>>r>>c;
  vector<vi> mat(r,vi(c));
  ll sum=0,cant=0;
  vi maxrow(r,0);
  vi maxcol(c,0);
  forn(i,r) forn(j,c){
    cin>>mat[i][j];
    if(mat[i][j]){
      cant++; sum+=mat[i][j];
    }
    maxrow[i]=max(maxrow[i],mat[i][j]);
    maxcol[j]=max(maxcol[j],mat[i][j]);
  }
  DBG(sum); DBG(cant);
  ll rec=cant;
  vb visto(c);
  forn(i,r){
    rec+=(maxrow[i]-1);
    forn(j,c) if(!visto[j] and maxrow[i]==maxcol[j]){visto[j]=true; break;}
  }
  forn(i,c) if(!visto[i]) rec+=(maxcol[i]-1);
  cout<<sum-rec<<"\n";


  return 0;
}
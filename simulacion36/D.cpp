#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

int main() {
  FIN; 
  int n,k; cin>>n>>k;
  vi sums;
  forn(i,k){
    string s; cin>>s;
    if(s=="undo"){
      int m; cin>>m;
      forn(j,m) sums.pop_back();
    }else{
      ll pas;
      pas=stoi(s);
      sums.pb(pas);
    }
  }
  ll ans=0;
  forn(i,SZ(sums)){
    ans=((ans+sums[i])%n +n) %n;
  }
  cout<<ans<<"\n";
  return 0;
}

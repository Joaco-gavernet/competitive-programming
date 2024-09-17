#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;
const int MOD = -1;
const int MAXN = -1;

int main() {
  FIN;
  int n,x; cin>>n>>x;
  vi v(n); forn(i,n) cin>>v[i];
  int cont=1,m=1;
  forn(i,n-1){
    if(v[i+1]-v[i]<=x) {cont++;} //cout<<v[i]<<endl;}
    else{
      m=max(m,cont);
      cont=1;
    }
  }
  m=max(m,cont);
  cout<<m<<"\n";  
  return 0;
}

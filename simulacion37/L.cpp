#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define fs first
#define ss second

int main() {
  FIN;
  int n,m,x,y; cin>>n>>m>>x>>y;
  vi shelf(n); forn(i,n) cin>>shelf[i];
  vi book(m); forn(i,m) cin>>book[i];
  sort(all(shelf)); reverse(all(shelf));
  sort(all(book)); reverse(all(book));
  ll posb=0,poss=0,ans=n,full=-1;
  bool res=true;
  if(book[0]>shelf[0]) res=false; 
  else{
    while(posb<m and poss<n){
      //~ ans++;
      posb+=y;
      poss++;
      while(posb<m and poss<n and book[posb]>shelf[poss] and full<poss-1){
	posb+=(x-y);
	ans--;
	full++;
      }
      if(posb<m and poss<n and book[posb]>shelf[poss]) res=false;
    }
    while(posb<m and full<n-1){
      full++; ans--;
      posb+=(x-y);
    }
    if(posb<m) res=false;
  }
  if(res) cout<<ans<<"\n";
  else cout<<"impossible\n";
  return 0;
}

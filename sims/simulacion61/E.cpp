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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================" << endl
#define ff first
#define ss second

int main() {
  FIN;
  ll h; cin >> h;
  ll k=200000/201;
  vi v(1,1), nv;
  ll d=0;
  forn(i,100){
    nv=v;
    forn(j,SZ(v)){
      if(j>0) v[j]+=nv[j-1];
      if(j<SZ(v)-1) v[j]+=nv[j+1];
    }
    if(i>0) v[0]+=nv[1];
    v.pb(1);
    if(v[0]>h) {v=nv; break;}
    d++;
  }
  /*forn(i,SZ(v)) cout << v[SZ(v)-1-i] << " ";
  forr(i,1,SZ(v)) cout << v[i] << " ";
  cout << endl;*/

  cout << k*201 << "\n";
  forn(i,k){
    cout << "0 " << 2*i << " 1\n";
    forn(j,100) cout << j+1 << " " << 2*i << " 0\n" << -j-1 << " " << 2*i << " 0\n";
  }
  vector <ii> ans;
  forn(j,SZ(v)) forn(i,k) {
    if(v[j]<=h){h-=v[j]; ans.pb({j,2*i});}
    if(v[j]<=h and j>0){h-=v[j]; ans.pb({-j,2*i});}
  }
  cout << SZ(ans) << " " << d << "\n";
  forn(i,SZ(ans)) cout << ans[i].ff << " " << ans[i].ss << "\n";
  return 0;
}
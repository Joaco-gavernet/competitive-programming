#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << '\n'
#define RAYA cerr << "===========================\n"

void solve(){
  ll n; cin>>n;
  map<string,ll> histo1,histo2;
  vector<string> pal1,pal2;
  forn(i,n){
    string s1,s2; cin>>s1>>s2;
    histo1[s1]++;
    histo2[s2]++;
    pal1.pb(s1);
    pal2.pb(s2);
  }
  histo1[pal1[0]]--; histo2[pal2[0]]--;
  bool correcto=true;
  forr(i,1,n){
    if (!(pal1[i]==pal1[i-1] or pal2[i]==pal2[i-1])){
      if(histo1[pal1[i-1]] or histo2[pal2[i-1]]) correcto=false;
    }
    histo1[pal1[i]]--;
    histo2[pal2[i]]--;
  }
  if(correcto) cout<<"Yes\n";
  else cout<<"No\n";
  return;
}

int main() {
  FIN;
  ll t; cin>>t;
  while(t--) solve();
  return 0;
}
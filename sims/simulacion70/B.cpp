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
#define RAYA cerr << "======================\n"

int main() {
  FIN;
  int n; cin >> n;
  vi v(10001);
  vi prev(10001,-1);
  vector<vi> ans(10001);
  vi b={1,2,5,10,20,50,100,200,500};
  vb s(10001,true);
  for(auto x : b){
    for(int i=1; i*x<=10000; i+=2) if(s[i*x]){
      ans[i*x].pb(x);
      if(i>1){
        ans[i*x].pb(x);
        prev[i*x]=(i-2)*x;
      }
      s[i*x]=false;
    }
  }
  for(auto x : b) forn(i,10001) if(s[i] and i/2<x and x<=i){
    s[i]=false;
    ans[i].pb(x);
    prev[i]=i-x;
  }
  for(auto x : b) forr(i,1,x) if(!s[i]) for(int j=1; j*x+i<=10000; j++) if(s[j*x+i]){
    forn(_,j) ans[j*x+i].pb(x);
    prev[j*x+i]=i;
    s[j*x+i]=false;
  }
  vi c={4,40,44,400,404,440,444};
  forn(i,10001) if(s[i]) for(auto d:c) if(i-d>=0 and (i-d)%200==0 and (i-d)/200%2==1){
    s[i]=false;
    forn(_,(i-d)/200) ans[i].pb(200);
    prev[i]=d;
    break;
  }
  //forn(i,10001) if(s[i]) DBG(i);
  if(s[n]) cout << "splittable\n";
  else{
    vi tot;
    while(n!=-1){
      if(!s[n])for(auto x : ans[n]) tot.pb(x);
      else forn(i,n) tot.pb(1);
      n=prev[n];
    }
    cout << SZ(tot) << "\n";
    for(auto x : tot) cout << x << " ";
    cout << "\n";
  }
  return 0; 
}
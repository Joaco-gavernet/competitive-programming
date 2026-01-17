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

int main() {
  FIN;
  vector<pair<ll,ll>> pass(3);
  cin>>pass[0].ff>>pass[1].ff>>pass[2].ff;
  pass[0].ss=0;
  pass[1].ss=1;
  pass[2].ss=2;
  sort(all(pass));
  ll a=pass[0].ff;
  ll b=pass[1].ff;
  ll c=pass[2].ff;
  if(a+b<c){cout << "No\n"; return 0;}
  if(c==0) cout<<"Yes\na\na\na\n";
  else if(b==0) cout<<"No\n";
  else if(a==0){
    if(b!=c) cout<<"No\n";
    else {
      string s0="a";
      string s1=s0; string s2=s0;
      forn(i,b) s2+='a';
      cout<<"Yes\n";
      if(pass[0].ss==0)cout<<s0<<"\n"<<s1<<"\n"<<s2<<"\n";
      if(pass[0].ss==1)cout<<s0<<"\n"<<s2<<"\n"<<s1<<"\n";
      if(pass[0].ss==2)cout<<s2<<"\n"<<s1<<"\n"<<s0<<"\n";
    }
  } else {
    string s0,s1,s2;
    forn(i,a) s0 += 'a', s1 += 'b', s2 += 'c';
    forr(x,a,b) s2 += 'c';
    forr(x,b,c) s2 += 'a';
    cout<<"Yes\n";
    if(pass[0].ss==0){
      if(pass[1].ss==1) cout<<s0<<"\n"<<s1<<"\n"<<s2<<"\n";
      else cout<<s1<<"\n"<<s0<<"\n"<<s2<<"\n";
    }
    if(pass[0].ss==1){
      if(pass[1].ss==0) cout<<s0<<"\n"<<s2<<"\n"<<s1<<"\n";
      else cout<<s1<<"\n"<<s2<<"\n"<<s0<<"\n";
    }
    if(pass[0].ss==2){
      if(pass[1].ss==0) cout<<s2<<"\n"<<s0<<"\n"<<s1<<"\n";
      else cout<<s2<<"\n"<<s1<<"\n"<<s0<<"\n";
    }
  }
  return 0;
}
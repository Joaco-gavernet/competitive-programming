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

ll sum(string &s){
  ll ans=0;
  for(auto u:s){
    ans+=(u-'A');
  }
  //~ DBG(ans);
  return ans;
}

void rotate(string &s,ll num){
  forn(i,SZ(s)){
    char c=s[i];
    //~ DBG(c);
    c=c-'A';
    //~ DBG(c);
    c=(c+num)%26;
    //~ DBG(c);
    //~ c=(c+26)%26;
    //~ DBG(c);
    s[i]=c+'A';
    //~ DBG(c+'A'); DBG(s[i]);
  }
  //~ DBG(s);
  return;
}

void decode(string &s1,string &s2){
  forn(i,SZ(s1)){
    char c=s1[i];
    c=c-'A';
    c+=(s2[i]-'A');
    c=c%26;
    s1[i]=c+'A';
  }
  return;
}

int main() {
  FIN; 
  string s; cin>>s;
  int n=SZ(s);
  int m=n/2;
  string s1=s.substr(0,m),s2=s.substr(m,m);
  //~ DBG(s1); DBG(s2);
  ll sum1=sum(s1),sum2=sum(s2);
  rotate(s1,sum1); rotate(s2,sum2);
  //~ DBG(s1);
  decode(s1,s2);
  //~ DBG(s1);
  cout<<s1<<"\n";
  return 0;
}

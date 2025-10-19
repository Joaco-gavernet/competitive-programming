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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=======================" << endl 
#define ff first
#define ss second


int main() {
  FIN;
  ll inc=5;
  string s;
  ll test=5;
  ll cont=0;
  while(inc ==test){
    s+='A'; cont++;
    cout<<s<<endl;
    string SS; getline(cin,SS); stringstream line(SS);
    string aux; line>>aux>>aux; 
    if(aux=="GRANTED") return 0;
    char c; line>>c>>test;
    while(line>>aux){};
    DBG(test);
  }
  ll correcto=9*cont+9;
  ll match=((test-5)/9)-1;
  while(test!=correcto){
    match=((test-5)/9)-1;
    if(s[match]=='Z') s[match]='a';
    else if(s[match]=='z') s[match]='0';
    else s[match]++;
    cout<<s<<endl;
    string SS; getline(cin,SS); stringstream line(SS);
    string aux; line>>aux>>aux; 
    if(aux=="GRANTED") return 0;
    char c; line>>c>>test;
    while(line>>aux){};
  }

  return 0; 
}

//ACCESS DENIED (5 ms)
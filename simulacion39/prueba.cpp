#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"



bool issubstr(string &b, string &bp, string &out){
  ll posb=0;
  ll posbp=0;
  while(posb<SZ(b) and posbp<SZ(bp)){
    if(b[posb]!=bp[posbp]){
      out+=b[posb];
    }else{
      posbp++;
    }
    posb++;
  }
  while(posb<SZ(b)){out+=b[posb]; posb++;} 
  if(posbp==SZ(bp)) return true;
  return false;
}


int main() {
  FIN;
  
  string a = "123456789";
  string b = "248";
  string c = "";
  
  DBG(issubstr(a, b, c));
  DBG(c); 
  
  return 0;
}

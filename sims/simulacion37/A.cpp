#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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


int main() {
  FIN;
  int n; cin>>n;
  string aux,aux2;
  getline(cin,aux);
  vector<pair<string,string>> v(n);
  forn(i,n){
    getline(cin,aux);
    v[i].second=aux;
    int pos=0;
    while(pos<SZ(aux) and !(aux[pos]-'A'>=0 and aux[pos]-'A'<26)) pos++;
    if(pos==SZ(aux)) v[i].first="$";
    else v[i].first=aux.substr(pos,SZ(aux)-pos);
  }
  sort(all(v));
  forn(i,n) cout<<v[i].second<<"\n";
  return 0;
}

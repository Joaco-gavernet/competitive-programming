#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v), end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=================================\n"



int main() {
  FIN;
  string s, p="Keine Loesung\n"; cin >> s;
  int n=SZ(s);

  if(n%2==1) {cout << p; return 0;}
  forn(i,n) if(i%2==0 and s[i]!=s[i+1]) {cout << p; return 0;}
  bool b=true;
  int cont=0;
  string ans;
  forn(i,n) if(i%2==0){
    if(cont==0){
      cont++;
      b=(s[i]==s[0]);
      ans+="[";
    }
    else{
      if(b!=(s[i]==s[0])){
        cont--;
        ans+="]";
      }
      else{
        cont++;
        ans+="[";
      }
    }
  }
  if(cont>0) cout << p;
  else cout << ans << "\n";
  return 0; 
}

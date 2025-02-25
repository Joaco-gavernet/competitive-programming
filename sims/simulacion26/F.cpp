#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<ll> vd; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) v.find(x) != v.end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "==========================\n"


__int128 conversion(string &s){
  int pos=SZ(s);
  __int128 p10=1;
  __int128 ans=0;
  while(pos--){
    ans=ans+(p10*(s[pos]-'0'));
    p10=p10*10;
  }
  return ans;
}

string inversa(int exp){
  __int128 nro=1;
  forn(i,exp) nro=nro<<1;
  string ans;
  while(nro > 0){
    char c='0'+(nro%10);
    ans=ans+c;
    nro/=10;
  }
  reverse(all(ans));
  return ans;
}

bool comprimir(vd &v) {
  int n = SZ(v);
  vd ans;
  bool done = false;  
  if (n == 2) {
    if (v[0] == v[1]) {
      v = {v[0] +1};
      return true; 
    } else return false; 
  }
  forr(i,1,n) {
    if (v[i] == v[i-1]){
      ans.pb(v[i]+1);
      forr(x,i+1,n) ans.pb(v[x]);
      v=ans;
      return true;
    } 
    else ans.pb(v[i-1]); 
  }
  if (n > 2 and v[n-1] != v[n-2]) ans.pb(v[n-1]); 
  v = ans; 
  return done; 
}

void eliminar(vd &v) {
  int n = SZ(v); 
  vd ans; 
  if (n == 2){
    v = {*max_element(all(v))};
    return;
  }
  else {
    //Caso 0
    if(v[1]<=v[0]){ans.pb(v[0]);}
    //Casos medios
    forr(i,1,n-1){
      if(v[i]>v[i-1] or v[i]>v[i+1]) ans.pb(v[i]);
    }
    //Caso n-1
    if(v[n-2]<=v[n-1]){ ans.pb(v[n-1]); }
  }
  v=ans;
  return;
}

int main() {
  FIN; 
  int n;
  cin >> n;
  vd v(n);
  forn(i,n) {
    string s; cin>>s;
    __int128 x = conversion(s);
    int cont = 0; 
    while (x %2 == 0) cont++, x>>=1; 
    v[i] = cont; 
  }
  while (SZ(v) > 1) {
    if (comprimir(v) == false) eliminar(v); 
    //~ DBGV(v,SZ(v)); 
    //~ cerr<<endl;
  }
  cout << inversa(*v.begin()) << endl; 

  return 0;
}

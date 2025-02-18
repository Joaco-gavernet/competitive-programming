#include <bits/stdc++.h>
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end() 


int main() {
  FIN;
  vi t(4);
  forn(i,4){
    char c;
    cin >> c;
    t[i]=(t[i]*10)+(c-'0');
    cin >> c;
    if(c!='.'){
      t[i]=(t[i]*10)+(c-'0');
      cin >> c;
    }
    cin >> c;
    t[i]=(t[i]*10)+(c-'0');
    cin >> c;
    t[i]=(t[i]*10)+(c-'0');
  }
  sort(all(t));
  ll f=0;
  char c;
  cin >> c;
  f=(f*10)+(c-'0');
  cin >> c;
  if(c!='.'){
    f=(f*10)+(c-'0');
    cin >> c;
  }
  cin>>c;
  f=(f*10)+(c-'0');
  cin >> c;
  f=(f*10)+(c-'0');
  ll cota=(3*f)-(t[1])-(t[2]);
  if(t[3]<=cota) cout << "infinite\n";
  else if(t[0]>cota) cout << "impossible\n";
  else cout << cota/100 << "." << (cota/10)%10 << cota%10 << "\n";
  return 0;
}  

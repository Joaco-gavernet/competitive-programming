#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back

const int MAXN = -1;
const int MOD = -1;
const int INF = -1;


int main() {
  FIN;
  int n,k; cin>>n>>k;
  vector<bool> light(n+1,true);
  int cont=0,maxi=0;
  forn(i,k){
    int x,aux; cin>>x; aux=x;
    while(aux<=n){
      if(light[aux]){
	cont++;
      }else{
	cont--;
      }
      light[aux]=(!light[aux]);
      aux+=x;
    }
    maxi=max(maxi,cont);
  }
  cout<<maxi<<"\n";
  return 0;
}

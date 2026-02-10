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
#define RAYA cerr << "==================================\n"


int main() {
  FIN;
  int n; cin >> n;
  forn(i,n){
    char a='a'+i%20, A='A'+i%20, s='!'+i%10;
    cout << a << A << s;
    cout << i << i;
    int d=0, aux=i;
    while(aux!=0){aux/=10;d++;}
    if(d==0) d++;
    d*=2;
    d+=3;
    while(d<12){
      cout << "J";
      d++;
    }
    cout << "\n";
  }
  return 0; 
}

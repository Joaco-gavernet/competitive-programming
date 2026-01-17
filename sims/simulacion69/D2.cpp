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
  int a, b, c; cin >> a >> b >> c;
  if(a+b<c or a+c<b or c+b<a) {cout << "No\n"; return 0;}
  cout << "Yes\n";
  string s;
  forn(i,20) s+='x';
  cout << s << s << "\n";
  int k=a+b, A=a, B=0;
  while(k>c){
    if(A>0) A--;
    else B++;
    k--;
  }
  DBG(A); DBG(B);
  cout << s;
  forn(i,A) cout << 'a';
  cout << s;
  forn(i,B) cout << 'b';
  forn(i,a-A-B) cout << 'a';
  cout << "\n";
  cout << s << s;
  forn(i,b) cout << 'b';
  cout << "\n";
  return 0;
}
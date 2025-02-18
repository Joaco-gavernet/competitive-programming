#include <bits/stdc++.h>
using namespace std; 


typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define all(v) (v).begin(), (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '


int main() {
  FIN;

  int n; cin >> n; 
  vi a(n), b(n);
  forn(i,n){
    cin >> a[i];
    b[i]=a[i];
  }
  sort(all(b));
  int l=-1, r=-1;
  forn(i,n) if(a[i]!=b[i]) {l=i; break;}
  if(l==-1) {cout << "1 1\n"; return 0;}
  for(int i=n-1; i>-1;i--) if(a[i]!=b[i]) {r=i; break;}
  int ansl=l+1, ansr=r+1;
  while(l<r) {swap(a[l], a[r]); l++; r--;}
  forn(i,n) if(a[i]!=b[i]) {cout << "impossible\n"; return 0;}
  cout << ansl << " " << ansr << "\n";
  return 0;
} 

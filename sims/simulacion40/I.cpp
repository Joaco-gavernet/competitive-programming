#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define fs first
#define ss second
#define forr(i,a,b) for (int i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '
#define esta(x,v) (v).find(x) != (v).end() 

const int MAXN = 2005; 

int main() {
  ll n, d; cin >> n >> d; 
  vi cont(n); 

  forn(i,d) { 
    int a, b; cin >> a >> b; 
    cont[--a]++; cont[--b]++; 
  }

  multiset<ll> st(all(cont)); 
  while (*st.begin() < *st.rbegin()) {
    ll a = *st.begin(); st.erase(st.begin()); 
    ll b = *st.begin(); st.erase(st.begin()); 
    a++; b++; 
    st.insert(a); st.insert(b); 
  } 

  cout << *st.begin() << '\n';

  return 0;
} 

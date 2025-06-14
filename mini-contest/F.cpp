#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define SZ(x) int((x).size()) 
#define RAYA cerr << "===============================" << endl



int query(int x) {
  cout << "? " << x << endl; 
  int val; cin >> val; 
  return val; 
} 

int main(){
  int n; cin >> n; 

  if (n == 1) {
    cout << "! " << 1 << endl; 
    return 0; 
  } 

  vi a(n+10, -1); 
  a[1] = query(1); 
  a[2] = query(2); 
  if (a[1] < a[2]) {
    cout << "! " << 1 << endl; 
    return 0; 
  } 

  a[n] = query(n); 
  a[n-1] = query(n-1); 
  if (a[n-1] > a[n]) {
    cout << "! " << n << endl; 
    return 0; 
  } 


  int l = 2, r = n-1; 
  while (l + 2 < r) {
    int mid = (l + r) /2; 
    a[mid] = query(mid); 
    a[mid+1] = query(mid+1); 

    if (a[mid] < a[mid+1]) r = mid +1; 
    else l = mid; 
  } 

  int pos = l -1, mn = 1<<30, ans = -1; 
  forn(i,5) {
    int aux = query(pos +i); 
    if (aux < mn) mn = aux, ans = pos +i; 
  } 

  cout << "! " << ans << endl; 



  return 0;
}

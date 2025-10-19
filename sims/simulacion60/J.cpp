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
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=======================" << endl 
#define ff first
#define ss second

const int N = 360; 

int main() {
  FIN;

  int n; cin >> n; 
  vi lon(n); 
  forn(i,n) {
    int lat; cin >> lat >> lon[i]; 
    lon[i] += 180;
    lon[i] *= 2; 
  }

  vb visto(2*N); 
  forn(i,n) {
    int j = (i +1) %n; 
    int dif = lon[j] -lon[i]; 
    (dif += 2*N) %= 2*N; 
    // cerr << i << " " << j << endl; 
    // cerr << lon[i] << " " << lon[j] << endl; 
    // DBG(dif); 


    if (dif == 360) {
      cout << "yes" << endl; 
      return 0;
    }
    if (dif < 360) {
      if (lon[i] <= lon[j]) {
        for (int x = lon[i]; x <= lon[j]; x++) visto[x] = true; 
      } else {
        for (int x = lon[i]; x < 2*N; x++) visto[x] = true; 
        for (int x = 0; x <= lon[j]; x++) visto[x] = true; 
      }
    } else {
      if (lon[j] <= lon[i]) {
        for (int x = lon[j]; x <= lon[i]; x++) visto[x] = true; 
      } else {
        for (int x = lon[j]; x < 2*N; x++) visto[x] = true; 
        for (int x = 0; x <= lon[i]; x++) visto[x] = true; 
      }
    }
  }

  int pos = -1; 
  forn(i,2*N) if (visto[i] == false) pos = i; 
  if (pos == -1) cout << "yes" << endl;
  else {
    cout << "no "; 
    double ans = (1.0*pos)/2 -180;
    cout << fixed << setprecision(1); 
    cout << ans << endl; 
  }

  return 0; 
}
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
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================" << endl
#define ff first
#define ss second

ll sum=0;

bool check(vi &v, priority_queue<ll> &pq) {
  while (SZ(v) and SZ(pq)) {
    if (v.back() > pq.top()) return false;
    ll aux = pq.top(); pq.pop();
    aux -= v.back(); v.pop_back();
    pq.push(aux); 
  }
  return SZ(v) == 0; 
}

int main() {
  FIN;

  int H, T; cin >> H >> T; 
  vi C(H); forn(i,H) cin >> C[i]; 
  vi D(T), I(T); forn(i,T) cin >> D[i] >> I[i]; 

  vi interv; 
  forn(y,16) {
    int last = -1; 
    forn(x,H) {
      if (C[x] >= y+1) {
        if (last == -1) last = x;
      } else {
        if (last > -1){
          interv.pb(x-last);
          sum+=(x-last); 
        }
        last = -1; 
      }
    }
    if (last > -1){
      interv.pb(H-last);
      sum+=(H-last); 
    }
  }
  sort(all(interv)); 
  reverse(all(interv)); 
  if (SZ(interv) > T) {
    cout << "0" << '\n';
    return 0; 
  }

  ll ans = 0; 
  forn(mask,(1<<T)) {
    priority_queue<ll> pq; 
    for (auto x: interv) pq.push(x);
    vi v; 
    ll act = 0; 
    ll cont = 0;
    forn(i,T) if ((1<<i) & mask) v.pb(D[i]), cont += D[i], act += I[i]; 
    sort(all(v)); 
    if (cont == sum and check(v, pq)) ans = max(ans, act); 
  }
  cout << ans << '\n'; 
  
  return 0;
}
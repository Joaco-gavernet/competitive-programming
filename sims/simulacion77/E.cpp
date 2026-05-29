#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

ll be(ll a, ll b, ll p){
  if(b==0) return 1;
  ll k=be(a,b/2,p);
  if(b%2==0) return k*k%p;
  else return k*k%p*a%p;
}

vi f(ll x, ll n){
  vi v;
  forn(i,n){
    v.pb(x%4);
    x/=4;
  }
  reverse(all(v));
  return v;
}

bool check(ll x, ll y, ll n){
  vi a=f(x,n), b=f(y,n);
  forn(i,n) if (a[i] % 2 == 0 and b[i] % 2) return false; 
  forn(i,n-1) if(a[i]!=3 and a[i+1]!=1 and b[i]!=2 and b[i+1]!=0) return false;
  return true;
}

int main() {
  FIN;
  ll n, m, p;
  cin >> n >> m >> p;
  if(n%2==1 and m%2==1) {cout << "1\n"; return 0;}
  if(n%2==1){cout << be(m/2+1,n/2,p) << "\n"; return 0;}
  if(m%2==1){cout << be(n/2+1,m/2,p) << "\n"; return 0;}
  vi v;
  RAYA; 
  forn(i,1<<(n/2)) forn(j,n/2+1){
    ll x=0;
    forn(t,n/2){
      x*=4;
      if(t<j) x+=2;
      if(((1<<t)&i)!=0) x+=1;
    }
    v.pb(x);
  }
  vii trans;
  RAYA; 
  forn(i,SZ(v)) forn(j,SZ(v)) if(check(v[i],v[j],n/2)) trans.pb({i,j});
  DBG(SZ(trans));
  RAYA; 
  vi dp(SZ(v),1);
  forn(i,m/2-1){
    vi _dp(SZ(v));
    for(auto [a,b] : trans) _dp[b]+=dp[a];
    swap(dp,_dp);
  }
  RAYA; 
  ll ans=0;
  forn(i,SZ(dp)) ans=(ans+dp[i])%p;
  cout << ans << "\n";
  return 0;
}
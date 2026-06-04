#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "================================\n"
#define ff first
#define ss second 


int main() {
  FIN;
  ll a, b; cin >> a >> b;
  ll tot=max(a,b)+1;
  vb primo(tot,true);
  primo[0]=false; primo[1]=false;
  forr(p,2,tot) if(primo[p]) for(int k=p*p; k<tot; k+=p) primo[k]=false;
  ll n=1, m=1;
  for(ll p=tot-1; p>1; p--) if(primo[p] and (a%p==0 or b%p==0)){
    ll e=0;
    int t=0;
    if(b%p==0) t=1;
    while(a%p==0){a/=p; e++;}
    while(b%p==0){b/=p; e++;}
    if(e%2==0){
      if(t==0) m*=p;
      else n*=p;
    }
    forn(i,(e+2)/2){
      if(t==0) n*=p;
      else m*=p;
    }
    if(e%2==0) continue;
    ll k=p-1;
    if(t==0) b*=k;
    else a*=k;
    ll g=__gcd(a,b);
    a/=g;
    b/=g;
  }
  cout << n << " " << m << "\n";
  return 0; 
} 

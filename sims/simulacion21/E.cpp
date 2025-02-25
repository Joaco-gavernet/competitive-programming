#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << " ======================= \n"

const int MAXN = -1;
const int MOD = -1;
const int INF = -1;


int main() {
  FIN;
  cout<<fixed<<setprecision(2);
  int p; cin>>p;
  vector<string> s(p);
  vector<int> inf(p),sup(p);
  int cotamin=0, cotamax=0;
  forn(i,p){
    cin>>s[i];
    int k; cin>>k;
    inf[i]=max((k-1)*100+50,0); cotamin+=inf[i];
    sup[i]=min(10000,k*100+49); cotamax+=sup[i];
  }
  if(cotamin>10000 or cotamax<10000){
    //cout<<cotamin<<" "<<cotamax<<endl;
    cout<<"IMPOSSIBLE\n"; 
    return 0;
  }
  vector<int> ansinf(p),anssup(p);
  forn(i,p){
    ansinf[i]=max(inf[i],10000-cotamax+sup[i]);
    anssup[i]=min(sup[i],10000-cotamin+inf[i]);
    cout<<s[i]<<" "<<(double)ansinf[i]/100<<" "<<(double)anssup[i]/100<<"\n";
  }
  return 0;
}

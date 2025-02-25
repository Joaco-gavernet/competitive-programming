/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 1e6+5;

int main(){  
  FIN;
  int N; cin>>N;
  vector<int> prec(N+5,0);
  bitset<MAXN> sigue;
  int t=1; int ans=N;
  int psinvoc=0;
  forn(i,N){
    string s; cin>>s;
    int cont=0; int lim=min(SZ(s),3);
    forn(w,lim){
      if((s[w]=='A')||(s[w]=='E')||(s[w]=='I')||(s[w]=='O')||(s[w]=='U')||(s[w]=='Y')){sigue[i]=1; psinvoc=0; prec[i+1]=cont; break;}else{cont++;}
    }
    if(!sigue[i]){psinvoc++; prec[i+1]=min(cont,3);}
    if(psinvoc>2){cout<<"*"<<"\n"; return 0;} 
     //cout<<prec[i+1]<<"\n";
  }
  
  while(t<=N){
    //bool corte=(t<=N-2)&&(!sigue[t-1])&&(!sigue[t])&&(!sigue[t+1]);
    if(prec[t+2]==0){t+=3;}else if (prec[t+1]==0){t+=2;}else{
      if(prec[t]==0){
	t++;
      }else if((prec[t+1]==1)&&(sigue[t])){ans++; t+=2;}
      else if(prec[t]==3){cout<<"*"<<"\n"; return 0;}else{ans+=prec[t]; t++;}
      
    }
  }
  cout<<ans<<"\n";
  return 0;
}

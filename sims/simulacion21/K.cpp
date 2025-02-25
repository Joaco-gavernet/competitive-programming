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

const int MAXN = 1e9+7;
const int MOD = -1;
const int INF = -1;

vector<int> z_function(string s){
  int n=(int) s.size();
  vector<int> z(n);
  for(int i=1,l=0,r=0;i<n;++i){
    if(i<=r)
      z[i]=min(r-i+1,z[i-l]);
    while(i+z[i]<n && s[z[i]]==s[i+z[i]])
      z[i]++;
    if(i+z[i]-1>r)
      l=i,r=i+z[i]-1;
  }
  return z;
}

int solve(int n, string &s){
  vector<int> zf;
  int ans=0; int prev=MAXN;
  while(n){
    zf=z_function(s);
    int imax=n-1;
    while((imax>prev)or(imax>0 and zf[imax]<imax)){
      imax--;
    }
    //~ forr(i,1,n){
      //~ if(zf[i]>=i) imax=i;
    //~ }
    if(imax==0){
      ans++;
      s=s.substr(1,n-1);
      n--;
      prev=MAXN;
    }else{
      s=s.substr(imax,n-imax); 
      //cout<<imax<<" "<<s<<endl;
      n-=(imax);
      prev=imax;
    }
  }
  return ans;
}

int main() {
  FIN;
  int n; cin>>n;
  string s; cin>>s;
  int aux,ans=MAXN;
  forn(i,n){
    string s1=s.substr(0,i),s2=s.substr(i,n-i);
    aux=solve(i,s1)+solve(n-i,s2);
    ans=min(ans,aux);
  }
  cout<<ans<<"\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<bool> vb;

#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << (c) << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << " "; cerr << endl
#define RAYA cerr << " ============================= " << endl
#define pb push_back
#define all(c) (c).begin(),(c).end()

const int INF = -1;
const int MOD = -1;
const int MAXN = -1;

#define RB(x) (x<n?r[x]:0)
void csort(vector<int> &sa, vector<int> &r, int k){
  int n=sa.size();
  vector<int> f(max(255,n),0),t(n);
  forr(i,0,n) f[RB(i+k)]++;
  int sum=0;
  forr(i,0,max(255,n)) f[i]=(sum+=f[i])-f[i];
  forr(i,0,n) t[f[RB(sa[i]+k)]++]=sa[i];
  sa=t;
}

vector<int> suffix_array(string &s){
  s +='$';
  int n=s.size(),rank;
  vector<int> sa(n),r(n),t(n);
  forr(i,0,n) sa[i]=i,r[i]=s[i];
  for(int k=1; k<n; k*=2){
    csort(sa,r,k); csort(sa,r,0);
    t[sa[0]]=rank=0;
    forr(i,1,n){
      if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k)) rank++;
      t[sa[i]]=rank;
    }
    r=t;
    if(r[sa[n-1]]==n-1) break;
  }
  return sa;
}

int binsearch(vector<int> &sa,string &s,char c,int len,int l,int r){
  int med=(r+l)/2;
  while(r-1>l){
    if(s[sa[med]+len]<c) l=med;
    else r=med;
    med=(l+r)/2;
  }
  return r;
}
 
void solve(vector<int> &sa, string &city, string &name){
  int ans=0,l=-1,r=SZ(city);
  int punt=0,len=0;
  while(punt<SZ(name)){
    //Veo primera con let
    l=binsearch(sa,city,name[punt],len,l,r);
    //Veo ultima con let
    r=binsearch(sa,city,name[punt]+1,len,l,r);
    //~ cout<<name[punt]<<" "<<l<<" "<<r<<" "<<len<<endl;
    //~ if(l>=SZ(sa)){cout<<-1<<"\n"; return;}
    if(l==r or (sa[l]+len<SZ(city) and city[sa[l]+len]!=name[punt])){
      if(len==0){cout<<-1<<"\n"; return;}
      len=0; ans++;
      l=-1; r=SZ(city);
    }else{
      len++;
      punt++;
      l--;
    }
  }
  cout<<ans+1<<"\n";
  return;
}

int main() {
  FIN;
  string city; cin>>city; int n; cin>>n;
  vector<string> names(n); forn(i,n) cin>>names[i];
  vector<int> sa=suffix_array(city);
  //~ for(auto u:sa) {cout<<u<<" ";} cout<< endl;
  forn(i,n){
    solve(sa,city,names[i]);
  }
  return 0;
}

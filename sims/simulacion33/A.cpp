#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "======================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '



int main() {
  FIN; 
  int n; cin>>n;
  vector<string> s(n); forn(i,n) cin>>s[i];
  int s1=0,s2=0,points=0;
  forn(i,n){
    int a,b;
    if(s[i][2]=='-'){
      a=10+s[i][1]-'0';
      if(SZ(s[i])==5) b=10+(s[i][4]-'0');
      else b=s[i][3]-'0';
    }else{
      a=s[i][0]-'0';
      if(SZ(s[i])==4) b=10+(s[i][3]-'0');
      else b=s[i][2]-'0';
    }
    points=s1+s2;
    int sum=a+b;
    //~ DBG(a); DBG(b); DBG(s1); DBG(s2);
    if(sum-points < 0 or sum>21){
      cout<<"error "<<i+1<<"\n";
      return 0;
    }else{
      //~ DBG(a); DBG(b); DBG(s1); DBG(s2);
      if(sum%4==1 or sum%4==2){
	//sirve Bob
	//~ cout<<"SIRVE BOB\n";
	if(b>11 or a>11 or (s1==11 and s2!=a) or (s2==11 and s1!=b) or (b<s1) or (a<s2)){
	  cout<<"error "<<i+1<<"\n";
	  return 0;
	}
	s1=b; s2=a;
      }else{
	//sirve Alice
	//~ cout<<"SIRVE ALICE\n";
	if(b>11 or a>11 or (s1==11 and s2!=b) or (s2==11 and s1!=a) or (b<s2) or (a<s1)){
	  cout<<"error "<<i+1<<"\n";
	  return 0;
	}
	s1=a; s2=b;
      }
    }
  }
  cout<<"ok\n";
  return 0;
}

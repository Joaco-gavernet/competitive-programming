#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back
#define esta(x,v) v.find(x) != v.end()
#define all(v) (v).begin(),(v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

int main() {
  FIN; 
  vector<vector<string>> palabras(21,vector<string>());
  int n; cin>>n;
  forn(i,n){
    string pal; cin>>pal;
    palabras[SZ(pal)].pb(pal);
  }
  ll ans=0;
  forr(i,3,21){
    vector<string> v=palabras[i];
    vector<string> queries;
    int t=SZ(v);
    forn(k,t){
      forr(j,k+1,t){
	string s1=v[k],s2=v[j];
	s1 +='$'; 
	s2 +='$'; 
	int pos=-1;
	forn(x,i){
	  //~ cout<<s1[x]<<s2[x]<<endl;
	  if(s1[x]!=s2[x]){
	    if(pos==-1 and s1[x+1]!=s2[x+1]){pos=x; x++;}
	    else{pos=-1; break;}
	  }
	}
	if (s1 > s2) swap(s1, s2); 
	string ss="$"; forn(q,2*i-1){ss=ss+'$';}
	if(pos!=-1){
	  ss[pos]=s1[pos]; ss[pos+1]=s1[pos+1]; 
	  ss[pos+i]=s2[pos]; ss[pos+1+i]=s2[pos+1];
	  queries.pb(ss);
	}
      }
    }
    sort(all(queries));
    //~ for(auto u:queries) cout<<u<<endl;
    int cont=1,posib=SZ(queries);
    if(posib==0) continue;
    else if(posib==1) ans++;
    else{
      if(queries[0]!=queries[1]) ans++;
      while(cont<posib-1){
	if((queries[cont]!=queries[cont-1])and(queries[cont]!=queries[cont+1])){ans++;}
	cont++;
      }
      if((queries[posib-1]!=queries[posib-2])) ans++;
    }
  }
  cout<<ans<<"\n";
  return 0;
}

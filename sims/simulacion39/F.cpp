#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define esta(x,v) (v).find(x) != (v).end()
#define all(v) (v).begin(),(v).end() 
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"

string lltostring(ll x){
  string ans="";
  while(x){
    ans+=(x%10+'0');
    x/=10;
  }
  reverse(all(ans));
  if(ans=="") return "0";
  return ans;
}

ll stringtoll(string &s){
  //~ DBG(s);
  ll ans=0;
  ll pot10=1;
  forn(i,SZ(s)){
    ans+=((s[SZ(s)-1-i]-'0')*pot10);
    pot10*=10;
  }
  return ans;
}

bool issubstr(string &b,string &bp,string &out){
  ll posb=0;
  ll posbp=0;
  while(posb<SZ(b) and posbp<SZ(bp)){
    if(b[posb]!=bp[posbp]){
      out+=b[posb];
    }else{
      posbp++;
    }
    posb++;
  }
  while(posb<SZ(b)){out+=b[posb]; posb++;} 
  if(posbp==SZ(bp)) return true;
  return false;
}


int main() {
  FIN;
  ll a,b,c,d;
  cin>>a>>b>>c>>d;
  ll ma=0,mb=0;
  ll a2=a,b2=b;
  while(a2){
    ma++;
    a2/=10;
  }
  while(b2){
    mb++;
    b2/=10;
  }
  string sa=lltostring(a);
  string sb=lltostring(b);
  //~ RAYA;
  forn(i,(1<<ma)-1){
    bool first=true;
    ll ap=0;
    string borradoa="",borradob="";
    string sap="",sbp="";
    forn(j,ma){
      ll bit=1<<j;
      if((i & bit)){
	borradoa+=sa[j];
      }else if(first and sa[j]=='0') break;
      else{
	first=false;
	sap+=sa[j];
      }
    }
    //~ DBG(borradoa);
    //~ RAYA;
    //~ DBG(first);
    if(first==false){
      ap=stringtoll(sap);
      //~ DBG(sap);
      __int128 aux=(__int128)d*ap;
      if((aux)%c==0){
	ll bp=0;
	__int128 bpp=(aux)/c;
	if(bpp > 1e18) continue;
	else bp=bpp;
	//~ if(ap==164610823730) DBG(bp);
	sbp=lltostring(bp);
	if(issubstr(sb,sbp,borradob)){
	  sort(all(borradoa));
	  sort(all(borradob));

	  if(borradoa==borradob){
	    cout<<"possible\n";
	    cout<<ap<<" "<<bp<<"\n";
	    return 0;
	  }
	}
      }
    }
  }
  cout<<"impossible\n";
  return 0;
}

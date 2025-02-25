#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi;
typedef pair<ll,ll> ii; 
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define esta(v,x) (v).find(x) != (v).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '
#define RAYA cerr << "=================================\n"


int main() {
  FIN; 
  int n,m; cin>>n>>m;
  vector<vector<char>> mat(n,vector<char>(m));
  set<pair<ii,char>> hijos;
  ii fav;
  //~ RAYA;
  forn(i,n){
    forn(j,m){
      cin>>mat[i][j];
      if(mat[i][j]!='.'){
	if(mat[i][j]=='A') fav={i,j};
	else hijos.insert({{i,j},mat[i][j]});
      }
    }
  }
  //~ for(auto u:hijos) DBG(u.second);
  vector<ii> lims(n);
  //~ int c=fav.second;
  //~ RAYA;
  forn(i,n){
    int l=fav.second,r=fav.second;
    while(l>=0 and (mat[i][l]=='.' or mat[i][l]=='A')){l--;}
    if(l==-1 or (l<m-1 and mat[i][l]!='.' and mat[i][l]!='A')) l++;
    if(mat[i][l]!='.' and mat[i][l]!='A'){
      l=m+1; 
      r=-1;
    }else{
      while(r<=m-1 and (mat[i][r]=='.' or mat[i][r]=='A')){r++;}
      if(r==m or (r>0 and mat[i][r]!='.' and mat[i][r]!='A')) r--;
      if(mat[i][r]!='.' and mat[i][r]!='A'){
	l=m+1; 
	r=-1;
      }
    }
    lims[i]={l,r};
    //~ DBG(lims[i].first); DBG(lims[i].second);
  }
  ii fmax,cmax; ll amax=0,aux; 
  //~ RAYA;
  forr(f,1,n+1){
    multiset<ll> li,ld;
    int in=max(fav.first-f+1,0LL);
    forn(i,f){
      li.insert((-1)*lims[in+i].first);
      ld.insert(lims[in+i].second);
    }
    ll mini=*(li.begin()),maxi=*(ld.begin());
    aux=(((maxi)-(mini*(-1))+1)*f);
    if(aux>amax){
      //~ DBG(f); DBG(mini); DBG(maxi); DBG(aux);
      amax=aux;
      fmax={in,in+f-1};
      cmax={(-1)*mini,maxi};
    }
    forr(i,in+1,min(fav.first,n-f)){
      li.erase((-1)*lims[i-1].first);
      ld.erase(lims[i-1].second);
      li.insert((-1)*lims[i+f-1].first);
      ld.insert(lims[i+f-1].second);
      mini=*(li.begin()),maxi=*(ld.begin());
      aux=(((maxi)-(mini*(-1))+1)*f);
      if(aux>amax){
	//~ DBG(f); DBG(mini); DBG(maxi); DBG(aux);
	amax=aux;
	fmax={i,i+f-1};
	cmax={(-1)*mini,maxi};
      }
    }
  }
  //~ RAYA;
  forr(x,fmax.first,fmax.second+1){
    forr(y,cmax.first,cmax.second+1){
      if(mat[x][y]=='.') mat[x][y]='a';
      //~ DBG(x); DBG(y);
    }
  }
  //~ RAYA;
  for(auto u:hijos){
    //~ DBG(u.second);
    int x=u.first.first,y=u.first.second;
    char ch=u.second;
    int fs=x-1,fi=x+1;
    //~ DBG(ch);
    //~ DBG(y);
    while(fs>=0 and mat[fs][y]=='.'){fs--;}
    if(fs<0 or mat[fs][y]!='.') fs++;
    while(fi<=n-1 and mat[fi][y]=='.'){fi++;}
    if(fi>n-1 or mat[fi][y]!='.') fi--;
    bool corte=true;
    int ci=y,cd=y;
    forr(p,fs,fi+1){
      if(mat[p][y]=='.') mat[p][y]=(ch+32);
    }
    while(corte and ci>0){
      ci--;
      //~ DBG(ci); DBG(fs); DBG(fi);
      forr(p,fs,fi+1){
	if(mat[p][ci]!='.'){corte=false;}
      }
      if(corte){
	forr(p,fs,fi+1){
	  mat[p][ci]=(ch+32);
	}
	//~ DBG(ci);
      }else{
	ci++;
      }
    }
    corte=true;
    //~ DBG(cd);
    while(corte and cd<m-1){
      cd++;
      //~ DBG(cd);
      forr(p,fs,fi+1){
	if(mat[p][cd]!='.'){corte=false;}
      }
      if(corte){
	forr(p,fs,fi+1){
	  mat[p][cd]=(ch+32);
	}
      }else{
	cd--;
      }
    }
  }
  //~ RAYA;
  forn(i,n){
    forn(j,m){
      cout<<mat[i][j];
    }
    cout<<"\n";
  }
  return 0; 
}


#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++) 
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '
#define RAYA cerr << "==============================\n"

vector<vb> pending(10,vb(10,true));
vb descub(10,false);

void update(ll n){
  descub[n]=true;
  forn(i,n+1) forr(j,n,10) pending[i][j]=false;
  return;
}

bool check(ll act,ll n,ll &prev){
  ll aux;
  forr(i,act+1,n) if(!descub[i]){
    cout<<i+1<<" "<<i+1<<endl;
    cin>>aux;
    if(aux==n) return true;
    if(aux<prev) descub[i]=true;
    else if(aux>prev){
      cout<<i+1<<" "<<i+1<<endl;
      cin>>aux;
      //~ prev=aux;
      descub[i]=true;
      //~ update(i);
    }
    prev=aux;
  }
  //~ prev=aux;
  return false;
}

bool solve(ll act,ll fin,ll n,ll &prev){
  if(act==fin){
    if(pending[act][fin]){
      cout<<act+1<<" "<<fin+1<<endl;
      ll aux; cin>>aux;
      prev=aux;
      if(aux==n) return true;
      else{
	if(aux==(act+1)) update(act);
	prev=aux;
	return false;
      }
    }
    return false;
  }else{
    if(solve(act,fin-1,n,prev)) return true;
    if(pending[act][fin]){
      cout<<act+1<<" "<<fin+1<<endl;
      ll aux; cin>>aux;
      if(aux==n) return true;
      else if(aux>prev){
	if(check(act,n,aux)) return true;
	else if(aux==act+1){
	  update(act);
	  prev=aux;
	  //~ return false;
	}
      }
      prev=aux;
      if(solve(act,fin-1,n,prev)) return true;
    }
    return false;
  }
  return false;
}

int main() {
  FIN; 
  ll n; cin>>n;
  ll k; cin>>k;
  if(k==n) return true;
  if(check(-1,n,k)) return 0;
  forn(i,n){
    if(solve(i,n-1,n,k)) return 0;
  }
  return 0; 
} 

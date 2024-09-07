#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i< (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define fs first
#define ss second

const int MAXN = 1e9+7;
const int INF = -1;
const int MOD = -1;
const long double EPS = 1e-10;


int main() {
  FIN;
  int h,w; cin>>h>>w;
  vector<string> lines(h); forn(i,h){cin>>lines[i];}
  cout << fixed << setprecision(10);
  vector<vector<long double>> dpa(h+1,vector<long double>(w+1,MAXN));
  dpa[0][0]=0;
  vector<vector<int>> dpc(h+1,vector<int>(w+1,0));
  long double seg=((long double)3.14159265358979323846264)*10/4;
  forr(i,1,h+1){
    dpa[i][0]=10*i;
    //if(lines[i-1][0]=='O'){dpc[i][0]++;}
  }
  forr(i,1,w+1){
    dpa[0][i]=10*i;
    //if(lines[0][i-1]=='O'){dpc[0][i]++;}
  }
  forr(i,1,h+1){
    forr(j,1,w+1){
      dpa[i][j] = dpa[i-1][j];
      if (dpa[i][j-1] -EPS < dpa[i-1][j]) 
	dpa[i][j] = dpa[i][j-1];
      dpa[i][j] += 10;
      if(lines[i-1][j-1]=='O'){
	dpc[i][j]=dpc[i-1][j-1]+1;
	int aux=dpc[i][j];
	//horizontal
	if ((i>1)and(lines[i-2][j-1]=='O')and((dpa[i-2][j-1]+ 2*seg+10 -EPS) < dpa[i][j])) 
	  dpa[i][j] = dpa[i-2][j-1]+ 2*seg+10;
	//vertical
	if ((j>1)and(lines[i-1][j-2]=='O')and((dpa[i-1][j-2]+ 2*seg+10 -EPS) < dpa[i][j])) 
	  dpa[i][j] = dpa[i-1][j-2]+ 2*seg+10;
	//diagonal
	if ((dpa[i-aux][j-aux]+(2*aux-1)*seg+10 -EPS) < dpa[i][j]) 
	  dpa[i][j] = dpa[i-aux][j-aux]+(2*aux-1)*seg+10;
      }
    }
  }
  //~ forn(i,h+1){
    //~ forn(j,w+1){
      //~ cout<<dpa[i][j]<<" ";
    //~ }
    //~ cout<<endl;
  //~ }
  cout<<dpa[h][w]<<"\n";
  return 0;
}

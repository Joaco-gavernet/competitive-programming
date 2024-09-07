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
  vector<vector<long double>> dpa(2*h+1,vector<long double>(2*w+1,MAXN));
  dpa[0][0]=0;
  //vector<vector<int>> dpc(h+1,vector<int>(w+1,0));
  long double seg=((long double)3.14159265358979323846264)*10/4;
  forr(i,1,2*h+1){
    dpa[i][0]=5*i;
    //if(lines[i-1][0]=='O'){dpc[i][0]++;}
  }
  forr(i,1,2*w+1){
    dpa[0][i]=5*i;
    //if(lines[0][i-1]=='O'){dpc[0][i]++;}
  }
  forr(i,1,2*h+1){
    forr(j,1,2*w+1){
      if(i%2){
	if ((j%2==0)){
	  if ((dpa[i-1][j]+5-EPS) < dpa[i][j]) 
	  dpa[i][j] = dpa[i-1][j]+5;
	  if ((lines[i/2][j/2-1]=='O')and((dpa[i-1][j-1]+seg-EPS) < dpa[i][j])) 
	  dpa[i][j] = dpa[i-1][j-1]+seg;
	}
      }else{
	if (j%2){
	  if ((lines[i/2-1][j/2]=='O')and((dpa[i-1][j-1]+seg-EPS) < dpa[i][j]))
	  dpa[i][j] = dpa[i-1][j-1]+seg;
	  if ((dpa[i][j-1]+5-EPS) < dpa[i][j]) 
	  dpa[i][j] = dpa[i][j-1]+5;
	}else{
	  if ((dpa[i-1][j]+5-EPS) < dpa[i][j]) 
	  dpa[i][j] = dpa[i-1][j]+5;
	  if ((dpa[i][j-1]+5-EPS) < dpa[i][j]) 
	  dpa[i][j] = dpa[i][j-1]+5;
	}
      }
    }
  }
  //~ forn(i,2*h+1){
    //~ forn(j,2*w+1){
      //~ cout<<dpa[i][j]<<" ";
    //~ }
    //~ cout<<endl;
  //~ }
  cout<<dpa[2*h][2*w]<<"\n";
  return 0;
}

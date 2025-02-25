#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = -1;
const int INF = -1;
const int MOD = -1;

struct elem{
  int cant; int val; char let;
  bool operator <(elem e) const{
    if(cant==e.cant) return val<e.val;
    else return cant>e.cant;
  }
};

int main() {
  FIN; 
  string s; cin>>s;
  int tam=SZ(s);
  vector<vector<int>> pf(tam+1,vector<int>(4,0));
  if(s[0]=='A') pf[1][0]++;
  if(s[0]=='T') pf[1][1]++;
  if(s[0]=='G') pf[1][2]++;
  if(s[0]=='C') pf[1][3]++;
  forr(i,1,tam){
    pf[i+1]=pf[i];
    if(s[i]=='A') pf[i+1][0]++;
    if(s[i]=='T') pf[i+1][1]++;
    if(s[i]=='G') pf[i+1][2]++;
    if(s[i]=='C') pf[i+1][3]++;
  }
  int n; cin>>n;
  while(n--){
   int l,r; cin>>l>>r;
   vector<elem> cant(4);
   cant[0].cant=pf[r][0]-pf[l-1][0]; cant[0].val=0; cant[0].let='A';
   cant[1].cant=pf[r][1]-pf[l-1][1]; cant[1].val=1; cant[1].let='T';
   cant[2].cant=pf[r][2]-pf[l-1][2]; cant[2].val=2; cant[2].let='G';
   cant[3].cant=pf[r][3]-pf[l-1][3]; cant[3].val=3; cant[3].let='C';
   sort(all(cant));
   cout<<cant[0].let<<cant[1].let<<cant[2].let<<cant[3].let<<"\n";;
  }
  return 0;
}

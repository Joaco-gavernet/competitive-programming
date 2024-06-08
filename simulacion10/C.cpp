#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
const ll INF = (ll)(1<<30); // (1LL<<60)
const int MAXN = (int)(2e5+5);


int main(){
  FIN;
  int n,q; 
  cin>>n>>q;
  set<int> s;
  forn(i,q){
    char c; cin>>c;
    if(c=='-'){
      int k; cin>>k;
      s.insert(k);
    }else if(c=='+'){
      int k; cin>>k;
      s.erase(k);
    }else{
      int x,y; cin>>x>>y;
      if(SZ(s)==0){
	cout<<"possible"<<"\n";
      }else{
	auto itx=s.lower_bound(x);
	if(itx==s.end()){itx=s.begin();}
	auto ity=s.lower_bound(y);
	if(ity==s.end()){ity=s.begin();}
	//cout<<x<<y<<*itx<<*ity<<endl;
	if((itx==ity)&&(*itx!=x)&&(*ity!=y)){
	  cout<<"possible"<<"\n";
	}else{
	  cout<<"impossible"<<"\n";
	}
      }
    }
  }
  
  
  return 0;
}

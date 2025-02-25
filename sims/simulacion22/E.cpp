#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define SZ(x) int((x).size())
#define DBG(c) cerr << #c << " = " << c << endl
#define RAYA cerr << "========================= \n"

const ll MAXN = -1;
const ll MOD = -1;
const ll INF = -1;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r){ // Random number in [l, r]
    return uniform_int_distribution<int>(l, r)(rng);
}
bool check(int x, int y, int a, int b, vector <pair<int,int>> &v, vector <pair<int,int>> &rv, int n){
  if(a==x and y==b) return true;
  set <pair<int,int>> s;
  s.insert({x,y});
  forn(i,n){
    int X=x+v[i].first,Y=y+v[i].second;
    if(1<=X and X<=n and 1<=Y and Y<=n) s.insert({X,Y});
  }
  forn(i,n){
    int X=a+rv[i].first,Y=b+rv[i].second;
    if(s.find({X,Y})!=s.end()) return true;
  }
  if(s.find({a,b})!=s.end()) return true;
  return false;
}

int main() {
  FIN;
  int n;
  cin >> n;
  int xa,ya,xb,yb;
  cin >> xa >> ya >> xb >> yb;
  vector <pair<int,int>> v(n), rv(n);
  forn(i,n){
    cin >> v[i].first >> v[i].second;
    rv[i].first=-v[i].first; rv[i].second=-v[i].second;
  }
  if(check(xa,ya,xb,yb,v,rv,n)) cout << "Alice wins\n";
  else if(n==2){
    if(!check(xb,yb,1,1,v,rv,n)) cout << "tie 1 1\n";
    else if(!check(xb,yb,1,2,v,rv,n)) cout << "tie 1 2\n";
    else if(!check(xb,yb,2,1,v,rv,n)) cout << "tie 2 1\n";
    else if(!check(xb,yb,2,2,v,rv,n)) cout << "tie 2 2\n";
    else cout << "Bob wins\n";
  }
  else if(n==3){
    forr(i,1,4) forr(j,1,4) if(!check(xb,yb,i,j,v,rv,n)){
      cout << "tie " << i << " " << j << "\n";
      return 0;
      }
    cout << "Bob wins\n";
  }
  else{
    bool listo=true;
    while(listo){
      int x=my_random(1,n),y=my_random(1,n);
      if(!check(xb,yb,x,y,v,rv,n)){cout << "tie " << x << " " << y << "\n"; listo=false;}
    }
  }

  return 0;
}

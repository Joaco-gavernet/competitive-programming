#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) begin(v),end(v)
#define SZ(x) int((x).size())
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "=======================" << endl 
#define ff first
#define ss second

typedef ll tipo;

struct punto {
  tipo x, y, id=-1; 
  punto const operator -(const punto &p) const { return {x-p.x, y-p.y, id}; }
  punto const operator +(const punto &p) const { return {x+p.x, y+p.y, id}; }
  tipo operator *(const punto &p) const { return x*p.x + y*p.y; }
  tipo operator ^(const punto &p) const { return x*p.y - y*p.x; }
  bool operator == (const punto &p) const {
    return (x == p.x and y == p.y);
  }
  bool operator < (punto p) const {
    return x != p.x ? x < p.x : y < p.y; 
  }
};

punto operator * (tipo k, const punto &p) { return {k*p.x, k*p.y}; }

punto origin = {0LL, 0LL}; 
bool AngularSort(const punto &A, const punto &B) {
  bool aorig = (A < origin);
  bool borig = (B < origin);
  if (aorig != borig) { return aorig > borig; }
  return (A^B) > 0;
}


int main() {
  FIN;
  vector <punto> p={{0,1},{1,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
  sort(all(p),AngularSort);
  forn(i,8) cout << p[i].x << " " << p[i].y << endl;
  return 0; 
}
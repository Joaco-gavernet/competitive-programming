#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define NaN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "/////////////////////////////\n"

int sint(string s){
  int n=0;
  forn(i,SZ(s)) n=n*10+s[i]-'0';
  return n;
}

int main() {
  NaN;
  string a, b, c, s, z;
  cin >> a >> s >> b >> z >> c;
  forr(i,1,SZ(a)) forr(j,1,SZ(b)){
    string a2=b.substr(0,j)+a.substr(i,SZ(a)-i), b2=a.substr(0,i)+b.substr(j,SZ(b)-j);
    if(s=="+" and sint(a2)+sint(b2)==sint(c)) {cout << a2 << " + " << b2 << " = " << c << "\n"; return 0;}
    if(s=="*" and sint(a2)*sint(b2)==sint(c)) {cout << a2 << " * " << b2 << " = " << c << "\n"; return 0;}
  }
  forr(i,1,SZ(a)) forr(j,1,SZ(c)){
    string a2=c.substr(0,j)+a.substr(i,SZ(a)-i), c2=a.substr(0,i)+c.substr(j,SZ(c)-j);
    if(s=="+" and sint(a2)+sint(b)==sint(c2)) {cout << a2 << " + " << b << " = " << c2 << "\n"; return 0;}
    if(s=="*" and sint(a2)*sint(b)==sint(c2)) {cout << a2 << " * " << b << " = " << c2 << "\n"; return 0;}
  }
  forr(i,1,SZ(b)) forr(j,1,SZ(c)){
    string b2=c.substr(0,j)+b.substr(i,SZ(b)-i), c2=b.substr(0,i)+c.substr(j,SZ(c)-j);
    if(s=="+" and sint(a)+sint(b2)==sint(c2)) {cout << a << " + " << b2 << " = " << c2 << "\n"; return 0;}
    if(s=="*" and sint(a)*sint(b2)==sint(c2)) {cout << a << " * " << b2 << " = " << c2 << "\n"; return 0;}
  }
  return 0; 
}
#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define forr(i,a,b) for(int i = (ll)a; i <(ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define pb push_back

vector<string> win(25);

int main() {
  //~ FIN;
  win[0]="ITMO";
  win[1]="SPbSU";
  win[2]="SPbSU";
  win[3]="ITMO";
  win[4]="ITMO";
  win[5]="SPbSU";
  win[6]="ITMO";
  win[7]="ITMO";
  win[8]="ITMO";
  win[9]="ITMO";
  win[10]="ITMO";
  win[11]="PetrSU, ITMO";
  win[12]="SPbSU";
  win[13]="SPbSU";
  win[14]="ITMO";
  win[15]="ITMO";
  win[16]="ITMO";
  win[17]="ITMO";
  win[18]="SPbSU";
  win[19]="ITMO";
  win[20]="ITMO";
  win[21]="ITMO";
  win[22]="ITMO";
  win[23]="SPbSU";
  win[24]="ITMO";
  int n; cin>>n;
  n-=1995;
  cout<<win[n]<<"\n";

  return 0; 
}

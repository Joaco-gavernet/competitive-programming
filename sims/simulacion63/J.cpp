#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==================================\n"


int main() {
  FIN;
  
  string op; cin >> op; 
  int n; cin >> n; 
  string s; cin >> s; 

  bool dif = false; 
  forn(i,n-1) if (s[i] != s[i+1]) dif = true;

  if (dif == false) {cout << s << '\n'; return 0;} 
  if (op == "Encode") {
    string aux(n, 'x'); 
    int i = 0;
    for (; dif and i < n and s[i] == s[0]; i++) aux[i] = '2';
    for (; i < n; i++) aux[i] = s[i];
    cout << aux << '\n';
  } else {
    int st=0;
    while(s[st]=='2') st++;
    while(s[st]!='2') st=(st+1)%n;
    int k=st;
    while(s[k]=='2') k=(k+1)%n;
    forn(i,n){
      if(s[(st+i)%n]=='2'){
        if(s[k]=='0') cout << '1';
        else cout << '0';
      }
      else cout << s[(st+i)%n];
    }
    cout << "\n";
  }

  return 0; 
}

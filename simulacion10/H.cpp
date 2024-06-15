/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

int main(){  
  FIN;
  
  string s[8]={"","abcdefv","aghijkw","bglmnox","chlpqry","dimpstz","ejnqsu","fkortu"};
  int sumas[8]={0,1,10,100,1000,10000,100000,1000000};
  map<int,char> m;
  char let='a';
  forr(i,1,7){
    forr(j,i+1,8){
      m[sumas[i]+sumas[j]]=let;
      let++;
    }
  }
  m[sumas[1]]='v';
  m[sumas[2]]='w';
  m[sumas[3]]='x';
  m[sumas[4]]='y';
  m[sumas[5]]='z';
  
  vector<int> palabra(10005,0);
  string ans="! ";

  forr(i,1,8){
    cout << "? " << s[i] << endl; 
    cout << flush;

    int enterNumber;
    string line;
    getline(cin, line);
    istringstream iss(line);
    while (iss >> enterNumber) {
      DBG(enterNumber);
      palabra[enterNumber] += sumas[i];
    }

    /*
    int act;
    while (cin >> act) {
      DBG(act);
      palabra[act] += sumas[i];
    }
    */

    /* 
    string act;
    getline(cin,act);

    int prev = 0;
    forn(j,act.size()) {
      if (act[j] == ' ') {
	int entero = stoi(act.substr(prev,j-prev));
	palabra[entero] += sumas[i];
	prev=j;
      }
    }
    if(act.size()!=0){
      int entero = stoi(act.substr(prev,act.size()-prev));
      palabra[entero] += sumas[i];
    }  
    */
  }

  int i=0;
  while((palabra[i]>0)&&(i<10001)){
    ans=ans+m[palabra[i++]];
  }
  cout << ans << endl;


  return 0;
}

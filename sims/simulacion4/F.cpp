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
typedef vector<ll> vi; typedef pair<int,int> ii;
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
  int n, q;
  cin >> n >> q;
  vector <vector<int>> m(n,vector<int>(n));
  vector <int> col(n), fil(n);
  int flow=0;
  forn(i,n){
    string s;
    cin >> s;
    forn(j,n) if(s[j]=='1'){
      col[j]++;
      fil[i]++;
      if(col[j]==n) flow++;
      if(fil[i]==n) flow++;
      m[i][j]=1;
    }
  }
  int c=0;
  cout << endl;
  forn(i,n){
    forn(j,n){
      int b=((j-c)%n+n)%n;
      int a=((i-(b+c)/n)%n+n)%n;
      cout << m[a][b] << " ";
    }
    cout << endl;
  }
  cout << endl;
  while(q--){
    int x;
    cin >> x;
    if(x==1){
      int a, b, k;
      cin >> a >> b >> k;
      a--; b--;
      int b2=((b-c)%n+n)%n;
      int a2=((a-(b2+c)/n)%n+n)%n;
      if(m[a2][b2]!=k){
        if(col[b2]==n) flow--;
        if(fil[a]==n) flow--;
        col[b2]+=1-2*m[a2][b2];
        fil[a]+=1-2*m[a2][b2];
        if(col[b2]==n) flow++;
        if(fil[a]==n) flow++;
      }
      cout << "HOLA " << a2 << " " << b2 << " " << k << " " << m[a2][b2] << endl;
      m[a2][b2]=k;
    }
    else{
      int k;
      cin >> k;
      int b=((n-1-c)%n+n)%n;
      int a=((n-1-(b+c)/n)%n+n)%n;
      if(m[a][b]!=k){
        if(col[b]==n) flow--;
        if(fil[n-1]==n) flow--;
        col[b]+=1-2*m[a][b];
        fil[n-1]+=1-2*m[a][b];
        if(col[b]==n) flow++;
        if(fil[n-1]==n) flow++;
      }
      m[a][b]=k;
      forn(i,n){
        int f=((i-(b+c)/n)%n+n)%n;
        if(m[f][b]!=m[(f-1+n)%n][b]){
          fil[i]+=1-2*m[f][b];
        }
      }
      c++;
    }
    cout << flow << "\n";
    cout << endl;
    forn(i,n){
      forn(j,n){
        int b=((j-c)%n+n)%n;
        int a=((i-(b+c)/n)%n+n)%n;
        cout << m[a][b] << " ";
      }
      cout << endl;
    }
    cout << endl;
    cout << "COLUMNAS: ";
    forn(i,n) cout << col[((i-c)%n+n)%n] << " ";
    cout << endl;
    cout << "FILAS: ";
    forn(i,n) cout << fil[i] << " ";
    cout << endl;
  }
  return 0;
}

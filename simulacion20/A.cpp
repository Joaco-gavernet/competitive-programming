#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define SZ(c) int((c).size())


int main() {
  int n, k;
  cin >> n >> k;
  n = 3*n;
  vector<string> v(n+1);  
  set <pair<pair<int, int>, string>> s;
  map<string, int> cont;
  map<string, int> id;
  for (int i=0; i<n+1; i++){
    getline(cin, v[i]);
    if (cont[v[i]] == 0){
      s.insert({{-1, -i}, v[i]});
      cont[v[i]] = 1;
      id[v[i]] = i;
    }
    else {
      s.erase({{-cont[v[i]], -id[v[i]]}, v[i]});
      cont[v[i]]++;
      id[v[i]] = i;
      s.insert({{-cont[v[i]], -id[v[i]]}, v[i]});
    }
  }
  int con=0;
  for (auto u : s){
    cout << u.second << "\n";
    con++;
    if(con==k) break;
  }
  FIN; 
  
  //~ string s;
  //~ getline(cin, s);
  
  
  return 0;
}

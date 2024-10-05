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


int main() {
  FIN;

  string s; getline(cin,s);
  string ss; getline(cin,ss);

  map<char,ll> ms, mss;
  for (char i : s) ms[i]++;
  for (char i : ss) mss[i]++;

  set<char> ans;
  for (char i : ss) if (ms[i] < mss[i]) ans.insert(i);
  for (char c: ans) cout << c;


  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(x) x.begin(),x.end()

int main() {
  FIN;
  string s; cin>>s;
  sort(all(s));
  if(s[0]==s[1] and s[3]==s[4] and ((s[2]==s[1] and s[2]!=s[3]) or (s[2]==s[3] and s[2]!=s[1]))) cout<<"YES\n";
  else cout<<"NO\n";

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define forr(i,a,b) for (int i = (a); i < b; i++)
#define forn(i,n) forr(i,0,n)
#define all(c) (c).begin(),(c).end()
#define fs first
#define ss second

const int INF = 1<<30;

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    string S = 'L' + s + 'L';
    const int N = n +2;
    vector<pair<bool,int>> dp(N,{false,INF});
    dp[0] = {true,0};

    forn(i,N) {
      if (dp[i].fs == false) continue;
      if (S[i] == 'L') {
	for (int step = m; step >= 1; step--) {
	  cerr << step << endl;
	  if (i +step >= N) continue;
	  if (S[i +step] == 'C') continue;
	  cerr << S[i] << ' ' << (i+step) << endl;
	  dp[i +step].fs = true;
	  dp[i +step].ss = min(dp[i].ss, dp[i +step].ss);
	  if (S[i +step] == 'L') break;
	}
      }	else if (S[i] == 'W') {
	dp[i+1].fs = true; 
	dp[i+1].ss = min(dp[i].ss +1, dp[i+1].ss);
      }
    }

    if (dp[N-1].fs == true and dp[N-1].ss <= k) cout << "YES\n";
    else cout << "NO\n";
  }


  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)

const int INF = 1<<30; 

int minDistance(string word1, string word2) {
  const int n = word1.size();
  const int m = word2.size(); 
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF)); 
  // dp[x][y] = "cost to make word1[0:x] be equal to word2[0:y]"

  auto cost = [&](int i, int j) -> int {
    return word1[i-1] != word2[j-1]; 
  }; 

  forn(i,n + 1) dp[i][0] = i;
  forn(j,m + 1) dp[0][j] = j; 

  forr(i,1,n + 1) {
    forr(j,1,m + 1) {
      dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cost(i, j)); 
      dp[i][j] = min(dp[i][j], dp[i-1][j] + 1); 
      dp[i][j] = min(dp[i][j], dp[i][j-1] + 1); 
    }
  }

  return dp[n][m]; 
}

int main(){
  string a, b; cin >> a >> b; 
  cout << minDistance(a, b) << '\n'; 
  return 0;
}




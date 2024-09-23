#include <bits/stdc++.h>
using namespace std;

freopen("output.txt", "w", stdout);

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) (v).begin(),(v).end()


void solve(int id) {
  ll n, k; cin >> n >> k;
  vi v(n); forr(i,0,n) cin >> v[i];
  sort(all(v));
  ll best = v[0];
  ll val = best;
  if (n > 2) val += 2*best*(n-2);
  if (val <= k) {
    cout << "Case #" << id << ": YES\n";
  } else {
    cout << "Case #" << id << ": NO\n";
  }
}


int main() {
  FIN;
  int t;
  cin >> t;
  forr(i,1,t+1) solve(i);
  return 0;
}


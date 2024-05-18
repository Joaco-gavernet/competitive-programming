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
const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 1e6+5;

struct item {
    ll op, l, r, c, id;
    bool operator < (const item &p) const {
	if(l != p.l) return l > p.l;
	else return op > p.op;
    }
};

int main(){  
    FIN;
    
    int n; ll S;
    cin >> n >> S;
    vector <ll> dp(n,0);
    priority_queue <item> p;
    forn(i,n) {
	ll l, r, c;
	cin >> l >> r >> c;
	p.push({1LL,l,r,c,i});
    }
    ll max_dp = 0;
    multiset <ll> ms; ms.insert(-INF);
    
    while(p.size()) {
	item cur = p.top(); p.pop();
	if(cur.op == 1) {
	    dp[cur.id] = max(dp[cur.id],*ms.rbegin() + cur.r * S - cur.c);
	    dp[cur.id] = max(dp[cur.id], max_dp + S * (cur.r-cur.l+1) - cur.c);
	    ms.insert(dp[cur.id] - cur.r * S);
	    p.push({2LL,cur.r,cur.r,dp[cur.id],cur.id});
	} else {
	    max_dp = max(max_dp, cur.c);
	    ms.erase(ms.find(dp[cur.id] - cur.r * S));
	}
    }
    cout << *max_element(all(dp)) << "\n";
    return 0;
}

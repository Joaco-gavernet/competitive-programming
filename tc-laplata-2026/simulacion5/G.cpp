#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i = a, jet = b; i < jet; i++)
#define SZ(x) int((x).size())
#define ALL(x) x.begin(), x.end()
#define mset(a,v) memset((a), (v), sizeof(a))
#define NCG ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vv;

int main() {
    NCG;

    int n = 6; 
    vv a(n); fore(i,0,n) cin >> a[i]; 

    ll tot = 0;
    ll h = min(a[0], a[2]), H = max(a[0], a[2]);
    fore(i,0,h) tot += 2 * a[1] + 1, a[1]++;
    
    h = min(a[3], a[5]), H = max(a[3], a[5]);
    fore(i,0,h) tot += 2 * a[4] + 1, a[4]++;

    tot += (H - h) * 2 * a[4]; 

    cout << tot << '\n'; 

    return 0;
}
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
    fore(i,0,a[1]) tot += (2 * a[0] + 1), a[0]++;
    fore(i,0,a[2]) tot += (2 * a[3] + 1), a[3]++;

    cout << tot << '\n'; 

    return 0;
}
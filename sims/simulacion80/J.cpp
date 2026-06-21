#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ss second
#define ff first
#define DBG(x) cerr << #x << " = " << x <<endl
#define RAYA cerr << "======================\n"

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k) {
    int n = SZ(sa);
    vector<int> f(max(255, n), 0), t(n);
    forr(i,0,n) f[RB(i+k)]++;
    int sum = 0;
    forr(i,0,max(255, n)) f[i] = (sum += f[i]) -f[i];
    forr(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
    sa = t;
}
vector<int> suffix_array(string& s) {
    s += '$';
    int n = SZ(s), rank;
    vector<int> sa(n), r(n), t(n);
    forr(i,0,n) sa[i] = i, r[i] = s[i];
    for (int k = 1; k < n; k *= 2) {
        csort(sa, r, k); csort(sa, r, 0);
        t[sa[0]] = rank = 0;
        forr(i,1,n) {
            if (r[sa[i]] != r[sa[i-1]] or RB(sa[i]+k) != RB(sa[i-1]+k)) rank++;
            t[sa[i]] = rank;
        }
        r = t;
        if (r[sa[n-1]] == n-1) break;
    }
    return sa;
}

vector<int> lcp_construction(string const& s, vector<int> const &p) {
    int n = SZ(s);
    vector<int> rank(n, 0);
    forn(i,n) rank[p[i]] = i;
    int k = 0;
    vector<int> lcp(n-1, 0);
    forn(i,n) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n and j + k < n and s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp; 
}

int main() {
    FIN;


    return 0;
}
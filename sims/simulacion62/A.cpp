#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n) 
#define SZ(x) int((x).size()) 
#define all(v) begin(v),end(v)
#define pb push_back
#define ff first
#define ss second 
#define DBG(x) cerr << #x << " = " << x << endl 
#define RAYA cerr << "========================\n" 

#define RB(x) (x<n?r[x]:0)

void csort(vi &sa, vi &r, int k) {
  int n = sa.size(); 
  vi f(max(255,n), 0), t(n); 
  forr(i,0,n) f[RB(i+k)]++;
  int sum = 0;
  forr(i,0,max(255, n)) f[i] = (sum += f[i]) -f[i];
  forr(i,0,n) t[f[RB(sa[i]+k)]++] = sa[i];
  sa = t;
}

vi suffix_array(string &s) {
  s += '$';
  int n = s.size(), rank;
  vi sa(n), r(n), t(n); 
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

vi lcp_construction(string const &s, vi const &p) {
  int n = s.size(); 
  vi rank(n, 0); 
  forn(i,n) rank[p[i]] = i;
  int k = 0; 
  vi lcp(n-1, 0); 
  forn(i,n) {
    if (rank[i] == n-1) {
      k = 0;
      continue; 
    }
    int j = p[rank[i] +1]; 
    while (i + k < n and j + k < n and s[i+k] == s[j+k]) k++; 
    lcp[rank[i]] = k;
    if (k) k--; 
  }
  return lcp; 
}

ll count_substring(string &pal) {
  ll n = SZ(pal);
  vi sa = suffix_array(pal);
  vi lcp = lcp_construction(pal, sa);
  ll ans = n * (n+1) /2; 
  for (int u: lcp) ans -= (ll)u; 
  return ans; 
}



int main() {
  FIN; 
  int n; cin >> n;
  string s="";
  vi p;
  forn(i,n){
    string a;
    cin >> a;
    s+=a;
    p.pb(SZ(s));
    s+="%";
  }
  vi u(SZ(s));
  int aux=0;
  forn(i,SZ(s)){
    while(p[aux]<i) aux++;
    u[i]=p[aux];
  }
  vi suf=suffix_array(s), lcp=lcp_construction(s,suf);
  ll ans=0;
  /*ll l=0;
  while(l!=SZ(s)){
    ll r=l, com=u[suf[l]]-suf[l];
    while(r<SZ(lcp) and lcp[r]>0){
      com=min(com,lcp[r]);
      r++;
    }
    DBG(l); DBG(com);
    ans+=com;
    l=r+1;
  }*/
 forr(i,1,SZ(suf)){
  ll tot;
  if(i<SZ(lcp)) tot=max(0LL,u[suf[i]]-suf[i]-lcp[i]);
  else tot=max(0LL,u[suf[i]]-suf[i]);
  ans+=tot;
 }
  cout << ans << "\n";
  return 0; 
} 

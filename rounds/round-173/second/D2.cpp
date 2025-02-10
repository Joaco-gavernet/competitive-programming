#include<bits/stdc++.h>

using namespace std;


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define RAYA cerr << "===============================" << endl


long long gcd(long long x, long long y)
{
  if(x == 0) return y;
  else return gcd(y % x, x);
}

void solve()
{
  long long l, r, g;
  scanf("%lld %lld %lld", &l, &r, &g);
  long long L = l + (l % g == 0 ? 0 : g - (l % g));
  long long R = r - r % g;
  for(int i = 0; i <= (R - L) / g; i++)
    for(int j = 0; j <= i; j++) {
      dbg(L + j * g, R - (i - j) * g); 
      if(gcd(L + j * g, R - (i - j) * g) == g)
      {
        printf("%lld %lld\n", L + j * g, R - (i - j) * g);
        RAYA; 
        return;
      }   
    }
  puts("-1 -1");
  RAYA; 
}

int main()
{                             
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++) solve();
}

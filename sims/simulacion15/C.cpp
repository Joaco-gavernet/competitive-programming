/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define DBG(x)
#define RAYA
#define dbg(...)
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
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

ll mod(ll x) {x%=MOD; if(x<0) x+=MOD; return x;}
ll add(ll a, ll b){return mod(a+b);}
ll sub(ll a, ll b){return mod(a-b);}
ll mul(ll a, ll b){return mod(mod(a)*mod(b));}
ll be(ll a, ll p) {
	ll ans=1; for(; p; p/=2, a = mul(a,a)) if(p&1) ans=mul(ans,a);
	return ans;
}
ll divi(ll a, ll b){return mul(a,be(b,MOD-2));}

int gauss(vector<vi> &a, vi &ans) {
    int n = SZ(a), m = SZ(a[0])-1;

    vector<int> where(m, -1);
    for(int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        forr(i, row, n){ // if(abs(a[i][col]) > abs(a[sel][col]))
            if(a[i][col] > a[sel][col]) sel = int(i); 
        }
        if(a[sel][col] == 0) continue; // if(abs(a[sel][col]) < EPS)
        forr(i, col, m+1) swap(a[sel][i], a[row][i]);
        where[col] = row;

        forn(i, n){
            if(i != row) { 
                ll c = divi(a[i][col], a[row][col]); // double c = a[i][col] / a[row][col];
                forr(j, col, m+1) a[i][j] = sub(a[i][j], mul(a[row][j], c));
            }
        }
        ++row;
    }

    ans.assign(m, 0);
    forn(i, m) if(where[i] != -1) ans[i] = divi(a[where[i]][m], a[where[i]][i]);
    forn(i, n){
        ll sum = 0; // double sum = 0;
        forn(j, m) sum = add(sum, mul(ans[j], a[i][j]));
        if(sum - a[i][m] != 0) return 0; // if(abs(sum-a[i][m]) > EPS)
        // No hay soluciones
    }
    forn(i, m) if(where[i] == -1) return INF; // Infinitas soluciones
    return 1; // Exactamente una solucion
}

vector<vi> find_bases(vector<vi> &A, vi &ans) {
	int n = SZ(A), m = SZ(ans);
	vi var_ind;
	forn(i,SZ(ans)) if(ans[i] == 0) var_ind.pb(i);
	
	vector <vi> bases(SZ(var_ind),vi(m,0));
	int r = 0;
	for(auto u : var_ind) {
		bases[r][u] = 1;
		forn(i,n) {
			forn(j,m) {
				if(A[i][j] != 0) {
					bases[r][j] = divi(-A[i][u], A[i][j]);
					break;
				}
			}
		}
		r++;
	}
	return bases;
} 

int main(){  
  FIN;
  int n,k; cin>>n>>k;
  vector<ll> ans(n);
  vector<vector<ll>> a(n,vector<ll>(n,0));
  forn(i,n){
    forn(j,k){
      a[i][(i+n-j)%n]=1;
    }
    ll aux; cin>>aux;
    a[i].pb(aux);
  }
  
  //for (auto i: a) dbg(i);
  
  //int sol;
  gauss(a,ans);
  //DBG(sol);
  
  vector<vi> b=find_bases(a,ans);
  
  //for (auto i: b) dbg(i);
  
  if(SZ(b)>0){
    cout<<"S"<<"\n";
  }else{
    cout<<"N"<<"\n";
  }
  
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using vi = vector<ll>; 
using vb = vector<bool>;
using ii = pair<ll,ll>;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v),end(v)
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "========================\n"
ll n, m;
vector <vi> v(100,vi(100));
queue <ii> q;
vi dx={0,0,-1,-1}, dy={0,-1,0,-1};
bool check(){
    while(SZ(q)>0){
        auto [x,y] = q.front(); q.pop();
        ll c=0;
        ii p;
        forn(i,2) forn(j,2){
            c+=v[x+i][y+j];
            if(v[x+i][y+j]==0) p={x+i,y+j};
        }
        if(abs(c)==4) {cout << "NO\n"; return true;}
        if(abs(c)<3) continue;
        v[p.ff][p.ss]=-c/3;
        forn(i,4){
            ll _x=p.ff+dx[i],_y=p.ss+dy[i];
            if(_x>=0 and _y>=0 and _x+1<n and _y+1<m) q.push({_x,_y});
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    string z="WB";
    forn(i,n){
        string s; cin >> s;
        forn(j,m){
            if(s[j]=='?') v[i][j]=0;
            else if(s[j]==z[(i+j)%2]) v[i][j]=1;
            else v[i][j]=-1;
        }
    }
    forn(i,n-1) forn(j,m-1) q.push({i,j});
    if(check()) return;
    forn(i,n) forn(j,m) if(v[i][j]==0){
        if(i==0 and j%2==0) v[i][j]=1;
        else if(i==0 and j%2==1) v[i][j]=-1;
        else v[i][j]=-v[i-1][j];
        forn(k,4){
            ll _x=i+dx[k],_y=j+dy[k];
            if(_x>=0 and _y>=0 and _x+1<n and _y+1<m) q.push({_x,_y});
        }
        if(check()) return;
    }
    cout << "YES\n";
    forn(i,n){
        forn(j,m){
            if(v[i][j]==1) cout << z[(i+j)%2];
            else cout << z[(i+j+1)%2];
        }
        cout << "\n";
    }
}

int main() {
    FIN;
    int t; cin >> t;
    cout << t << '\n';
    while (t--) solve(); 
    return 0; 
}
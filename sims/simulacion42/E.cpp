#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
typedef vector<ll> vi; 
typedef vector<bool> vb; 
typedef pair<int,int> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i<(ll)b; i++) 
#define forn(i,n) forr(i,0,n) 
#define all(v) (v).begin(), (v).end() 
#define pb push_back
#define SZ(x) int((x).size()) 
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) forn(_,n) cerr << v[_] << ' '
#define RAYA cerr << "==============================\n"
#define fs first 
#define ss second 

const ll INF = (1LL<<60); 

struct tup {
  ll x, y; 
  int id; 
}; 

void pushear(ii a, ii b, queue<tup> &ans) {
  int x1 = a.fs, y1 = a.ss, x2 = b.fs, y2 = b.ss; 
  ans.push({x2, y1, 0}); 
  ans.push({x2 +y2 -y1, y1, 0}); 
  ans.push({x2 -y2 +y1, y1, 0}); 
  ans.push({x1, x2 +y2 -x1, 0}); 
  ans.push({x1, y2 -x2 +x1, 0}); 
  if ((x2 +y2 +x1 -y1) %2 == 0) ans.push({(x2 +y2 +x1 -y1)/2, (x2 +y2 +y1 -x1)/2,0}); 
}

bool check_puntos(tup p, ii q) {
  int x1 = p.x, y1 = p.y, x2 = q.fs, y2 = q.ss; 
  if (y1 == y2) return true;
  if (x1 == x2) return true;  
  if (x1 +y1 == x2 +y2) return true;  
  if (x1 -y1 == x2 -y2) return true; 
  return false; 
}

tup check(ii &a, ii &b) {
  tup ans = {-1, -1, -1}; 
  int x1 = a.fs, y1 = a.ss, x2 = b.fs, y2 = b.ss; 
  if (y1 == y2) ans = {x1, y1, 1};
  if (x1 == x2) ans = {x1, y1, 2};  
  if (x1 +y1 == x2 +y2) ans = {x1, y1, 3};  
  if (x1 -y1 == x2 -y2) ans = {x1, y1, 4}; 
  return ans; 
}

bool check2(tup u, ii q) { // u es una recta 
  if (u.id == 1 and u.y == q.ss) return true; 
  else if (u.id == 2 and u.x == q.fs) return true; 
  else if (u.id == 3 and u.x +u.y == q.fs +q.ss) return true; 
  else if (u.id == 4 and u.x -u.y == q.fs -q.ss) return true; 
  else return false; 
}

void dbgq(queue<tup> q) {
  DBG(SZ(q)); 
  while (SZ(q)) {
    cerr << "(" << q.front().x << ',' << q.front().y << ") ";
    q.pop(); 
  }
  cerr << endl; 
}

void solve() {
  int n; cin >> n; 
  vector<ii> q(n); 
  forn(i,n) cin >> q[i].fs >> q[i].ss; 
  
  queue<tup> act; 
  tup recta = {-1, -1, -1}; 
  if (n >= 2) {
    pushear(q[0], q[1], act); 
    pushear(q[1], q[0], act); 
    recta = check(q[0], q[1]); 
  }
  //~ dbgq(act); 
  bool ok = true; 
  if (recta.id != -1) forr(i,2,n) {
    if (!check2(recta, q[i])) {
      pushear(q[i], q[0], act); 
      pushear(q[0], q[i], act); 
      ok = false; 
      break; 
    }
  }
  
  if ((ok and recta.id != -1) or n == 1) {
    cout << "Yes\n";
    cout << q[0].fs << " " << q[0].ss << '\n';
    //~ RAYA; 
    return; 
  }
  forn(i,n) {
    queue<tup> aux; 
    while (SZ(act)) {
      auto a = act.front(); act.pop(); 
      if (check_puntos(a, q[i])) aux.push(a); 
    }
    act = aux; 
  }
  if (SZ(act) > 0) {
    cout << "Yes\n";
    auto [x, y, t] = act.front(); 
    cout << x << ' ' << y << '\n';
  } else cout << "No\n"; 
  //~ RAYA; 
}

int main() {
  FIN; 
  int t; cin >> t; 
  while (t--) solve(); 
  return 0; 
} 

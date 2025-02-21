#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define SZ(x) int((x).size())
#define RAYA cerr << "===========================\n"
#define DBG(x) cerr << #x << " = " << x << endl
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << '\n'

int get_num(int i, string &s) {
  int x = 0;
  for (; s[i] != ']' and s[i] != ','; i++) {
    x *= 10;
    x += s[i] -'0';
  }
  return x;
}

bool iguales(int l, int r, string s) {
  l++;
  int x = get_num(l, s); 
  vi v = {x}; 
  l += SZ(to_string(x)); 
  while (s[l] != ')') {
    if (s[l] == ',') l++;
    else {
      x = get_num(l, s); 
      v.pb(x); 
      l += SZ(to_string(x)); 
    }
  }
  if (SZ(v) == 1) return true; 
  while (l <= r and v[l -1] == v[l]) l++; 
  return (l != r); 
}

vii get_par(string a) {
  stack<int> st;
  vii ans;
  forn(i,SZ(a)) {
    if (i > 0 and a[i-1] == 't') continue; 

    if (a[i] == '(') {
      st.push(i);
    } else if (a[i] == ')') {
      if (SZ(st) == 1) {
        if (a[st.top()-1] == 'd') ans.pb({st.top(), i}); 
        else if (!iguales(st.top(), i, a)) ans.pb({st.top(), i});
      }
      if (SZ(st)) st.pop();
    }
  }
  return ans;
}

void ordenar(vi &s, int l, int r) {
  // cerr << l << ' ' << r << '\n';
  sort(s.begin() +l, s.begin() +r +1);
}

int main() {
  FIN;

  string a, b; cin >> a >> b;

  vi va, vb;
  set<ii> fina, finb;

  // step 1: build vector of numbers
  forn(i, SZ(a)) {
    if (48 <= a[i] and a[i] <= 57) {
      int x = get_num(i, a);
      i += SZ(to_string(x)) -1;
      fina.insert({i,SZ(va)});
      va.pb(x);
    }
  }
  forn(i, SZ(b)) {
    if (48 <= b[i] and b[i] <= 57) {
      int x = get_num(i, b);
      i += SZ(to_string(x)) -1;
      finb.insert({i,SZ(vb)});
      vb.pb(x);
    }
  }
  if (SZ(va) != SZ(vb)) { cout << "not equal\n"; return 0; }

  // step 2: map closing parentheses
  vii ma = get_par(a);
  vii mb = get_par(b);
  sort(all(ma)), sort(all(mb)); 
  // for (auto [k, v]: ma) cerr << k << ' ' << v << '\n'; 
  // for (auto [k, v]: mb) cerr << k << ' ' << v << '\n'; 

  // step 3: determine sorted() and shuffle() intervals
  vii shua, shub; 
  for (auto [l, r]: ma) {
    // cerr << "ma " << l << ' ' << r << '\n'; 
    int vl = (*fina.lower_bound({l, 0})).second; 
    auto pvr = fina.lower_bound({r, 0}); 
    int vr = -1; 
    if (pvr == fina.end()) vr = SZ(va) -1; 
    else {
      pvr--; 
      vr = (*pvr).second; 
    }
    ordenar(va, vl, vr); 
    if (a[l-1] == 'e') shua.pb({vl, vr}); 
  }
  // RAYA; 
  for (auto [l, r]: mb) {
    int vl = (*finb.lower_bound({l, 0})).second; 
    auto pvr = finb.lower_bound({r, 0}); 
    int vr = -1; 
    if (pvr == finb.end()) vr = SZ(vb) -1; 
    else {
      pvr--; 
      vr = (*pvr).second; 
    }    
    ordenar(vb, vl, vr); 
    if (b[l-1] == 'e') shub.pb({vl, vr}); 
  }

  // check shua == shub
  if (SZ(shua) != SZ(shub)) { cout << "not equal\n"; return 0; }
  forn(i,SZ(shua)) {
    if (shua[i] != shub[i]) { cout << "not equal\n"; return 0; }
  }
  
  // check identity va == vb final
  forn(i,SZ(va)) if (va[i] != vb[i]) { cout << "not equal\n"; return 0; }
  cout << "equal\n";

  
  return 0;
}

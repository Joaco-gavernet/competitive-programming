#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<ll> vi;
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
#define DBGV(v) cerr << #v << " = "; forn(_,SZ(v)) cerr << v[_] << ' '; cerr << '\n'


int get_num(int i, string &s) {
  int x = 0;
  for (; s[i] != ']' and s[i] != ','; i++) {
    x *= 10;
    x += s[i] -'0';
  }
  return x;
}

bool iguales(int l, int r, vi &v) {
  if (l == r) return true; 
  l++; 
  for (; l <= r and v[l -1] == v[l]; l++) {}
  return (l > r); 
}

void ordenar(vi &va, int l, int r) {
  vi aux; 
  forr(i,l,r+1) aux.pb(va[i]);
  sort(all(aux));
  forn(i, r -l +1) va[l +i] = aux[i]; 
}

void get_vector_and_par(string a, vi &va, set<ii> &fina, vii &ans) {
  stack<int> st;
  int check = -1; 
  forn(i, SZ(a)) {
    if (48 <= a[i] and a[i] <= 57) {
      int x = get_num(i, a);
      i += SZ(to_string(x)) -1;
      fina.insert({i,SZ(va)});
      va.pb(x);
    } else if (a[i] == '(') {
      st.push(i);
      if (a[i-1] != 't' and check == -1) check = SZ(st);
    } else if (a[i] == ')') {
      if (SZ(st) == check) {
        check = -1; 
        int vl = (*fina.lower_bound({st.top(), 0})).second; 
        int vr = (*(--fina.lower_bound({i, 0}))).second;
        if (!iguales(vl, vr, va)) {
          ordenar(va, vl, vr);
          if (a[st.top()-1] == 'e') ans.pb({vl, vr});
        }
      }
      st.pop();
    }
  }
}

bool valid_intervals(vi &va, vi &vb, ii &interval) {
  unordered_map<int,int> mp; 
  forr(i, interval.first, interval.second +1) mp[va[i]]++;
  forr(i, interval.first, interval.second +1) mp[vb[i]]--;
  for (auto [k, v]: mp) if (v != 0) return false;
  return true; 
}

int main() {
  FIN;

  string a, b; cin >> a >> b;

  // Declarations 
  set<ii> fina, finb;
  vi va, vb; 
  vii shua, shub; 

  // step 1: build vector of numbers and map closing parentheses
  get_vector_and_par(a, va, fina, shua);
  get_vector_and_par(b, vb, finb, shub);
  if (SZ(va) != SZ(vb)) goto fin; 

  // check shua == shub
  if (SZ(shua) != SZ(shub)) goto fin;
  forn(i,SZ(shua))
    if (shua[i] != shub[i] or !valid_intervals(va, vb, shua[i]))
      goto fin; 

  // check identity va == vb final
  forn(i,SZ(va)) if (va[i] != vb[i]) goto fin; 
  cout << "equal\n";
  return 0; 

  fin: cout << "not equal\n";
  return 0;
}
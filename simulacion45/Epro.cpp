#include <bits/stdc++.h> 
using namespace std; 

typedef vector<int> vi; 
typedef pair<int,int> ii; 
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl

void read_any(vi &va, vector<ii> &ra, char *&cursor); 

void read_concat(vi &va, vector<ii> &ra, char *&cursor) {
  char c;
  while ((c = *cursor++)) {
    if (c == '(') break;
  }
  read_any(va, ra, cursor);
  read_any(va, ra, cursor); 
}

void read_list_until_par(vi &va, char *&cursor) {
  int par = 0;
  int num = 0;
  while (true) {
    char c = *cursor++; 
    if (c == '(') par++; 
    else if (c == ')') {
      par--; 
      if (par == 0) break; 
    }
    if (isdigit(c)) {
      num *= 10;
      num += c-'0'; 
    } else {
      if (num != 0) va.pb(num); 
      num = 0;
    }
  }
}

void read_list(vi &va, char *&cursor) {
  int num = 0;
  while (true) {
    char c = *cursor; 
    if (c == ']') { cursor++; break; }
    if (c == ',') { cursor++, num = 0; continue; } 
    if (c == '[') { cursor++; continue; } 
    while (isdigit(*cursor)) {
      num *= 10;
      num += *cursor++ -'0';
    }
    va.pb(num);
    num = 0; 
  }
}

void read_any(vi &va, vector<ii> &ra, char *&cursor) {
  while (true) {
    char c = *cursor++; 
    if (c == 0 or c == ',' or c == ')') break;
    else if (c == 'c') read_concat(va, ra, cursor); 
    else if (c == 's') {
      int type = *cursor;
      vi aux; 
      read_list_until_par(aux, cursor); 
      sort(all(aux)); 
      if (type == 'h' and aux[0] != aux.back()) 
        ra.pb({SZ(va), SZ(aux)}); 
      for (auto &x: aux) va.pb(x); 
    } else if (c == '[') read_list(va, cursor);
    else exit(1); 
  }
}

int main() {
  // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

  vi va, vb;
  vector<ii> ra, rb; 

  string a, b; cin >> a >> b;
  
  char *ca = &a[0]; 
  read_any(va, ra, ca);
  char *cb = &b[0]; 
  read_any(vb, rb, cb);

  if (va == vb && ra == rb) cout << "equal\n";
  else cout << "not equal\n";

  return 0; 
}
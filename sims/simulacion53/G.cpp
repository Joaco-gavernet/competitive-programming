#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==========================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '

unordered_map<char,int> steps;
vector<char> rgb={'R','G','B'};

void move(char &c, ll step){
  int i=0;
  if(c=='G') i=1; else if(c=='B') i=2;
  i+=step;
  i%=3;
  c=rgb[i];
  return;
}

ll fix() {

}

int main() {
  FIN;
  steps['R']=0;
  steps['G']=2;
  steps['B']=1;

  int l, b; cin >> l >> b; 
  string s; cin >> s; 
  vector<vi> but(b), mybut(l); 
  vi clicks(b, -1); 
  forn(i,b) {
    int k; cin >> k;
    but[i] = vi(k); 
    while (k--) {
      int a; cin >> a; 
      but[i][k] = --a; 
      mybut[a].pb(i); 
    }
  }

  vb visto(l,false);

  //Chequeo grado 0
  queue<ll> q;
  forn(i,l){
    if(SZ(mybut[i])==0 and s[i]!='R'){
      cout<<"impossible\n";
      return 0;
    }
    if(SZ(mybut[i])==0) visto[i]=true;
    if(SZ(mybut[i])==1) q.push(i);
  }

  //Grado 1
  while(SZ(q)){
    ll act=q.front(); q.pop();
    if(clicks[mybut[act][0]] != -1){
      move(s[act],clicks[mybut[act][0]]);
      if(s[act]!='R'){
        cout<<"impossible\n";
        return 0;
      }
    } else clicks[mybut[act][0]] = steps[s[act]], s[act] = 'R';

    mybut[act].pop_back();
    visto[act]=true;
    for(auto u: but[mybut[act][0]]) if(!visto[u] and SZ(mybut[u]) == 2) {
      if(mybut[u].back() != mybut[act][0]) reverse(all(mybut[u]));
      mybut[u].pop_back();
      move(s[u],clicks[mybut[act][0]]);
      q.push(u);
    }
  }

  RAYA;
  forn(i,l) if(!visto[i]) DBG(i);

  ll ans=0;
  forn(i,b) if(clicks[i]!=-1) ans+=clicks[i];

  unordered_map<char, vector<ii>> cases; 
  cases['R'] = {{0, 0}, {2, 1}, {1, 2}};
  cases['G'] = {{2, 0}, {0, 2}, {1, 1}};
  cases['B'] = {{0, 1}, {1, 0}, {2, 2}};
  forn(i,l) if(!visto[i]) {
    for (auto p: cases[s[i]]) {
      unordered_map<int,bool> aux;
      
      queue<int> q; q.push(); 
      ll ret = fix(visto, clicks, s, mybut, but, q);
    }
  }


  return 0;
}

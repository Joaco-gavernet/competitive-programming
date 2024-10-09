#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"


const int MAXN = -1;
const int INF = -1;
const int MOD = -1;

struct carta{
  int pos; char rank,suit;
  bool operator <(carta c) const{
    return pos<c.pos;
  }
  bool const operator *(carta c) const{
    if (rank==c.rank) return true;
    return false;
  }
  bool const operator -(carta c) const{
    if (suit==c.suit) return true;
    return false;
  }
};

typedef tree<ll,null_type,less<ll>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int update(vector<carta> &cards, indexed_set &pila, int tam){
  if(tam>3){
    //primero chequeamos el ultimo
    if(cards[*(pila.rbegin())] * cards[*(pila.find_by_order(tam-4))]){
      forn(x,4) pila.erase(pila.rbegin());
      tam-=4;
    }else if(tam>4 and (cards[*(pila.find_by_order(tam-2))] * cards[*(pila.find_by_order(tam-5))])){
      forn(x,4) pila.erase(pila.find_by_order(tam-1));
      tam-=4;
      tam=update(cards,pila,tam);
    }else if(cards[*(pila.rbegin())] - cards[*(pila.find_by_order(tam-4))]){
      pila.erase(pila.find_by_order(tam-4));
      pila.erase(pila.rbegin());
      tam-=2;
      tam=update(cards,pila,tam);
    }else if(tam>4 and cards[*(pila.find_by_order(tam-2))] - cards[*(pila.find_by_order(tam-5))]){
      pila.erase(pila.find_by_order(tam-5));
      pila.erase(pila.find_by_order(tam-3));
      tam-=2;
      tam=update(cards,pila,tam);
    }
  }
  return tam;
}

int main() {
  FIN; 
  vector<carta> cards(53);
  forr(i,1,53){
    char p,n; cin>>n>>p;
    cards[i].rank=n;
    cards[i].suit=p;
    cards[i].pos=i;
  }
  indexed_set pila;
  int tam=0;
  forr(i,1,53){
    pila.insert(i);
    tam++;
    if(tam>3){
      if(cards[*(pila.rbegin())] * cards[*(pila.find_by_order(tam-4))]){
	forn(x,4) pila.erase(pila.rbegin());
	tam-=4;
      }else if(cards[*(pila.rbegin())] - cards[*(pila.find_by_order(tam-4))]){
	pila.erase(pila.find_by_order(tam-4));
	pila.erase(pila.rbegin());
	tam-=2;
	tam=update(cards,pila,tam);
      }
    }
    //~ cout<<tam<<"\n";
    //~ if(tam>0){
      //~ for(auto u:pila) cout<<cards[u].rank<<cards[u].suit<<" ";
    //~ }
    //~ cout<<"\n";
  }
  cout<<tam<<"\n";
  if(tam>0){
    for(auto u:pila) cout<<cards[u].rank<<cards[u].suit<<" ";
  }
  cout<<"\n";
  return 0;
}

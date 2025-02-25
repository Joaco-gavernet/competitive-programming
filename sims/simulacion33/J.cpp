#include <bits/stdc++.h> 
using namespace std;

typedef long long ll; 
typedef vector<ll> vi; 
typedef pair<ll,ll> ii; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define all(v) (v).begin(), (v).end()
#define esta(v,x) (v).find(x) != (v).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "======================================\n"
#define DBGV(v,n) forn(i,n) cerr << v[i] << ' '

vector<ii> sc;
map<ii,int> pos;
vector<bool> fuera(100,false);
//~ int cont=0;
int xt,yt;

void update(int x,int y,int dif,int scu){
  if(x==xt and y==yt and scu!=0){
      fuera[scu]=true;
      //~ cout<<"SALE SCOOTER "<<scu<<"\n";
      sc[scu-1]={xt,yt};
      return;
  }
  int z=pos[{x,y}];
  if(z){
    if(dif==0){
      update(x,y+1,0,z);
      //~ pos[{x,y+1}]=z;
      sc[z-1]={x,y+1};
    }else if(dif==1){
      update(x+1,y,1,z);
      //~ pos[{x+1,y}]=z;
      sc[z-1]={x+1,y};
    }else if(dif==2){
      update(x,y-1,2,z);
      //~ pos[{x,y-1}]=z;
      sc[z-1]={x,y-1};
    }else{
      update(x-1,y,3,z);
      //~ pos[{x-1,y}]=z;
      sc[z-1]={x-1,y};
    }
    pos[{x,y}]=0;
  }
  if(scu!=0) pos[{x,y}]=scu;
  return;
}

int main() {
  FIN; 
  int n; cin>>n;
  int x0,y0; cin>>x0>>y0>>xt>>yt;
  forn(i,n){
    ii aux;
    cin>>aux.first>>aux.second;
    sc.pb(aux);
    pos[aux]=i+1;
  }
  //~ RAYA;
  //Llevo a mi robot al tacho
  while(x0>xt){
    cout<<"left\n";
    update(x0-1,y0,3,0);
    x0--;
  }
  while(x0<xt){
    cout<<"right\n";
    update(x0+1,y0,1,0);
    x0++;
  }
  while(y0>yt){
    cout<<"down\n";
    update(x0,y0-1,2,0);
    y0--;
  }
  while(y0<yt){
    cout<<"up\n";
    update(x0,y0+1,0,0);
    y0++;
  }
  //~ RAYA;
  //Voy a buscar a mi proximo scooter
  int cont=1;
  while(fuera[cont]) cont++;
  while(cont<=n){	//Para todos los scooters que vaya a buscar
    int xs,ys; 
    xs=sc[cont-1].first; ys=sc[cont-1].second;
    
    //Acá, voy a normalizar uno de los cosos a x
    //~ DBG(xs); DBG(ys);
    if(x0!=xs and y0!=ys){
      if(x0<xs){
	while(x0<xs+1){
	  cout<<"right\n"; update(x0+1,y0,1,0);
	  x0++;
	}
      }else{
	while(x0>xs-1){
	  cout<<"left\n"; update(x0-1,y0,3,0);
	  x0--;
	}
      }
      while(y0<ys){
	cout<<"up\n"; update(x0,y0+1,0,0);
	y0++;
      }
      while(y0>ys){
	cout<<"down\n"; update(x0,y0-1,2,0);
	y0--;
      }
      //Los muevo
      if(x0<xt){
	while(x0<xt-1){
	  cout<<"right\n"; update(x0+1,y0,1,0);
	  x0++;
	}
      }else{
	while(x0>xt+1){
	  cout<<"left\n"; update(x0-1,y0,3,0);
	  x0--;
	}
      }
      //Bajo
      while(y0<yt){
	cout<<"up\n"; update(x0,y0+1,0,0);
	y0++;
      }
      while(y0>yt){
	cout<<"down\n"; update(x0,y0-1,2,0);
	y0--;
      }
      //Me pongo en partida
      if(x0<xt){
	cout<<"right\n"; update(x0+1,y0,1,0);
	x0++;
      }else{
	cout<<"left\n"; update(x0-1,y0,3,0);
	x0--;
      }
      xs=x0;
    }
    //~ DBG(cont); DBG(xs); DBG(ys); DBG(x0); DBG(y0);
    if(x0==xs){
      cout<<"right\n"; update(x0+1,y0,1,0);
      if(y0>ys){
	while(y0>ys-1){
	  cout<<"down\n"; update(x0+1,y0-1,2,0);
	  y0--;
	}
      }else{
	while(y0<ys+1){
	  cout<<"up\n"; update(x0+1,y0+1,0,0);
	  y0++;
	}
      }
      cout<<"left\n"; update(x0,y0,3,0);
      if(y0<ys){
	while(y0<yt){
	  cout<<"up\n"; update(x0,y0+1,0,0);
	  y0++;
	}
      }else{
	while(y0>yt){
	  cout<<"down\n"; update(x0,y0-1,2,0);
	  y0--;
	}
      }
    }else if(y0==ys){
      cout<<"up\n"; update(x0,y0+1,0,0);
      if(x0>xs){
	while(x0>xs-1){
	  cout<<"left\n"; update(x0-1,y0+1,3,0);
	  x0--;
	}
      }else{
	while(x0<xs+1){
	  cout<<"right\n"; update(x0+1,y0+1,1,0);
	  x0++;
	}
      }
      cout<<"down\n"; update(x0,y0,2,0);
      if(x0<xs){
	while(x0<xt){
	  cout<<"right\n"; update(x0+1,y0,1,0);
	  x0++;
	}
      }else{
	while(x0>xt){
	  cout<<"left\n"; update(x0-1,y0,3,0);
	  x0--;
	}
      }
    }
    //~ prev=cont;
    while(fuera[cont]) cont++;
    //~ if(prev==cont){DBG(cont); cout<<" SE TRABO ACA\n"; break;}
  }
  return 0;
}

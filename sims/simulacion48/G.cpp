#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi; 
typedef vector<bool> vb;
typedef pair<ll,ll> ii; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define SZ(x) int((x).size())
#define all(v) begin(v), end(v)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=============================\n"
#define DBGV(v,n) cerr << #v << " = "; forn(_,n) cerr << v[_] << ' '; cerr << endl



void s35tipo1(vector<vector <char>> &ans, int x, int y){
	ans[x][y]='U'; ans[x][y+1]='U'; ans[x][y+2]='X'; ans[x][y+3]='U'; ans[x][y+4]='U';
	ans[x+1][y]='U'; ans[x+1][y+1]='X'; ans[x+1][y+2]='X'; ans[x+1][y+3]='X'; ans[x+1][y+4]='U';
	ans[x+2][y]='U'; ans[x+2][y+1]='U'; ans[x+2][y+2]='X'; ans[x+2][y+3]='U'; ans[x+2][y+4]='U';
}

void s35tipo2(vector<vector <char>> &ans, int x, int y){
	ans[x][y]='V'; ans[x][y+1]='Z'; ans[x][y+2]='V'; ans[x][y+3]='V'; ans[x][y+4]='V';
	ans[x+1][y]='V'; ans[x+1][y+1]='Z'; ans[x+1][y+2]='Z'; ans[x+1][y+3]='Z'; ans[x+1][y+4]='V';
	ans[x+2][y]='V'; ans[x+2][y+1]='V'; ans[x+2][y+2]='V'; ans[x+2][y+3]='Z'; ans[x+2][y+4]='V';
}

string s2por10up="LLLLYYYYPP";
string s2por10down="LIIIIIYPPP";
void s2p10(vector<vector <char>> &ans, int x, int y){
	forn(i,10) ans[x][y+i]=s2por10up[i];
	forn(i,10) ans[x+1][y+i]=s2por10down[i];
}

string s2por15up="LLLLNNNYYYYNNPP";
string s2por15down="LIIIIINNYNNNPPP";
void s2p15(vector<vector <char>> &ans, int x, int y){
	forn(i,15) ans[x][y+i]=s2por15up[i];
	forn(i,15) ans[x+1][y+i]=s2por15down[i];
}


int main() {
	FIN; 
int n, m; cin >> n >> m;
bool s=false;
if(n%5==0) {swap(n,m); s=true;}
if(m%5!=0 or (n==1 and m>5) or (n==2 and m==5)){
	cout << "no\n";
	return 0;
}
cout << "yes\n";
vector<vector <char>> ans(n,vector<char>(m)); 
int x=0;
if(n==1){
	if(!s) cout << "IIIII\n";
	else cout << "I\nI\nI\nI\nI\n";
	return 0;
}
if(n%3==1){
	forn(i,m){
		if((i/5)%2==0) ans[0][i]='I';
		else ans[3][i]='I';
	}
	forn(i,m/5){
		if(i%2==0) s35tipo2(ans,1,i*5);
		else s35tipo1(ans,0,i*5);
	}
	x=4;
}
else if(n%3==2){
	if(m==5){
		forn(i,5) {ans[0][i]='I'; ans[4][i]='I';}
		s35tipo1(ans,1,0);
		x=5;
	}
	else{
		int y=0;
		if(m%10==5) {s2p15(ans,0,0); y+=15;}
		while(y<m) {s2p10(ans,0,y); y+=10;}
		x=2;
	}
}
while(x<n){
	forn(i,m/5){
		if((x+i)%2==0) s35tipo1(ans,x,i*5);
		else s35tipo2(ans,x,i*5);
	}
	x+=3;
}
if(!s){
	forn(i,n){
		forn(j,m) cout << ans[i][j];
		cout << "\n";
	}
}
else{
	forn(i,m){
		forn(j,n) cout << ans[j][i];
		cout << "\n";
	}
}
	return 0; 
} 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<bool> vb; 
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define SZ(x) int((x).size())
#define ff first
#define ss second
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "=========================\n"
#define all(v) begin(v),end(v)


int main() {
  FIN;
  string s11,s12,s21,s22; cin>>s11>>s12>>s21>>s22;
  ll dia1=-1,dia2=-1;
  ll minutos1,minutos2;
  if(s11=="Mon") dia1=0; 
  if(s21=="Mon") dia2=0;
  if(s11=="Tue") dia1=1; 
  if(s21=="Tue") dia2=1;
  if(s11=="Wed") dia1=2; 
  if(s21=="Wed") dia2=2;
  if(s11=="Thu") dia1=3; 
  if(s21=="Thu") dia2=3;
  if(s11=="Fri") dia1=4; 
  if(s21=="Fri") dia2=4;
  if(s11=="Sat") dia1=5; 
  if(s21=="Sat") dia2=5;
  if(s11=="Sun") dia1=6; 
  if(s21=="Sun") dia2=6;

  ll h1,h2,m1,m2;
  h1=((s12[0]-'0')*10)+(s12[1]-'0');
  h2=((s22[0]-'0')*10)+(s22[1]-'0');
  m1=((s12[3]-'0')*10)+(s12[4]-'0');
  m2=((s22[3]-'0')*10)+(s22[4]-'0');

  // DBG(dia2);
  minutos1=dia1*60*24;
  minutos2=dia2*60*24;
  // DBG(minutos2); DBG(minutos1);

  minutos1+=(h1*60)+(m1); minutos2+=(h2*60)+(m2);
  // DBG(minutos2); DBG(minutos1);
  if(minutos2<=minutos1) minutos2+=(60*24*7);

  ll len=minutos2-minutos1;
  // DBG(len);

  ll dias=len/(60*24);
  len-=(dias*60*24);
  ll horas=len/(60);
  len-=(horas*60);
  ll mins=len;

  bool coma=false;
  if(dias and horas and mins) coma=true;

  if(dias){
    cout<<dias<<" day";
    if(dias>1) cout<<"s";
  }

  if(coma) cout<<", ";
  else if(dias and horas) cout<<" and ";
  else if(dias and mins) cout<<" and "; 

  if(horas){
    cout<<horas<<" hour";
    if(horas>1) cout<<"s";
  }

  if(coma) cout<<", ";
  else if(mins and horas) cout<<" and ";

  if(mins){
    cout<<mins<<" minute";
    if(mins>1) cout<<"s";
  }

  cout<<"\n";

  return 0;
}
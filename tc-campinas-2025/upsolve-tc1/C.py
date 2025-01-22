import math
from typing import List
from sys import stdin, stdout

g: list[list[int]] = [[] for _ in range(105)]
llegan = [0] *105
dp = [0] *105

def calc(val, n):
    global llegan
    llegan = [0] *105
    hijos = 0
    for nod in range(1, n+1): 
        if nod == 1: 
            llegan[nod] += val
        hijos = len(g[nod]) 
        if nod == 2: 
            print(nod, hijos) 
        if hijos > 0: 
            mod_hijos = llegan[nod] % hijos
            if nod == 2: 
                print(mod_hijos) 
            for i in range(mod_hijos): 
                llegan[g[nod][i]] += 1
            for i in range(hijos): 
                llegan[g[nod][i]] += (llegan[nod] // hijos) 
    print(llegan) 

def main(): 
    input = stdin.read
    data = input().split()
    idx = 0

    n = int(data[idx])
    idx += 1
    g = [[] for _ in range(n +1)]

    for i in range(n):
        x = int(data[idx])
        idx += 1
        for j in range(x): 
            aux = int(data[idx])
            idx += 1
            g[i +1].append(aux)

    dp = [0] * (n +1)
    llegan = [0] * (n +1)

    dp[0] = 1
    for i in range(1, n +1): 
        if len(g[i]) == 0: 
            dp[i] = dp[i -1]
            continue
        calc(dp[i -1], n)
        dp[i] = dp[i -1] * (len(g[i]) // math.gcd(len(g[i]), llegan[i])) 
    print(dp) 
    print(dp[n]) 

if __name__ == "__main__":
    main() 


'''
vector<vector<ll>> g(105);
vector<__int128> llegan(105,0);
vector<__int128> dp(105,0);

void calc(__int128 val,ll n){
	forn(lol,105) llegan[lol]=0;
	ll hijos;
	forr(nod,1,n+1){
		if(nod==1) llegan[nod]+=val;
		hijos=SZ(g[nod]);
		if(hijos>0){
			forn(i,llegan[nod]%hijos) llegan[g[nod][i]]++;
			forn(i,hijos) llegan[g[nod][i]]+=(llegan[nod]/hijos);
		}
	}
	return;
}

int main() {
	FIN;
	ll n; cin>>n;
	forn(i,n){
		ll x; cin>>x;
		forn(j,x){
			ll aux; cin>>aux;
			g[i+1].pb((__int128)aux);
		}
	}
	dp[0]=1;
	forr(i,1,n+1){
		if(SZ(g[i])==0) {dp[i]=dp[i-1]; continue;}
		calc(dp[i-1],n);
		dp[i]=dp[i-1]*(SZ(g[i])/gcd(SZ(g[i]),llegan[i]));
	}
	cout<< toString(dp[n]) <<"\n";
	return 0;
}
'''

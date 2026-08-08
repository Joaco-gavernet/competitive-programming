#include <bits/stdc++.h>
using namespace std;
#define all(v) begin(v), end(v)

struct RandomAll {
  mt19937 rng;
  RandomAll(int seed) { rng.seed(seed); }
  int nextInt(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(rng); 
  } 
}; 


int main(int argc, char** argv) {
  int seed = argc > 1 ? atoi(argv[1]) : chrono::steady_clock::now().time_since_epoch().count(); 
  RandomAll rand(seed); 

  int n = 20; 
  string s(n, '#'); 
  for (int i = 0; i < n; i++) s[i] = 'a' + rand.nextInt(0,25); 
  cout << s << '\n'; 
} 

#include <bits/stdc++.h>

using namespace std;
int main(){
  string pal;
  cin >> pal;
  int len = (int)pal.length();
  
  for (int i = 0; i < len; i++) { 
    if (pal[i] != 'A' and 
	pal[i] != 'a' and 
	pal[i] != 'O' and 
	pal[i] != 'o' and
	pal[i] != 'Y' and 
	pal[i] != 'y' and 
	pal[i] != 'E' and 
	pal[i] != 'e' and 
	pal[i] != 'U' and 
	pal[i] != 'u' and 
	pal[i] != 'I' and 
	pal[i] != 'i') {
	  cout << '.';
	  if (pal[i] >= 'a'){
	     cout << pal[i]; 
	  } else {
	    cout << (char)(pal[i] + 'a' - 'A'); 
	  } 
    } 
  }
}

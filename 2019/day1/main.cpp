#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  int total = 0;
  int n;
  while(cin >> n){
    while(n > 0){
      total += max(0, (n/3) - 2);
      n = (n/3) - 2;
    }
  }
  cout << total << endl;
  return 0;
}

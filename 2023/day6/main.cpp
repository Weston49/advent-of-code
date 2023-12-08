#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int main(){
  string s;
  long tmp, count, dist, total;
  long i, j;
  string times;
  string dists;
  
  getline(cin, s);
  s = s.substr(9);
  stringstream ss(s);
  while(ss >> tmp){
    times += to_string(tmp);
  }

  getline(cin, s);
  s = s.substr(9);
  stringstream ss2(s);
  while(ss2 >> tmp){
    dists += to_string(tmp);
  }

  cout << times << endl;
  cout << dists << endl;
  count = 0;
  total = 1;
  for(j = 0; j < stol(times); j++){
    dist = j * (stol(times) - j);
    // cout << dist << endl;
    if(dist > stol(dists)) count++;
  }

  cout << count << endl;

  return 0;
}

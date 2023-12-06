#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
  
  string s, tmp, color;
  int i, k, j;
  int maxR, maxB, maxG;
  maxR = 0;
  maxB = 0; 
  maxG = 0;
  int total = 0;
  j = 0;
  while(getline(cin, s)){
    s = s.substr(s.find(':')+2);
    stringstream ss(s);
    j++;

    while(getline(ss, tmp, ';')){
      for(i = 0; i < tmp.size(); i++){
        if(tmp[i] == ',') tmp[i] = ' ';
      }
      stringstream sin(tmp);
      while(sin >> k >> color){
        //cout << k << endl;
        //cout << color << endl;
        switch (color[0]) {
          case 'r':
            if(k > maxR) maxR = k;
            break;
          case 'g':
            if(k > maxG) maxG = k;
            break;
          case 'b':
            if(k > maxB) maxB = k;
            break;
          default:
            cout << "oops" << endl;
            break;
        }
      }
    }
    total += (maxR * maxG * maxB);
    maxR = 0;
    maxG = 0;
    maxB = 0;
    cout << endl;
  }
  cout << total << endl;

  return 0;
}

#include <vector>
#include <iostream>

using namespace std;

int main(){
  string s;
  vector <string> loop;
  size_t i, j;
  while(cin >> s){
    loop.push_back(s);
  }
  bool inside;
  bool pipe = false;
  int counter = 0;
  for(i = 0; i < loop.size(); i++){
    inside = false;
    for(j = 0; j < loop[i].size(); j++){
      if(loop[i][j] != '.') {
        pipe = true;
        inside = false;
      }
      if(pipe && loop[i][j] == '.'){
        inside = !inside;
      }
      if(loop[i][j] == '.' && !pipe){
        inside = !inside;
      }
      if(loop[i][j] == '.' && inside){
        counter++;
      }
    }
  }

  cout << counter << endl;

  return 0;
}

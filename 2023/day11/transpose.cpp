#include <iostream>
#include <vector>

using namespace std;

int main(){
  string s;
  vector <string> v;

  while(cin >> s){
    v.push_back(s);
  }

  for(size_t i = 0; i < v[0].size(); i++){
    for(size_t j = 0; j < v.size(); j++){
      cout << v[j][i];
    }
    cout << endl;
  }
}

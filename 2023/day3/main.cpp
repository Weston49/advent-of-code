#include <iostream>
#include <vector>

using namespace std;

bool isSymbol(char c){ //checks if is gear
  if(c == '*') return true;
  return false;
}

int main(){
  string s;
  string val;
  char tmpC;
  vector <string> sc;
  int i, j, k;
  bool part = false;
  int total = 0;
  vector <vector <int> > stars;
  vector <int> starPos;
  int cols;
  int x;

  while(cin >> s){
    sc.push_back(s);
  }
  stars.resize(sc.size() * sc[0].size());
  cols = sc[0].size();

  for(i = 0; i < sc.size(); i++){
    for(j = 0; j < sc[i].size(); j++){
      val.clear();
      starPos.clear();
      if(sc[i][j] >= '0' && sc[i][j] <= '9'){
        while(sc[i][j] >= '0' && sc[i][j] <= '9'){
          val.push_back(sc[i][j]);
          tmpC = sc[i][j];
          if(i > 0 && isSymbol(sc[i-1][j])) {
            part = true;
            x = (i-1) * cols + (j);
            if(find(starPos.begin(), starPos.end(), x) != starPos.end()){
              //duplicate star
            }else{
              starPos.push_back(x);
            }
          }
          if(i > 0 && j > 0 && isSymbol(sc[i-1][j-1])) {
            part = true;
            x = (i-1) * cols + (j-1);
            if(find(starPos.begin(), starPos.end(), x) != starPos.end()){
              //duplicate star
            }else{
              starPos.push_back(x);
            }
          }
          if(i < sc.size()-1 && isSymbol(sc[i+1][j])) {
            part = true;
            x = (i+1) * cols + (j);
            if(find(starPos.begin(), starPos.end(), x) != starPos.end()){
              //duplicate star
            }else{
              starPos.push_back(x);
            }
          }
          if(i < sc.size()-1 && j < sc[i].size()-1 && isSymbol(sc[i+1][j+1])){
            part = true;
            x = (i+1) * cols + (j+1);
            if(find(starPos.begin(), starPos.end(), x) != starPos.end()){
              //duplicate star
            }else{
              starPos.push_back(x);
            }
          }
          if(j < sc[i].size()-1 && isSymbol(sc[i][j+1])){
            part = true;
            x = (i) * cols + (j+1);
            if(find(starPos.begin(), starPos.end(), x) != starPos.end()){
              //duplicate star
            }else{
              starPos.push_back(x);
            }
          }
          if(i < sc.size()-1 && j > 0 && isSymbol(sc[i+1][j-1])) {
            part = true;
            x = (i+1) * cols + (j-1);
            if(find(starPos.begin(), starPos.end(), x) != starPos.end()){
              //duplicate star
            }else{
              starPos.push_back(x);
            }
          }
          if(i > 0 && j < sc[i].size()-1 && isSymbol(sc[i-1][j+1])) {
            part = true;
            x = (i-1) * cols + (j+1);
            if(find(starPos.begin(), starPos.end(), x) != starPos.end()){
              //duplicate star
            }else{
              starPos.push_back(x);
            }
          }
          if(j > 0 && isSymbol(sc[i][j-1])) {
            part = true;
            x = (i) * cols + (j-1);
            if(find(starPos.begin(), starPos.end(), x) != starPos.end()){
              //duplicate star
            }else{
              starPos.push_back(x);
            }
          }
          j++;
        }
        if(part){
          for(k = 0; k < starPos.size(); k++){
            stars[starPos[k]].push_back(stoi(val));
            cout << val << endl;
          }
          //cout << val << endl;
          //total += stoi(val);
        }
        part = false;
      }
    }
  }
  for(i = 0; i < stars.size(); i++){
    if(stars[i].size() == 2){
      total += stars[i][0] * stars[i][1];
    }
  }
  cout << total << endl;
  return 0;
}

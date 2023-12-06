#include <iostream>
#include <vector>
#include <cstdio>
#include <sstream>

using namespace std;

int main(){
  string s;
  long long tmp, x, y, z, tmp2;
  size_t i, j;
  vector<long long> seeds;
  unsigned long long m = -1;
  vector<vector <long long> > maps;
  long long t;
  vector<long long> tmpV;
  int mapCounter = 0;
  getline(cin, s);
  s = s.substr(7);
  stringstream ss(s);
  while(ss >> tmp){
    ss >> tmp2;
    for(i = 0; i < tmp2+1; i++){
      seeds.push_back(tmp+i);
    }
    //cout << tmp << endl;
  }
  cout << seeds.size() << endl;
  getline(cin, s);
  while(getline(cin, s)){
    if(s == ""){
      // cout << "just a newline" << endl;
      for(i = 0; i < seeds.size(); i++){
        //cout << "seeds: " << seeds[i] << " ";
      }
      //cout << endl;
      continue;
    }
    if(!(s[0] >= '0' && s[0] <= '9')){
      // cout << "move to next map here" << endl;
      for(i = 0; i < seeds.size(); i++){
        for(j = 0; j < maps.size(); j++){
          if(seeds[i] >= maps[j][1] && seeds[i] < (maps[j][1]+maps[j][2])){
            t = maps[j][0] + (seeds[i] - maps[j][1]);
            seeds[i] = t;
            //printf("Processed seed %15zu / %15zu  :  Current map: %d\n", i, seeds.size(), mapCounter);
            break;
          }
        }
      }
      for(i = 0; i < maps.size(); i++){
        for(j = 0; j < maps[i].size(); j++){
          //cout << maps[i][j] << " ";
        }
        //cout << endl;
      }
      // cout << endl;
      mapCounter++;
      printf("New map number: %d\n", mapCounter);
      maps.clear();
    }else{
      stringstream ss(s);
      while(ss >> x >> y >> z){
        tmpV.push_back(x);
        tmpV.push_back(y);
        tmpV.push_back(z);
        maps.push_back(tmpV);
        tmpV.clear();
      }
    }
  }
  for(i = 0; i < seeds.size(); i++){
    for(j = 0; j < maps.size(); j++){
      if(seeds[i] >= maps[j][1] && seeds[i] < (maps[j][1]+maps[j][2])){
        t = maps[j][0] + (seeds[i] - maps[j][1]);
        seeds[i] = t;
        // printf("Processed seed %15zu / %15zu\n", i, seeds.size());
        break;
      }
    }
  }
  for(i = 0; i < maps.size(); i++){
    for(j = 0; j < maps[i].size(); j++){
      //cout << maps[i][j] << " ";
    }
    //cout << endl;
  }
  //cout << endl;
  maps.clear();

  for(i = 0; i < seeds.size(); i++){
    if(seeds[i] < m) m = seeds[i];
  }
  cout << m << endl;
  return 0;
}

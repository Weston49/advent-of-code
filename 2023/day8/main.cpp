#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

int main(){
  string dirs;
  string a,b,c,d;
  unordered_map<string, pair<string, string> > m;
  unordered_map<string, pair<string, string> >::iterator mit;
  vector<string> currs;
  vector<string> starts;
  vector<bool> founds;
  vector<int>counts;
  int i, k;
  unsigned long long counter;
  bool finished;

  cin >> dirs;
   
  while(cin >> a >> b >> c >> d){
    if(a[2] == 'A') currs.push_back(a);
    m.insert(make_pair(a, make_pair(c.substr(1,3), d.substr(0,3))));
  }

  for(mit = m.begin(); mit != m.end(); mit++){
    //cout << mit->first << " " << mit->second.first << " " << mit->second.first << endl;
  }
  for(i = 0; i < (int)currs.size(); i++){
    founds.push_back(false);
    counts.push_back(0);
  }

  i = 0;
  counter = 0;
  long long total = 1;
  while(true){
    for(k = 0; k < (int)currs.size(); k++){
      if(currs[k][2] == 'Z'){
        founds[k] = true;
        counts[k] = counter;
      }
    }
    finished = true;
    for(k = 0; k < (int)founds.size(); k++){
      if(!founds[k]) finished = false;
    }
    if(finished){
      //cout << counter << endl;
      for(k = 0; k < (int)counts.size(); k++){
        cout << counts[k] << endl;
        total *= counts[k];
      }
      //cout << total << endl;
      return 0;
    }
    for(k = 0; k < (int)currs.size(); k++){
      if(dirs[i] == 'L'){
        currs[k] = m.find(currs[k])->second.first;
      }else{
        currs[k] = m.find(currs[k])->second.second;
      }
    }
    counter++;
    i++;
    //cout << currs[0] << endl;
    //cout << counter << endl;
    if(i == (int)dirs.size()) i = 0;
  }

  //cout << counter << endl;


  return 0;
}

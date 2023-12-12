#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
  string s;
  vector< pair <pair<int,int>, pair<int, int> > > stars;
  int i = 0;
  int j = 0;
  long long total = 0;
  int x = 0;
  int y = 0;
  int dist = 0;

  while(cin >> s){
    for(j = 0; j < (int)s.size(); j++){
      if(s[j] == '|') x++;
      if(s[j] == '-'){
        y++;
        break;
      }
      if(s[j] == '#') stars.push_back(make_pair(make_pair(i,j), make_pair(x,y)));
    }
    x = 0;
    i++;
  }

  for(i = 0; i < (int)stars.size(); i++){
    cout << stars[i].first.first << " " << stars[i].first.second << endl;
    cout << stars[i].second.first << " " << stars[i].second.second << endl;
  }


  for(i = 0; i < (int)stars.size()-1; i++){
    for(j = i+1; j < (int)stars.size(); j++){
      dist = abs(stars[i].first.first - stars[j].first.first);
      dist += abs(stars[i].first.second - stars[j].first.second);
      dist += (abs(stars[i].second.first - stars[j].second.first) * 1000000) - (abs(stars[i].second.first - stars[j].second.first));
      dist += (abs(stars[i].second.second - stars[j].second.second) * 1000000) - (abs(stars[i].second.second - stars[j].second.second));
      total += dist;
    }
  }  
  
  cout << total << endl;

  return 0;
}

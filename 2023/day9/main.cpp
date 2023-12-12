#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

int get_pred(vector<int> vals){
  reverse(vals.begin(), vals.end());
  size_t i, j;
  int pred;
  bool allZeros = false;
  vector<vector <int> > diffs;

  diffs.resize(vals.size()+1);
  pred = 0;

  for(i = 0; i < vals.size(); i++){
    diffs[0].push_back(vals[i]);
  }

  j = 1;

  while(!allZeros){
    allZeros = true;
    for(i = 0; i < diffs[j-1].size()-1; i++){
      diffs[j].push_back(diffs[j-1][i+1] - diffs[j-1][i]);
      if(diffs[j-1][i+1] - diffs[j-1][i] != 0) allZeros = false;
    }
    j++;
  }

  diffs.resize(j);

  for(i = diffs.size()-1; i != 0; i--){
    diffs[i-1].push_back(diffs[i][diffs[i].size()-1]+diffs[i-1][diffs[i].size()-1]);
  }

  for(i = 0; i < diffs.size(); i++){
    for(j = 0; j < diffs[i].size(); j++){
      cout << diffs[i][j] << " ";
    }
    cout << endl;
  }

  pred = diffs[0][diffs[0].size()-1];

  cout << pred << endl;
  return pred;
}

int main(){
  string s;
  size_t i;
  int tmp;
  int total;
  vector<int> vals;

  total = 0;

  while(getline(cin, s)){
    stringstream ss(s);
    vals.clear();
    while(ss >> tmp){
      vals.push_back(tmp);
    }
    for(i = 0; i < vals.size(); i++){
      //cout << vals[i] << " ";
    }
    //cout << endl;
    total += get_pred(vals);
  }

  cout << total << endl;
  return 0;
}

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
  string s, wins, nums;
  vector<int> winV;
  vector<int> numV;
  vector<int> cards;
  int total, current, count, i, j;

  cards.resize(203, 1);
  j = 0;
  total = 0;

  while(getline(cin, s)){
    current = 0;
    count = 0;

    s = s.substr(s.find(':')+2);
    wins = s.substr(0, s.find('|'));
    nums = s.substr(s.find('|')+2);

    stringstream ss(wins);
    while(ss >> current) winV.push_back(current);
    stringstream ss2(nums);
    while(ss2 >> current) numV.push_back(current);

    
    for(i = 0; i < numV.size(); i++){
      if(find(winV.begin(), winV.end(), numV[i]) != winV.end()) {
        count++; 
        cards[j+count] += cards[j];
      }
    }

    winV.clear();
    numV.clear();

    total += cards[j];
    j++;
  }

  cout << total << endl;
  return 0;
}

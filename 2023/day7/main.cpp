#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int get_type(string s);

bool is_better(string s1, string s2){
  //returns if s1 is a better hand than s2
  if(get_type(s1) < get_type(s2)) return true;
  if(get_type(s1) > get_type(s2)) return false;
  size_t i;
  for(i = 0; i < s1.size(); i++){
    switch (s1[i]) {
      case 'A': 
        s1[i] = '9' + 5;
        break;
      case 'K':
        s1[i] = '9' + 4;
        break;
      case 'Q':
        s1[i] = '9' + 3;
        break;
      case 'J':
        s1[i] = '1';
        break;
      case 'T':
        s1[i] = '9' + 1;
        break;
      default:
        break;
    }
    switch (s2[i]) {
      case 'A': 
        s2[i] = '9' + 5;
        break;
      case 'K':
        s2[i] = '9' + 4;
        break;
      case 'Q':
        s2[i] = '9' + 3;
        break;
      case 'J':
        s2[i] = '1';
        break;
      case 'T':
        s2[i] = '9' + 1;
        break;
      default:
        break;
    }
  }
  return s1 > s2;
}

int get_type(string s){
  /*1 = 5 of a kind, 2 = 4 of a kind and so on*/
  size_t i;
  int j;
  int jCount;
  jCount = 0;
  vector<int> counts;
  bool hasThree = false;
  bool hasTwo = false;
  bool twoTwos = false;
  counts.resize(13, 0);
  for(i = 0; i < s.size(); i++){
    switch (s[i]) {
      case 'A': 
        counts[12]++;
        break;
      case 'K':
        counts[11]++;
        break;
      case 'Q':
        counts[10]++;
        break;
      case 'J':
        jCount++;
        break;
      case 'T':
        counts[8]++;
        break;
      default:
        counts[s[i]-'2']++;
        break;
    }
  }
  for(j = 4; j >= 0; j--){
  for(i = 0; i < counts.size(); i++){
    if(counts[i] == j){
      counts[i] += jCount;
      jCount = 0;
    } 
  }
  }
  for(i = 0; i < counts.size(); i++){
    if(counts[i] == 5) return 1;
    if(counts[i] == 4) return 2;
    if(counts[i] == 2 && hasTwo) twoTwos = true;
    if(counts[i] == 3) hasThree = true;
    if(counts[i] == 2) hasTwo = true;
  }
  if(hasThree && hasTwo) return 3;
  if(hasThree) return 4;
  if(twoTwos) return 5;
  if(hasTwo) return 6;
  return 7;
}

int main(){
  string s;
  size_t i, j;
  int b;
  long long total;
  vector<int> bets;
  vector<string> hands;
  long long tmpBet;
  string tmpHand;

  while(cin >> s >> b){
    hands.push_back(s);
    bets.push_back(b);
  }

  for(j = 0; j < hands.size(); j++){
  for(i = 0; i < hands.size()-1; i++){
    if(is_better(hands[i], hands[i+1])){
      tmpBet = bets[i];
      bets[i] = bets[i+1];
      bets[i+1] = tmpBet;
      tmpHand = hands[i];
      hands[i] = hands[i+1];
      hands[i+1] = tmpHand;
    }
  }
  }
  total = 0;
  int tmpType;
  for(i = 0; i < hands.size(); i++){
    printf("%s %3d %3zu", hands[i].c_str(), bets[i], i+1);
    cout << endl;
    tmpType = get_type(hands[i]);
    switch (tmpType) {
      case 1:
        cout << "Five of a kind" << endl;
        break;
      case 2:
        cout << "Four of a kind" << endl;
        break;
      case 3:
        cout << "Full house" << endl;
        break;
      case 4:
        cout << "Three of a kind" << endl;
        break;
      case 5:
        cout << "Two Pair" << endl;
        break;
      case 6:
        cout << "One Pair" << endl;
        break;
      case 7:
        cout << "High Card" << endl;
        break;
      default:
        
        break;
    }
    total += ((i+1)*bets[i]);
  }

  cout << total << endl;

  return 0;
}

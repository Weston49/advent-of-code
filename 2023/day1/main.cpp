#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  string s, tmp, k;
  int i, ans, tot, j;
  tot = 0;
  vector<string> nums;
  vector<int> tmpV;
  nums.push_back("one");
  nums.push_back("two");
  nums.push_back("three");
  nums.push_back("four");
  nums.push_back("five");
  nums.push_back("six");
  nums.push_back("seven");
  nums.push_back("eight");
  nums.push_back("nine");
  while(cin >> s){
    tmp.clear();
    tmpV.clear();
    for(i = 0; i < s.size(); i++){
      if(s[i] >= '0' && s[i] <= '9'){
        tmpV.push_back(s[i] - '0');
        cout << s[i] << endl;
      }else{
        for(j = 0; j < 9; j++){
          if(s.size()-i >= nums[j].size()){ //then check if a that num word is there
            tmp = s.substr(i, (nums[j].size()));
            if(tmp == nums[j]){
              tmpV.push_back(j+1);
            }
          }
        }
      }
    }
    k = to_string(tmpV[0]) + to_string(tmpV[tmpV.size()-1]);
    ans = stoi(k);
    tot += ans;
  }
  cout << tot << endl;
  return 0;
}

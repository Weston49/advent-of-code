#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

    string currentDay = "1";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    vector <int> nums;

    while(getline(fin, line, delim)){

        nums.push_back(stoi(line));

    }

    fin.close();
    int total = 0;
    for(int i = 3; i < nums.size(); i++){
        int x = nums[i] + nums[i-1] + nums[i-2];
        int y = nums[i-1] + nums[i-2] + nums[i-3];
        if(x > y){
            total++;
        }
    }

    cout << total << endl;

    return 0;
}
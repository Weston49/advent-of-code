#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int maxIndex(vector <vector <int> > cals){
    int maxVal = 0;
    int maxIndex = 0;
    int x = 0;
    for(int i = 0; i < cals.size(); i++){
        x = 0;
        for(int j = 0; j < cals[i].size(); j++){
            x += cals[i][j];
        }
        if(x > maxVal){
            maxVal = x;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int addVector(vector <int> arr){
    int t = 0;
    for(int i = 0; i < arr.size(); i++){
        t += arr[i];
    }
    return t;
}


int main(){

    string currentDay = "1";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables
    vector < vector <int> >  cals;
    vector <int> temp;
    while(getline(fin, line, delim)){
        if(line == ""){
            cals.push_back(temp);
            temp.clear();
        }else{
            temp.push_back(stoi(line));
        }

    }

    int total = 0;
    for(int i = 0; i < 3; i++){
        total += addVector(cals[maxIndex(cals)]);
        cals.erase(cals.begin() + maxIndex(cals));
    }

    cout << total << endl;
    return 0;
}


#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool checkUnique(vector <char> s, int i, int y){
    if(y == 0){
        return true;
    }
    int selector = i - y;
    for(int offset = 13; offset >= 0; offset--){
        if(selector != i-offset){
            if(s[i-offset] == s[selector]){
                return false;
            }
        }
    }
    
    return checkUnique(s, i, y-1);
}

int main(){

    string currentDay = "6";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables
    vector <char> s;

    while(getline(fin, line, delim)){
        for(int i = 0; i < line.length(); i++){
            s.push_back(line[i]);
        }
    }

    for(int i = 13; i < s.size(); i++){
        char c = s[i];
        if(checkUnique(s, i, 13)){
            cout << i+1 << endl;
            break;
        }
    }

    cout << endl << "Code Complete" << endl;

    return 0;
}


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

    int floor = 0;

    while(getline(fin, line, delim)){

        for(int i = 0; i < line.length(); i++){
            if(line[i] == '('){
                floor++;
            }else{
                floor--;
            }
            if(floor < 0){ // part two
                cout << i+1 << endl;
                return 0;
            }
        }

    }

    cout << floor << endl;

    return 0;
}
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

    string currentDay = "2";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    int h = 0;
    int d = 0;
    int a = 0;

    while(getline(fin, line, delim)){

        if(line[0] == 'f'){
            h += stoi(line.substr(7));
            d += a * stoi(line.substr(7));
        }else if(line[0] == 'u'){
            a -= stoi(line.substr(2));
        }else if(line[0] == 'd'){
            a += stoi(line.substr(4));
        }

    }

    cout << h * d * -1 << endl;

    return 0;
}
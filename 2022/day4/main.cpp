#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

    string currentDay = "4";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line, r;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables
    string r1, r2, r1min, r1max, r2min, r2max;
    int total = 0;
    while(getline(fin, line, delim)){
        r1 = line.substr(0, line.find(','));
        r2 = line.substr(line.find(',') + 1, line.length());
        
        r1min = r1.substr(0, r1.find('-'));
        r1max = r1.substr(r1.find('-') + 1, r1.length());

        r2min = r2.substr(0, r2.find('-'));
        r2max = r2.substr(r2.find('-') + 1, r2.length());

        if(stoi(r1min) >= stoi(r2min) && stoi(r1min) <= stoi(r2max)){
            total++;
        }else if(stoi(r2min) >= stoi(r1min) && stoi(r2min) <= stoi(r1max)){
            total++;
        }else if(stoi(r2max) <= stoi(r1max) && stoi(r2max) >= stoi(r1min)){
            total++;
        }
        else if(stoi(r1max) <= stoi(r2max) && stoi(r1max) >= stoi(r2min)){
            total++;
        }
               
    }
    cout << total << endl;

    return 0;
}
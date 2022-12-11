#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void check(int currentCycle, int currentPosition, int X) {
    if (X == currentPosition || X - 1 == currentPosition || X + 1 == currentPosition) {
        cout << "#";
      }
    else {
        cout << ".";
      }
}

int main() {

    string currentDay = "10";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables
    int X = 1;
    int currentCycle = 0;
    int currentPosition = 0;

    while (getline(fin, line, delim)) {
        if (line[0] == 'n') {
        currentCycle++;
        check(currentCycle, currentPosition, X);
        currentPosition++;
        if ((currentCycle) % 40 == 0) {
            cout << endl;
            currentPosition = 0;
        }
        }
        else {
        currentCycle ++;
        check(currentCycle, currentPosition, X);
        currentPosition++;
        if ((currentCycle) % 40 == 0) {
            cout << endl;
            currentPosition = 0;
        }
            currentCycle++;
            check(currentCycle, currentPosition, X);
            currentPosition++;
            if ((currentCycle) % 40 == 0) {
            cout << endl;
            currentPosition = 0;
            }
            X += stoi(line.substr(5));
        }
    }
}


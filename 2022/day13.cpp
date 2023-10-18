#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

    string currentDay = "13";
    char delim = '\n';
    int i,j,k;

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");



    while(getline(fin, line, delim)){
        


    }

    return 0;
}

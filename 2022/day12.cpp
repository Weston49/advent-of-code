#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

    string currentDay = "12";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    vector < vector <char> > map;
    vector <char> temp;
    while(getline(fin, line, delim)){
        temp.clear();
        for(int i = 0; i < line.length(); i++){
            temp.push_back(line[i]);
        }
        map.push_back(temp);
    }
    fin.close();

    int height = map.size();
    int width = map[0].size();

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}
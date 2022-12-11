#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

    string currentDay = "3";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    vector <string> lines;

    while(getline(fin, line, delim)){

        lines.push_back(line);

    }

    fin.close();

    int width = lines[0].length();
    int height = lines.size();

    vector <int> vals(width);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(lines[i][j] == '1'){
                vals[j]++;
            }
        }
    }
    string temp = "";
    string temp2 = "";
    for(int i = 0; i < width; i++){
        if(vals[i] > height/2){
            temp += "1";
            temp2 += "0";
        }else{
            temp += "0";
            temp2 += "1";
        }
    }

    int value = 0;
    int indexCounter = 0;
    for(int i=temp.length()-1;i>=0;i--){

        if(temp[i]=='1'){
            value += pow(2, indexCounter);
        }
        indexCounter++;
    }
    int value2 = 0;
    indexCounter = 0;
    for(int i=temp2.length()-1;i>=0;i--){

        if(temp2[i]=='1'){
            value2 += pow(2, indexCounter);
        }
        indexCounter++;
    }

    cout << value * value2 << endl;

    return 0;
}
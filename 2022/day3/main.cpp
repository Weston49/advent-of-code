#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

    string currentDay = "3";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables
    vector < vector < vector <int> > > sacks;

    vector <int> sack;
    vector < vector <int> > group;
    int asciiOffset = 0;
    int count = 0;
    while(getline(fin, line, delim)){
        sack.clear();
        for(int i = 0; i < line.length(); i++){
            if((int)line[i] > 91){
                //lowercase letter
                asciiOffset = 96;
            }else{
                asciiOffset = 38;
            }
            sack.push_back((int)line[i] - asciiOffset);
        }
        group.push_back(sack);
        count++;
        if(count == 3){
            sacks.push_back(group);
            group.clear();
            count = 0;
        }
    }

    int total = 0;
    int temp = 0;
    for(int i = 0; i < sacks.size(); i++){
        group = sacks[i];
        int maxSize = 0;
        int maxIndex = 0;
        for(int j = 0; j < 3; j++){
            if(group[j].size() > maxSize){
                maxSize = group[j].size();
                maxIndex = j;
            }
        }
        int otherIndex1 = 0;
        int otherIndex2 = 0;
        switch (maxIndex)   
        {
        case 0:
            otherIndex1 = 1;
            otherIndex2 = 2;
            break;
        case 1:
            otherIndex1 = 0;
            otherIndex2 = 2;
            break;
        case 2:
            otherIndex1 = 0;
            otherIndex2 = 1;
            break;
        default:
            break;
        }
        for(int j = 0; j < group[maxIndex].size(); j++){
            if(find(group[otherIndex1].begin(), group[otherIndex1].end(), group[maxIndex][j]) != group[otherIndex1].end() && find(group[otherIndex2].begin(), group[otherIndex2].end(), group[maxIndex][j]) != group[otherIndex2].end()){
                total += group[maxIndex][j];
                temp++;
                break;
            }
        }
    }

    cout << total << endl;
    cout << temp << endl;
    cout << sacks.size() << endl;
    return 0;
}
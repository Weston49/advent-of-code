#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main(){

    string currentDay = "5";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables
    vector <string> crateLines;
    vector <string> moves;
    while(getline(fin, line, delim)){
        //getting crates
        crateLines.push_back(line);
        if(line == ""){
            break;
        }
    }
    while(getline(fin, line, delim)){
        //getting moves
        moves.push_back(line);
    }
    fin.close();
    int last = crateLines.size()-2;
    int stacksAmount = (crateLines[last].length() / 4) + 1;
    crateLines.pop_back();
    crateLines.pop_back();
    vector < vector <char> > crates(stacksAmount);
    char temp;
    for(int i = crateLines.size()-1; i >= 0; i--){
        for(int j = 1; j < stacksAmount*4 -1; j+= 4){
            temp = crateLines[i][j];
            if(temp != ' '){
                crates[j/4].push_back(temp);
            }
        }
    }
    vector <string> moveVec;
    vector < vector <int> > commands;
    vector <int> y;
    for(int i = 0; i < moves.size(); i++){
        string move = moves[i].substr(5);
        stringstream t(move);
        string x = "";
        moveVec.clear();
        while(getline(t, x, ' ')){
            moveVec.push_back(x);
        }
        y.clear();
        y.push_back(stoi(moveVec[0]));
        y.push_back(stoi(moveVec[2]));
        y.push_back(stoi(moveVec[4]));
        commands.push_back(y);
    }

    for(int i = 0; i < commands.size(); i++){
        vector <int> command = commands[i];
        int depth = command[0] - 1;
        for(int j = 0; j < command[0]; j++){
            int top = crates[command[1]-1].size() - 1;
            crates[command[2]-1].push_back(crates[command[1]-1][top-depth]);
            depth--;
        }
        for(int j = 0; j < command[0]; j++){
            crates[command[1]-1].pop_back();
        }
    }

    for(int i = 0; i < crates.size(); i++){
        int top = crates[i].size() - 1;
        cout << crates[i][top];
    }
    cout << endl;

    return 0;
}
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
    vector < vector <int> > games;

    while(getline(fin, line, delim)){
        vector <int> game;
        if(line[0] == 'A'){
            game.push_back(1);
        } else if(line[0] == 'B'){
            game.push_back(2);
        } else if(line[0] == 'C'){
            game.push_back(3);
        }
        if(line[2] == 'X'){
            game.push_back(1);
        } else if(line[2] == 'Y'){
            game.push_back(2);
        } else if(line[2] == 'Z'){
            game.push_back(3);
        }
        games.push_back(game);
    }

    int total = 0;

    for(int i = 0; i < games.size(); i++){
        switch (games[i][1]){
        case 1:
            //lose 
            if(games[i][0] == 1){
                total += 3;
            }else{
                total += games[i][0] - 1;
            }
            break;
        case 2:
            //draw
            total += 3 + games[i][0];
            break;
        case 3:
            //win
            total += 6;
            if(games[i][0] == 3){
                total += 1;
            }else{
                total += games[i][0] + 1;
            }
            break;
        default:
            break;
        }
    }

    cout << total << endl;

    return 0;
}
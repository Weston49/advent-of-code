#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

vector < vector <int> > moveTails(vector < vector <int> > p){
    for(int i = 0; i < p.size()-1; i++){
        if((abs(p[i][1]-p[i+1][1]) > 1 && p[i][0] != p[i+1][0]) || (abs(p[i][0]-p[i+1][0]) > 1 && p[i][1] != p[i+1][1])){//diag move
            if(p[i][1] > p[i+1][1]){
                p[i+1][1]++;
            }else{
                p[i+1][1]--;
            }
            if(p[i][0] > p[i+1][0]){
                p[i+1][0]++;
            }else{
                p[i+1][0]--;
            }
        }else if(abs(p[i][0] - p[i+1][0]) > 1){ //horizontal move
            if(p[i][0] > p[i+1][0]){
                p[i+1][0]++;
            }else{
                p[i+1][0]--;
            }
        }else if(abs(p[i][1] - p[i+1][1]) > 1){ //vertical move
            if(p[i][1] > p[i+1][1]){
                p[i+1][1]++;
            }else{
                p[i+1][1]--;
            }
        }
    }
    return p;
}

int main(){

    string currentDay = "9";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    vector <char> directions;
    vector <int> amounts;

    while(getline(fin, line, delim)){
        directions.push_back(line[0]);
        amounts.push_back(stoi(line.substr(1)));
    }
    fin.close();
    
    vector < vector <int> > positions = {{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}}; // [0][0] is x pos of head [0][1] is y pos of head

    vector < vector <int> > locs;
    vector <int> temp;
    int moves = 0;
    int headMoves = 0;

    for(int i = 0; i < directions.size(); i++){
        for(int j = 0; j < amounts[i]; j++){
            headMoves++;
            switch(directions[i]){
                case 'R':
                    //go right
                    positions[0][0]++;
                    break;
                case 'L':
                    //go left
                    positions[0][0]--;
                    break;
                case 'D':
                    //go down
                    positions[0][1]--;
                    break;
                case 'U':
                    //go up
                    positions[0][1]++;
                    break;
            }

            positions = moveTails(positions);
            
            temp.clear();
            temp.push_back(positions[positions.size()-1][0]);
            temp.push_back(positions[positions.size()-1][1]);
            if(count(locs.begin(),locs.end(),temp)){
                //value already exists
            }else{
                locs.push_back(temp);
                cout << temp[0] << " " << temp[1] << endl;
            }
        }
    }

    cout << locs.size() << endl;

    return 0;
}
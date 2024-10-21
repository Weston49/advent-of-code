#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int move(int curMoves, vector < vector <int> > visited, int v, int h, vector < vector <int> > map){
    //check which ways are movable, exclude places that path has already been
    // v = verticle pos
    // h = horizontal pos
    //cout << v << " " << h << endl;
    
    int bigNum = map.size() * map[0].size() * 10;

    bool onLeftEdge = false;
    bool onRightEdge = false;
    bool onTopEdge = false;
    bool onBottomEdge = false;
    if(v == 0){
        onTopEdge = true;
    }
    if(h == 0){
        onLeftEdge = true;
    }
    if(v == map.size()-1){
        onBottomEdge = true;
    }
    if(h == map[0].size()-1){
        onRightEdge = true;
    }
    // cout << "T: " << onTopEdge << " B: " << onBottomEdge << " " << endl;
    // cout << "L: " << onLeftEdge << " R: " << onRightEdge << " " << endl;
    
    vector <int> pos = {v,h};
    vector <int> posToCheck;
    int rightPath = bigNum;
    int leftPath = bigNum;
    int downPath = bigNum;
    int upPath = bigNum;

    bool canMove = false;

    if(!onRightEdge){
        posToCheck = {v, h+1}; // checking right
        if(!(count(visited.begin(), visited.end(), posToCheck))){ //if it has not been visited
            if(map[v][h+1] - map[v][h] < 2){ //if the right tile is less than two higher
                if(map[v][h+1] == 27){ // thats the finish!
                    cout << "Found finish!" << endl;
                    cout << curMoves << endl;
                    return curMoves+1;
                }
                cout << curMoves << endl;
                canMove = true;
                visited.push_back(pos);
                rightPath = move(curMoves+1, visited, v, h+1, map);//recursive call for this path
            } 
        }
    }
    if(!onTopEdge){
        posToCheck = {v-1, h}; // checking up
        if(!(count(visited.begin(), visited.end(), posToCheck))){ //if it has not been visited
            if(map[v-1][h] - map[v][h] < 2){ //if the right tile is less than two higher
                if(map[v-1][h] == 27){ // thats the finish!
                    cout << "Found finish!" << endl;
                    cout << curMoves << endl;
                    return curMoves+1;
                }
                cout << curMoves << endl;
                canMove = true;
                visited.push_back(pos);
                upPath = move(curMoves+1, visited, v-1, h, map);//recursive call for this path
            }
        }
    }
    if(!onLeftEdge){
        posToCheck = {v, h-1}; //checking left
        if(!(count(visited.begin(), visited.end(), posToCheck))){ //if it has not been visited
            if(map[v][h-1] - map[v][h] < 2){ //if the right tile is less than two higher
                if(map[v][h-1] == 27){ // thats the finish!
                    cout << "Found finish!" << endl;
                    cout << curMoves << endl;
                    return curMoves+1;
                }
                cout << curMoves << endl;
                canMove = true;
                visited.push_back(pos);
                leftPath = move(curMoves+1, visited, v, h-1, map);//recursive call for this path
            }
        }
    }
    if(!onBottomEdge){
        posToCheck = {v+1, h};
        if(!(count(visited.begin(), visited.end(), posToCheck))){ //if it has not been visited
            if(map[v+1][h] - map[v][h] < 2){ //if the right tile is less than two higher
                if(map[v+1][h] == 27){ // thats the finish!
                    cout << "Found finish!" << endl;
                    cout << curMoves << endl;
                    return curMoves+1;
                }
                cout << curMoves << endl;
                canMove = true;
                visited.push_back(pos);
                downPath = move(curMoves+1, visited, v+1, h, map);//recursive call for this path
            }
        }
    }
    if(canMove){
        return min({rightPath,leftPath,upPath,downPath});
    }else{
        return bigNum;
    }
}


int charToHeight(char c){
    int i = 0;
    if(c == 'E'){
        i = 27;
    }else if(c == 'S'){
        i = 1;
    }else{
        i = (int)c - 96;
    }
    return i;
}


int main(){

    string currentDay = "12";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    vector < vector <int> > map;
    vector <int> temp;
    vector < vector <int> > startPos;
    int h = 0;
    int v = 0;
    int lineCounter = 0;
    while(getline(fin, line, delim)){
        temp.clear();
        for(int i = 0; i < line.length(); i++){
            temp.push_back(charToHeight(line[i]));
            if(line[i] == 'S'){
                h = lineCounter;
                startPos.push_back({h,i});
                v = i;
            }
        }
        lineCounter++;
        map.push_back(temp);
    }
    fin.close();

    int height = map.size();
    int width = map[0].size();

    int shortestPath = move(0, startPos, v, h, map);

    cout << shortestPath << endl;

    return 0;
}
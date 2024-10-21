#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool canMove(vector < vector <char> > ocean, int row, int col){
    if(ocean[row][col] == '>'){
        if(ocean[row].size() == col+1){
            return (ocean[row][0] == '.');
        }else{
            return (ocean[row][col+1] == '.');
        }
    }
    if(ocean[row][col] == 'v'){
        if(ocean.size() == row+1){
            return (ocean[0][col] == '.');
        }else{
            return (ocean[row+1][col] == '.');
        }
    }
    return false;
}

void printOcean(vector < vector <char> > ocean){
    for(int row = 0; row < ocean.size(); row++){
        for(int col = 0; col < ocean[row].size(); col++){
            cout << ocean[row][col];
        }
        cout << endl;
    }
}

int main(){

    string currentDay = "25";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    vector < vector <char> > ocean;
    vector < vector <char> > image;
    vector < vector <bool> > willMove;
    vector <char> temp;
    while(getline(fin, line, delim)){
        temp.clear();
        for(int i = 0; i < line.length(); i++){
            temp.push_back(line[i]);
        }
        ocean.push_back(temp);
    }
    fin.close();

    //int counter = 0;

    int height = ocean.size();
    int width = ocean[0].size();
    int counter = 0;

    //printOcean(ocean);
    //cout << endl << endl;

    vector <bool> temp2;

    while(image != ocean){
        counter++;
        image = ocean; //taking a picture of the ocean before it moves
        willMove.clear();
        /* populating the willMove matrix for the rightward movers */
        for(int row = 0; row < height; row++){ //for each row i
            temp2.clear();
            for(int col = 0; col < width; col++){ //each column j in the row i
                if(ocean[row][col] == '>' && canMove(ocean, row, col)){
                    temp2.push_back(true);
                }else{
                    temp2.push_back(false);
                }
            }
            willMove.push_back(temp2);
        }
        /* moving the rightward movers */
        for(int row = 0; row < height; row++){ //for each row
            for(int col = 0; col < width; col++){ //each column in the row
                if(willMove[row][col]){
                    ocean[row][col] = '.';
                    if(col == width-1){ //checking if we are on the last col
                        ocean[row][0] = '>';
                    }else{
                        ocean[row][col+1] = '>';
                    }
                }
            }
        }
        willMove.clear();
        /* asking the downward movers if they are going to move */
        for(int row = 0; row < height; row++){ //for each row i
            temp2.clear();
            for(int col = 0; col < width; col++){ //each column j in the row i
                if(ocean[row][col] == 'v' && canMove(ocean, row, col)){
                    temp2.push_back(true);
                }else{
                    temp2.push_back(false);
                }
            }
            willMove.push_back(temp2);
        }
        /* moving the downward movers */
        for(int row = 0; row < height; row++){ //for each row 
            for(int col = 0; col < width; col++){ //each column in the row
                if(willMove[row][col]){
                    ocean[row][col] = '.';
                    if(row == height-1){ //checking if we are on the last row
                        ocean[0][col] = 'v';
                    }else{
                        ocean[row+1][col] = 'v';
                    }
                }
            }
        }
        printOcean(ocean);
        cout << endl <<  "step number " << counter << endl << endl;
    }

    cout << "Final steps: " << counter << endl;

    return 0;
}
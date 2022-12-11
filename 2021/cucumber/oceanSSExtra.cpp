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
    if(ocean[row][col] == '<'){
        if(0 == col){
            return (ocean[row][ocean[row].size()-1] == '.');
        }else{
            return (ocean[row][col-1] == '.');
        }
    }
    if(ocean[row][col] == '^'){
        if(0 == row){
            return (ocean[ocean.size()-1][col] == '.');
        }else{
            return (ocean[row-1][col] == '.');
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

void newOcean(int w, int h){
    int width = w;
    int height = h;
    ofstream fout;
    fout.open("ocean.txt");
    
    char item = '.';
    srand(time(NULL));

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int n = rand() % 11;
            switch (n){
            case 0:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                item = '.';
                break;
            case 1:
                item = '^';
                break;
            case 2:
                item = '<';
                break;
            case 3:
                item = '>';
                break;
            case 4:
                item = 'v';
                break;
            default:
                break;
            }
            fout << item;
        }
        if(i+1 != height){
            fout << '\n';
        }
    }

    fout.close();
}

bool simulateOcean(int w, int h){
    //generates new ocean
    newOcean(w, h);

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("ocean.txt");
    vector < vector <char> > ocean;
    vector < vector <char> > image;
    vector < vector <bool> > willMove;
    vector <char> temp;
    while(getline(fin, line)){
        temp.clear();
        for(int i = 0; i < line.length(); i++){
            temp.push_back(line[i]);
        }
        ocean.push_back(temp);
    }
    fin.close();

    int height = ocean.size();
    int width = ocean[0].size();
    int counter = 0;

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
        willMove.clear();
        /* populating the willMove matrix for the leftward movers */
        for(int row = 0; row < height; row++){ //for each row i
            temp2.clear();
            for(int col = 0; col < width; col++){ //each column j in the row i
                if(ocean[row][col] == '<' && canMove(ocean, row, col)){
                    temp2.push_back(true);
                }else{
                    temp2.push_back(false);
                }
            }
            willMove.push_back(temp2);
        }
        /* moving the leftward movers */
        for(int row = 0; row < height; row++){ //for each row
            for(int col = 0; col < width; col++){ //each column in the row
                if(willMove[row][col]){
                    ocean[row][col] = '.';
                    if(col == 0){ //checking if we are on the first
                        ocean[row][width-1] = '<';
                    }else{
                        ocean[row][col-1] = '<';
                    }
                }
            }
        }
        willMove.clear();
        /* asking the upward movers if they are going to move */
        for(int row = 0; row < height; row++){ //for each row i
            temp2.clear();
            for(int col = 0; col < width; col++){ //each column j in the row i
                if(ocean[row][col] == '^' && canMove(ocean, row, col)){
                    temp2.push_back(true);
                }else{
                    temp2.push_back(false);
                }
            }
            willMove.push_back(temp2);
        }
        /* moving the upward movers */
        for(int row = 0; row < height; row++){ //for each row 
            for(int col = 0; col < width; col++){ //each column in the row
                if(willMove[row][col]){
                    ocean[row][col] = '.';
                    if(row == 0){ //checking if we are on the first row
                        ocean[height-1][col] = '^';
                    }else{
                        ocean[row-1][col] = '^';
                    }
                }
            }
        }
        willMove.clear();
        printOcean(ocean);
        cout << endl <<  "step number " << counter << endl << endl;
    }

    cout << "This ocean had a width of " << width << " and a height of " << height << endl;
    cout << "and took " << counter << " iterations to settle." << endl;
    cout << "Would you like to continue? (y/n)  ";
    string response;
    cin >> response;
    if(response == "y"){
        return true;
    }else{
        return false;
    }
}

int main(int argc, char **argv){
    if(argc < 3){
        cout << "Format: ./oceanSS [width] [height]" << endl;
    }

    int width = stoi(argv[1]);
    int height = stoi(argv[2]);

    while(simulateOcean(width, height)){
        //do nothing lol
    }

    return 0;
}
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){
    if(argc < 3){
        cout << "Please use this format: ./scGen [width] [height]" << endl;
        return 1;
    }
    int height = stoi(argv[2]);
    int width = stoi(argv[1]);

    ofstream fout;
    fout.open("ocean.txt");
    
    char item = '.';
    srand(time(NULL));

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int n = rand() % 3;
            switch (n){
            case 0:
                item = '.';
                break;
            case 1:
                item = 'v';
                break;
            case 2:
                item = '>';
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


    return 0;
}
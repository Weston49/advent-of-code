#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Dir{
    int id;
    vector <unsigned long long> files;
    int parent = -1;
    int depth = 0;
    unsigned long long totalSize = 0;
    bool operator<(const Dir &r) const
    {
        if (depth != r.depth) {   
            return depth < r.depth;
}

    return totalSize < r.totalSize;
    }
};

int main(){

    string currentDay = "7";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    Dir tempDir;
    vector <Dir> dirs;
    int previousDir = 0;
    int currentDir = 0;
    int currentDepth = 0;
    dirs.push_back(tempDir);
    getline(fin,line,delim); // throwing out the first line
    while(getline(fin, line, delim)){
        
        if(line[0] == '$'){ // then this is a command
            if(line[2] == 'c'){ // this is a cd command
                if(line[5] == '.'){
                    currentDir--;
                    currentDepth--;
                }else{
                    previousDir = currentDir;
                    currentDir = dirs.size();
                    currentDepth++;
                    dirs.push_back(tempDir);
                    dirs[currentDir].depth = currentDepth;
                    dirs[currentDir].parent = previousDir;
                }
            }
        }else{
            if(line[0] == 'd'){ //this is a dir, just ignore it

            }else{ //this is where file sizes are
                dirs[currentDir].files.push_back(stoi(line.substr(0,line.find(' '))));
            }
        }
    }
    fin.close();
    int total = 0;
    for(int i = 0; i < dirs.size(); i++){
        dirs[i].id = i;
        for(int j = 0; j < dirs[i].files.size(); j++){
            dirs[i].totalSize += dirs[i].files[j];
        }
    }

    sort(dirs.begin(),dirs.end());

    for(int i = dirs.size()-1; i > 0; i--){
        for(int j = 0; j < dirs.size(); j++){
            if(dirs[j].id == dirs[i].parent){
                dirs[j].totalSize += dirs[i].totalSize;
            }
        }
    }

    int res = 0;
    for(int i = 0; i < dirs.size(); i++){
        if(dirs[i].totalSize <= 100000){
            res += dirs[i].totalSize;
        }
    }

    cout << res << endl;

    return 0;
}
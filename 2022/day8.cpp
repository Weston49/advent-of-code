#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int treeVisible(vector < vector <int> > trees, int y, int x) {
    int height = trees.size();
    int width = trees[0].size();
    int cnt = 0;
    int left = 0;
    int right = 0;
    int up = 0;
    int down = 0;

    for (int i = x - 1; i >= 0; i--) {
        if (trees[y][i] >= trees[y][x]) {
            left++;
            break;
        }
        else {
            left++;
        }
    }
    for (int i = x + 1; i < width; i++) {
        if (trees[y][i] >= trees[y][x]) {
            right++;
            break;
        }
        else {
            right++;
        }
    }
    for (int i = y - 1; i >= 0; i--) {
        if (trees[i][x] >= trees[y][x]) {
            up++;
            break;
        }
        else {
            up++;
        }
    }
    for (int i = y + 1; i < height; i++ ) {
        if (trees[i][x] >= trees[y][x]) {
            down++;
            break;
        }
        else{
            down++;
        }
    }

    //cout << up << " " << down << " " << left << " " << right << endl;
    return up * down * left * right;
}

int main() {
    string currentDay = "8";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    vector < vector <int> > trees;

    while (getline(fin, line, delim)) {
    vector<int> row;
    for(int i = 0; i < line.length(); i++) {
            row.push_back(int(line[i]) - 48);
        }
        trees.push_back(row);
    }

    int height = trees.size();
    int width = trees[0].size();
    int total = 0;
    int tmp = 0;
    vector <int> scores;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                total++;
                tmp ++;
            }
            else{
                scores.push_back(treeVisible(trees, i, j));
            }
        }
    }
    cout << *max_element(scores.begin(), scores.end()) << endl;

}
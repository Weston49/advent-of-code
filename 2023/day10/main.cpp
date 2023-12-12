#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

void DFS2(vector<string> &pipes, int r, int c){
  if(pipes[r][c] == ' ') return;
  pipes[r][c] = ' ';
  if(r < pipes.size()-1 && (pipes[r+1][c] == 'x' || pipes[r+1][c] == 'o')){
    DFS2(pipes, r+1, c);
  }
  if(r > 0 && (pipes[r-1][c] == 'x' || pipes[r-1][c] == 'o')){
    DFS2(pipes, r-1, c);
  }
  if(c < pipes[0].size()-1 && (pipes[r][c+1] == 'x' || pipes[r][c+1] == 'o')){
    DFS2(pipes, r, c+1);
  }
  if(c > 0 && (pipes[r][c-1] == 'x' || pipes[r][c-1] == 'o')){
    DFS2(pipes, r, c-1);
  }
}

int DFS(vector<string> &pipes, vector<string> &visited, int r, int c){
  if(visited[r][c] == 'T') return 0;
  visited[r][c] = 'T';
  char curr = pipes[r][c];
  int total = 1;

  if(curr == 'S'){
    if(r > 0 && (pipes[r-1][c] == '|' || pipes[r-1][c] == 'F' || pipes[r-1][c] == '7')){ // checks up
      total += DFS(pipes, visited, r-1, c);
    }
    if(r < pipes.size()-1 && (pipes[r+1][c] == '|' || pipes[r+1][c] == 'J' || pipes[r+1][c] == 'L')){ // checks down
      total += DFS(pipes, visited, r+1, c);
    }
    if(c > 0 && (pipes[r][c-1] == '-' || pipes[r][c-1] == 'F' || pipes[r][c-1] == 'L')){ //checks left
      total += DFS(pipes, visited, r, c-1);
    }
    if(c < pipes[0].size()-1 && (pipes[r][c+1] == '-' || pipes[r][c+1] == 'J' || pipes[r][c+1] == '7')){ // checks right
      total += DFS(pipes, visited, r, c+1);
    }
  }
  if(curr == '-'){
    if(c > 0 && (pipes[r][c-1] == '-' || pipes[r][c-1] == 'F' || pipes[r][c-1] == 'L')){ //checks left
      total += DFS(pipes, visited, r, c-1);
    }
    if(c < pipes[0].size()-1 && (pipes[r][c+1] == '-' || pipes[r][c+1] == 'J' || pipes[r][c+1] == '7')){ // checks right
      total += DFS(pipes, visited, r, c+1);
    }
  }
  if(curr == '|'){
    if(r > 0 && (pipes[r-1][c] == '|' || pipes[r-1][c] == 'F' || pipes[r-1][c] == '7')){ //checks up
      total += DFS(pipes, visited, r-1, c);
    }
    if(r < pipes.size()-1 && (pipes[r+1][c] == '|' || pipes[r+1][c] == 'J' || pipes[r+1][c] == 'L')){ //checks down
      total += DFS(pipes, visited, r+1, c);
    }
  }
  if(curr == '7'){
    if(c > 0 && (pipes[r][c-1] == '-' || pipes[r][c-1] == 'F' || pipes[r][c-1] == 'L')){ //checks left
      total += DFS(pipes, visited, r, c-1);
    }
    if(r < pipes.size()-1 && (pipes[r+1][c] == '|' || pipes[r+1][c] == 'J' || pipes[r+1][c] == 'L')){ // checks down
      total += DFS(pipes, visited, r+1, c);
    }
  }
  if(curr == 'J'){
    if(c > 0 && (pipes[r][c-1] == '-' || pipes[r][c-1] == 'F' || pipes[r][c-1] == 'L')){ //checks left
      total += DFS(pipes, visited, r, c-1);
    }
    if(r > 0 && (pipes[r-1][c] == '|' || pipes[r-1][c] == 'F' || pipes[r-1][c] == '7')){ //checks up
      total += DFS(pipes, visited, r-1, c);
    }
  }
  if(curr == 'L'){
    if(r > 0 && (pipes[r-1][c] == '|' || pipes[r-1][c] == 'F' || pipes[r-1][c] == '7')){ //checks up
      total += DFS(pipes, visited, r-1, c);
    }
    if(c < pipes[0].size()-1 && (pipes[r][c+1] == '-' || pipes[r][c+1] == 'J' || pipes[r][c+1] == '7')){ // checks right
      total += DFS(pipes, visited, r, c+1);
    }
  }
  if(curr == 'F'){
    if(c < pipes[0].size()-1 && (pipes[r][c+1] == '-' || pipes[r][c+1] == 'J' || pipes[r][c+1] == '7')){ // checks right
      total += DFS(pipes, visited, r, c+1);
    }
    if(r < pipes.size()-1 && (pipes[r+1][c] == '|' || pipes[r+1][c] == 'J' || pipes[r+1][c] == 'L')){ // checks down
      total += DFS(pipes, visited, r+1, c);
    }
  }
  return total;
}

int main(){
  string s;
  size_t i, j;
  vector<string> pipes;
  vector<string> loop;
  int total_r, total_c;
  int sR, sC;

  total_r = 0;
  while(cin >> s){
    pipes.push_back(s);
    total_r++;
  }
  total_c = s.size();
  s = "";
  s.resize(total_c, 'F');
  loop.resize(total_r, s);

  for(i = 0; i < pipes.size(); i++){
    for(j = 0; j < pipes[i].size(); j++){
      if(pipes[i][j] == 'S'){
        sR = i;
        sC = j;
      }
      // cout << loop[i][j];
    }
    // cout << endl;
    // cout << pipes[i] << endl;
  }


  int total = DFS(pipes, loop, sR, sC);
  cout << total << endl;

  for(i = 0; i < loop.size(); i++){
    for(j = 0; j < loop[i].size(); j++){
      //if(loop[i][j] == 'T') pipes[i][j] = 'P';
    }
  }

  for(i = 0; i < pipes.size(); i++){
    for(j = 0; j < pipes[i].size(); j++){
      if(loop[i][j] == 'T'){
        //cout << pipes[i][j];
      }else if(pipes[i][j] != '.'){
        pipes[i][j] = 'x';
      }else{
        pipes[i][j] = 'o';
      }
    }
    //cout << endl;
  }
  DFS2(pipes, 0, 0);
  pipes[sR][sC] = 'S';
  for(i = 0; i < pipes.size(); i++){
    for(j = 0; j < pipes[i].size(); j++){
      if(pipes[i][j] == 'x'){
        cout << ".";
        pipes[i][j] = ' ';
      }else if(pipes[i][j] == '7'){
        cout << "┐";
      }else if(pipes[i][j] == 'J'){
        cout << "┘";
      }else if(pipes[i][j] == '-'){
        cout << "─";
      }else if(pipes[i][j] == 'L'){
        cout << "└";
      }else if(pipes[i][j] == 'F'){
        cout << "┌";
      }else if(pipes[i][j] == 'o'){
        cout << ".";
      }else if(pipes[i][j] == '|'){
        cout << "|";
      }else if(pipes[i][j] == 'S'){
        cout << "─";
      }else{
        cout << ".";
      }
    }
    cout << endl;
  }



  //cout << total_c << " " << total_r << endl;
  //cout << sR << " " << sC << endl;

  return 0;
}

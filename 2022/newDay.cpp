#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv){

  if(argc != 2){
    cerr << "usage: ./newDay [day]" << endl;
    return 1;
  }
  string day(argv[1]);

  string filename = "day" + day + ".cpp";
  string txtFilename = "inputs/day" + day + ".txt";

  ofstream fout(filename);
  fout << "#include <iostream>\n";
  fout << "#include <sstream>\n";
  fout << "#include <fstream>\n";
  fout << "#include <string>\n";
  fout << "#include <vector>\n";
  fout << "#include <iomanip>\n";
  fout << "#include <algorithm>\n";
  fout << "#include <cstdio>\n";
  fout << "\n";
  fout << "using namespace std;\n";
  fout << "\n";
  fout << "int main(){\n";
  fout << "\n";
  fout << "    string currentDay = \"" + day + "\";\n";
  fout << "    char delim = '\\n';\n";
  fout << "    int i,j,k;\n";
  fout << "\n";
  fout << "    /* Opens the file and begins to read it in line by line */\n";
  fout << "    string line;\n";
  fout << "    fstream fin;\n";
  fout << "    fin.open(\"./inputs/day\" + currentDay + \".txt\");\n";
  fout << "\n";
  fout << "\n";
  fout << "\n";
  fout << "    while(getline(fin, line, delim)){\n";
  fout << "\n";
  fout << "\n";
  fout << "\n";
  fout << "    }\n";
  fout << "\n";
  fout << "    return 0;\n";
  fout << "}\n";
  fout.close();
  ofstream fout2(txtFilename);
  fout2 << "";

  return 0;
}
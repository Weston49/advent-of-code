#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Monkey{
    public: 
        vector <unsigned long long> items;
        char operation;
        int operationValue; //-1 for old
        int test;
        int trueMonkey;
        int falseMonkey;
        int inspections;
};

vector <int> adv_tokenizer(string s, char del){
    vector <int> temp;
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        temp.push_back(stoi(word));
    }
    return temp;
}

int main(){

    string currentDay = "11";
    char delim = '\n';

    /* Opens the file and begins to read it in line by line */
    string line;
    fstream fin;
    fin.open("./inputs/day" + currentDay + ".txt");

    //room for variables

    int counter = 0;
    Monkey mTemp;
    vector <Monkey> monkies;
    string s;
    vector <int> tempItems;
    while(getline(fin, line, delim)){
        if(line[0] == 'M'){
            //new monkey 
            counter = 0;
            mTemp.inspections = 0;
            mTemp.items.clear();
        }else{
            switch (counter){
            case 0:
                //adding items
                tempItems.clear();
                tempItems = adv_tokenizer(line.substr(17), ',');
                for(int i = 0; i < tempItems.size(); i++){
                    mTemp.items.push_back(tempItems[i]);
                }
                counter++;
                break;
            case 1:
                //set operations 
                int opVal;
                if(line[25] == 'o'){
                    opVal = -1;
                }else{
                    opVal = stoi(line.substr(25));
                }
                mTemp.operationValue = opVal;
                mTemp.operation = line[23];
                counter++;
                break;
            case 2:
                //set test value
                mTemp.test = stoi(line.substr(21));
                counter++;
                break;
            case 3:
                //set true monkey
                mTemp.trueMonkey =  stoi(line.substr(29));
                counter++;
                break;
            case 4:
                //set false monket
                mTemp.falseMonkey =  stoi(line.substr(29));
                monkies.push_back(mTemp);
                counter++;
                break;
            default:
                break;
            }
        }
    }
    fin.close();

    int rounds = 10000;
    int opVal;
    int sumOfTests = 1;
    for(int i = 0; i < monkies.size(); i++){
        sumOfTests *= monkies[i].test;
    }
    for(int round = 0; round < rounds; round++){
        for(int monkey = 0; monkey < monkies.size(); monkey++){
            for(int item = 0; item < monkies[monkey].items.size(); item++){
                monkies[monkey].inspections++;
                if(monkies[monkey].operationValue == -1){
                    opVal = monkies[monkey].items[item];
                }else{
                    opVal = monkies[monkey].operationValue;
                }
                if(monkies[monkey].operation == '+'){
                    monkies[monkey].items[item] += opVal;
                }else{
                    monkies[monkey].items[item] *= opVal;
                }

                //monkies[monkey].items[item] = monkies[monkey].items[item] / 3; //gets bored
                monkies[monkey].items[item] = monkies[monkey].items[item] % sumOfTests; 

                if(monkies[monkey].items[item] % monkies[monkey].test == 0){
                    monkies[monkies[monkey].trueMonkey].items.push_back(monkies[monkey].items[item]);
                }else{
                    monkies[monkies[monkey].falseMonkey].items.push_back(monkies[monkey].items[item]);
                }
            }
            monkies[monkey].items.clear();
        }
    }
    vector <unsigned long long> totals;
    for(int i = 0; i < monkies.size(); i++){
        cout << "Monkey " << i;
        cout << " : " << monkies[i].inspections;
        cout << endl;
        totals.push_back(monkies[i].inspections);
    }

    sort(totals.begin(), totals.end());
    reverse(totals.begin(), totals.end());

    cout << totals[0] * totals[1] << endl;

    return 0;
}
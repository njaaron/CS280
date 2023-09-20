#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[]){
    string fileName;
    if(argc > 1){
        fileName = argv[1];
    }
    else{
        cout << "NO SPECIFIED INPUT FILE NAME." << endl;
        exit(1);
    }
    ifstream inFile;
    inFile.open(fileName);
    if(!inFile){
        cout << "CANNOT OPEN THE FILE " << fileName << endl;
        exit(1);
    }
    if(inFile.peek() == std::ifstream::traits_type::eof()){
        cout << "File is empty." << endl;
        return 0;
    }
    map<int, int> integer;
    map<float, int> real;
    map<string, int> special;
    string words;
    int specialCount = 0;
    int integerCount = 0;
    int realCount = 0;
    while(inFile >> words){
        if(isdigit(words[0]) || ((words[0] == '-' || words[0] == '+') && isdigit(words[1]))){
            int i = 1;
            while(i < words.size() && isdigit(words[i])){
                i++;
            }
            if(i == words.size()){
                integerCount++;
                if (words[0] == '+') {
                  words = words.substr(1);
                }
                if(integer.count(stof(words)) == 0){
                    integer[stof(words)] = 1;
                } else{
                    integer[stof(words)]++;
                }
            } else if(words[i] == '.' && isdigit(words[i + 1])){
                int j = i + 1;
                while(j < words.size() && isdigit(words[j])){
                    j++;
                }
                if(j == words.size()){
                    realCount++;
                    if (words[0] == '+') {
                  words = words.substr(1);
                }
                    if(real.count(stof(words)) == 0){
                        real[stof(words)] = 1;
                    } else{
                        real[stof(words)]++;
                    }
                }
            }
        } else if(words[0] == '$' && isalpha(words[1])){
            int i = 1;
            while(i < words.size() && (isalnum(words[i]) || words[i] == '_')){
                i++;
            }
            if(i == words.size()){
                specialCount++;
                if(special.count(words) == 0){
                    special[words] = 1;
                } else{
                    special[words]++;
                }
            }
        }
    }
    inFile.close();
    cout << "Number of integers in the file: " << integerCount << endl;
    cout << "Number of reals in the file: " << realCount << endl;
    cout << "Number of special names in the file: " << specialCount << endl;
    if(integer.size() > 0){
        cout << endl;
        cout << "List of integer values and their number of occurrences:" << endl;
        for(auto &i : integer){
            cout << i.first << ": " << i.second << endl;
        }
    }
    if(real.size() > 0){
        cout << endl;
        cout << "List of real values and their number of occurrences:" << endl;
        for(auto &i : real){
            cout << i.first << ": " << i.second << endl;
        }
    }
    if(special.size() > 0){
        cout << endl;
        cout << "List of special names and their number of occurrences:" << endl;
        for(auto &i : special){
            cout << i.first << ": " << i.second << endl;
        }
    }
    return 0;
}
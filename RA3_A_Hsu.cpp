#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
bool specialName(string words, char special){
    if(words.length() < 2){
        return false;
    }
    if(words[0] != special){
        return false;
    }
    for(int i = 1; i < words.length(); i++){
        if(!isalnum(words[i]) && words[i] != '_'){
            return false;
        }
    }
    return true;
}
int countSpecialName(string fileName, char special){
    ifstream openFile(fileName);
    if(!openFile.is_open()){
        cout << "CANNOT OPEN THE FILE " << fileName << endl;
        return 0;
    }
    int count = 0;
    string readLine;
    while(getline(openFile, readLine)){
        istringstream issReadLine(readLine);
        string words;
        while(issReadLine >> words){
            if(specialName(words, special)){
                count++;
            }
        }
    }
    openFile.close();
    return count;
}
int countWords(string fileName, char special){
    ifstream openFile(fileName);
    if(!openFile.is_open()){
        cout << "CANNOT OPEN THE FILE " << fileName << endl;
        return 0;
    }
    int count = 0;
    string readLine;
    while(getline(openFile, readLine)){
        istringstream issReadLine(readLine);
        string words;
        while(issReadLine >> words){
            count++;
        }
    }
    openFile.close();
    return count;
}
int main(int argc, char* argv[]){
    if(argc < 2){
        cout << "NO SPECIFIED INPUT FILE NAME." << endl;
        return 0;
    }
    string fileName = argv[1];
    ifstream openFile(fileName);
    if(!openFile.is_open()){
        cout << "CANNOT OPEN THE FILE " << fileName << endl;
        return 0;
    }
    openFile.close();
    int type1 = countSpecialName(fileName, '$');
    int type2 = countSpecialName(fileName, '@');
    int all = countWords(fileName, '$');
    if(all == 0){
        cout << "File is empty." << endl;
        return 0;
    }
    if(argc == 2){
        cout << "Total number of words: " << all << endl;
        cout << "Total number of Type 1 and Type 2 names: " << type1+type2 << endl;
        return 0;
    }
    string flag = argv[2];
    if(flag == "-all"){
        cout << "Total number of words: " << all << endl;
        cout << "Number of Type 1 names: " << type1 << endl;
        cout << "Number of Type 2 names: " << type2 << endl;
    } else if(flag == "-type1"){
        cout << "Number of Type 1 names: " << type1 << endl;
    } else if(flag == "-type2"){
        cout << "Number of Type 2 names: " << type2 << endl;
    } else{
        cout << "UNRECOGNIZED FLAG -alls" << endl;
    }
    return 0;
}
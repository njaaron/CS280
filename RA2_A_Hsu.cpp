#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string fileName;
    cout << "Enter the name of a file to read from:\n" << endl;
    cin >> fileName;
    int totalNumberLines = 0;
    int numberCommentedLines = 0;
    int maxLengthCommentedLines = 0;
    int maxLengthNonCommentedLines = 0;
    string commentedLineMaxLength = "";
    string nonCommentedLineMaxLength = "";
    ifstream openFile(fileName);
    if(!openFile.is_open()){
        cout << "File cannot be opened " << fileName << "\n";
        return 0;
    }
    while(!openFile.eof()){
        string readLine;
        getline(openFile, readLine);
        totalNumberLines++;
        if(readLine.substr(0,2) == "//" || readLine.substr(0,2) == "##"){
            numberCommentedLines++;
            if(readLine.length() > maxLengthCommentedLines){
                maxLengthCommentedLines = readLine.length();
                commentedLineMaxLength = readLine;
            }
        } else if(readLine.length() > maxLengthNonCommentedLines){
            maxLengthNonCommentedLines = readLine.length();
            nonCommentedLineMaxLength = readLine;
        }
    }
    cout << "Total Number of Lines: " << totalNumberLines-1 << "\n";
    cout << "Number of commented lines: " << numberCommentedLines << "\n";
    cout << "Maximum Length of commented lines: " << maxLengthCommentedLines << "\n";
    cout << "Maximum Length of non-commented lines: " << maxLengthNonCommentedLines << "\n";
    cout << "Commented line of maximum length: \"" << commentedLineMaxLength << "\"\n";
    cout << "Non-commented line of maximum length: \"" << nonCommentedLineMaxLength << "\"\n"; 
    openFile.close();
    return 0;
}
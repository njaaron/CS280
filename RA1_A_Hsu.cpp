#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Welcome to CS 280 in Spring 2023 Semester\n";
    string first;
    string last;
    cout << "Please enter your first name\n";
    cin >> first;
    cout << "Please enter your last name\n";
    cin >> last;
    cout << "Welcome " << first << " " << last << " to CS 280\n";
    return 0;
}
#include <iostream>
#include <stack>
#include <map>
#include <regex>
#include <sstream>
using namespace std;
bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}
bool isVariable(char c){
    return c >= 'A' && c <= 'Z';
}
void PostfixEval(string instr){
    stack<int> s;
    map<char, int> variables;
    regex numbers("[0-9]+");
    regex var("[$]?[a-zA-z]");
    stringstream in(instr);
    string token;
    while(in >> token){
        if(regex_match(token, numbers)){
            s.push(stoi(token));
        }else if(regex_match(token, var)){
            if(s.empty()){
                cout << "Error: Incomplete input postfix expression." << endl;
                return;
            }else{
                if(token[0] == '$'){
                    s.push(variables[token[1]]);
                }else{
                    variables[token[0]] = s.top();
                    s.pop();
                }
            }
        }else{
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch (token[0]){
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
                default: cout << "Error: Invalid string \"" << instr << "\"" << endl;
            }
        }
    }
    if (s.size() != 1){
        cout << "The evaluation is incomplete, missing input operators." << endl;
    }else{
        cout << "The result of evaluating the postfix expression \"" << instr << "\" is the value: " << s.top() << endl;
    }
}
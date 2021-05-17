// usestack.cpp - for CS 24 lab practice using stacks
// NAME(S), DATE

#include "intstack.h"
#include <iostream>
#include <string>
using namespace std;
//Precondition: I. Numbers in string are single digit numbers
//II: Organized in PostFix Order (numbers first/operations second)
//III: Operations supported are +-*/%
//Postcondition: Returns the evaluated expression
int PostFixEval(string expr) {
    Stack s;
    int right(0), left(0);
    for (char c: expr) {
        if(isdigit(c)) {
            int k = c - 48;
            s.push(k);
        }
        else if(c == ' '){}
        else if(c == '+'){
            right = s.top(); s.pop();
            left = s.top(); s.pop();
            s.push(right+left);
        }
        else if(c == '*'){
            right = s.top(); s.pop();
            left = s.top(); s.pop();
            s.push(right*left);
        }
        else if(c == '-'){
            right = s.top(); s.pop();
            left = s.top(); s.pop();
            s.push(right-left);
        }
        else if(c == '/'){
            right = s.top(); s.pop();
            left = s.top(); s.pop();
            s.push(right/left);
        }
        else if(c == '%'){
            right = s.top(); s.pop();
            left = s.top(); s.pop();
            s.push(right%left);
        }

        else {cerr << endl << "INVALID EXPRESSION" << endl;}

    }
    return s.top();
}

int main() {
    Stack s;

    s.push(10);
    s.push(20);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}

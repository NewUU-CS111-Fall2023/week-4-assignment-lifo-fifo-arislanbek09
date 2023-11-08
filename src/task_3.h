/*
 * Author: Arislanbek Kalbaev
 * Date: November 3, 2023
 * Name: Arislanbek Kalbaev
*/

#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int calcExpression(string expression) {
    stack<int> stk;
    stringstream ss(expression);
    string token;

    while (getline(ss, token, ' ')) {
        if (isdigit(token[0])) {
            stk.push(stoi(token));
        } else {
            int operand2 = stk.top();
            stk.pop();
            int operand1 = stk.top();
            stk.pop();

            int res;
            if (token == "+") {
                res = operand1 + operand2;
            } else if (token == "-") {
                res = operand1 - operand2;
            } else if (token == "*") {
                res = operand1 * operand2;
            } else {
                cout << "Invalid operator: " << token << endl;
                return 0;
            }

            stk.push(res);
        }
    }

    return stk.top();
}

int main() {
    string expression;
    cout << "Enter the expression in postfix notation: " << endl;
    getline(cin, expression);

    int result = calcExpression(expression);
    cout << "Result: " << res << endl;

    return 0;
}

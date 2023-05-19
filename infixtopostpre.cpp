#include <iostream>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;
unordered_set<char> operators = {'+', '-', '*', '/', '(', ')'};
unordered_map<char, int> PRI = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
string infix_to_postfix(string formula) {
    stack<char> s;
    string output = "";
    for (char ch : formula) {
        if (operators.find(ch) == operators.end()) {
            output += ch;
        } else if (ch == '(') {
            s.push('(');
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                output += s.top();
                s.pop();
            }
            s.pop();  // pop '('
        } else {
            while (!s.empty() && s.top() != '(' && PRI[ch] <= PRI[s.top()]) {
                output += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        output += s.top();
        s.pop();
    }
    cout << "POSTFIX: " << output << endl;
    return output;
}
string infix_to_prefix(string formula) {
    stack<char> op_stack;
    stack<string> exp_stack;
    for (char ch : formula) {
        if (operators.find(ch) == operators.end()) {
            exp_stack.push(string(1, ch));
        } else if (ch == '(') {
            op_stack.push(ch);
        } else if (ch == ')') {
            while (op_stack.top() != '(') {
                char op = op_stack.top();
                op_stack.pop();
                string a = exp_stack.top();
                exp_stack.pop();
                string b = exp_stack.top();
                exp_stack.pop();
                exp_stack.push(op + b + a);
            }
            op_stack.pop();
        } else {
            while (!op_stack.empty() && op_stack.top() != '(' && PRI[ch] <= PRI[op_stack.top()]) {
                char op = op_stack.top();
                op_stack.pop();
                string a = exp_stack.top();
                exp_stack.pop();
                string b = exp_stack.top();
                exp_stack.pop();
                exp_stack.push(op + b + a);
            }
            op_stack.push(ch);
        }
    }
    while (!op_stack.empty()) {
        char op = op_stack.top();
        op_stack.pop();
        string a = exp_stack.top();
        exp_stack.pop();
        string b = exp_stack.top();
        exp_stack.pop();
        exp_stack.push(op + b + a);
    }
    cout << "PREFIX: " << exp_stack.top() << endl;
    return exp_stack.top();
}
int main() {
    cout<<"Aditya Saxena\n";
    string expression;
    cout << "INPUT THE EXPRESSION: ";
    getline(cin, expression);
    string prefix = infix_to_prefix(expression);
    string postfix = infix_to_postfix(expression);
    return 0;
}

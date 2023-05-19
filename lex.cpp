#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
string arr[] = { "void", "using", "namespace", "int", "include", "iostream", "std", "main","cin", "cout", "return", "float", "double", "string" };
bool isKeyword(string a) {
    for (int i = 0; i < 14; i++) {
        if (arr[i] == a) {
            return true;
        }
    }
    return false;
}
int main() {
    string input;
    cout << "Enter the program code: ";
    getline(cin, input);
    string s;
    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            if (s != "") {
                if (isKeyword(s)) {
                    cout << s << " is a keyword\n";
                } else if (s == "+" || s == "-" || s == "" || s == "/" || s == "^" || s == "&&" || s == "||" || s == "=" || s == "==" || s == "&" || s == "|" || s == "%" || s == "++" || s == "--" || s == "+=" || s == "-=" || s == "/=" || s == "=" || s == "%=") {
                    cout << s << " is an operator\n";
                } else if (s == "(" || s == "{" || s == "[" || s == ")" || s == "}" || s == "]" || s == "<" || s == ">" || s == "()" || s == ";" || s == "<<" || s == ">>" || s == "," || s == "#") {
                    cout << s << " is a symbol\n";
                } else if (isdigit(s[0])) {
                    int x = 0;
                    if (!isdigit(s[x++])) {
                        continue;
                    } else {
                        cout << s << " is a constant\n";
                    }
                } else {
                    cout << s << " is an identifier\n";
                }
                s = "";
            }
        } else {
            s += c;
        }
    }
    return 0;
}

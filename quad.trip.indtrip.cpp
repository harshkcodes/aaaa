#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Quadruple{
    string op;
    string arg1;
    string arg2;
    string result;
};
struct Triple{
    string op;
    string arg1;
    string arg2;
};
vector<Triple> triples;
vector<Quadruple> quadruples;
int main() {
    string expr;
    cout << "Enter an arithmetic expression:";
    getline(cin, expr);
    vector<string> tokens;
    string token;
    for(char c : expr) {
        if (c == ' ' || c == '\t')
            continue;
        if (isdigit(c))
            token += c;
        else {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(string(1, c));
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    vector<string> t1=tokens;
    int temp_num = 0;
    string temp_prefix = "t";
    string temp;
    for (size_t i = 0; i < t1.size(); i++) {
        string token = t1[i];
        if (token == "*" || token == "/") {
            Quadruple q;
            q.op = token;
            q.arg1 = t1[i-1];
            q.arg2 = t1[i+1];
            q.result = temp_prefix + to_string(temp_num);
            temp_num++;
            quadruples.push_back(q);
            t1[i-1] = q.result;
            t1.erase(t1.begin() + i, t1.begin() + i + 2);
            i--;
        }
    }
    for (size_t i = 0; i < t1.size(); i++) {
        string token = t1[i];
        if (token == "+" || token == "-") {
            Quadruple q;
            q.op = token;
            q.arg1 = t1[i-1];
            q.arg2 = t1[i+1];
            q.result = temp_prefix + to_string(temp_num);
            temp_num++;
            quadruples.push_back(q);
            t1[i-1] = q.result;
            t1.erase(t1.begin() + i, t1.begin() + i + 2);
            i--;
        }
    }
    cout << "Quadruples:" << endl;
    for (const Quadruple& q : quadruples) {
        cout << q.op << " " << q.arg1 << " " << q.arg2 << " " << q.result << endl;
    }
    int temp_num2 = 0;
    string temp2;
    for (size_t i = 0; i < tokens.size(); i++) {
        string token = tokens[i];
        if (token == "*" || token == "/") {
            Triple t;
            t.op = token;
            t.arg1 = tokens[i-1];
            t.arg2 = tokens[i+1];
            triples.push_back(t);
            tokens[i-1] = to_string(temp_num2);
            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            i--;
            temp_num2++;
        }
    }
    for (size_t i = 0; i < tokens.size(); i++) {
        string token = tokens[i];
        if (token == "+" || token == "-") {
            Triple t;
            t.op = token;
            t.arg1 = tokens[i-1];
            t.arg2 = tokens[i+1];
            triples.push_back(t);
            tokens[i-1] = to_string(temp_num2);
            tokens.erase(tokens.begin() + i, tokens.begin() + i + 2);
            i--;
            temp_num2++;
        }
    }
    Triple t;
    t.op = "=";
    t.arg1 = tokens[0];
    t.arg2 = "";
    triples.push_back(t);
    cout << "Triples:\n";
    for (Triple t : triples) {
        cout << t.op << " " << t.arg1 << " " << t.arg2 << endl;
    }
    cout << "Indirect Triples:\n";
    int id=100;
    int ids=0;
    for (Triple t : triples) {
        cout<<id<<" "<<ids<<endl;
        id+=1;
        ids+=1;
    }
    return 0;
}
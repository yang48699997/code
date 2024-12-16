#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

string filename = "";
string input = "";

/* 
E->E+T
E->E-T
E->T
T->T*F
T->T/F
T->F
F->(E)
F->n
*/

string getInput(){
    if(input == ""){
        char c;
        string s;
        while(cin.get(c)){
            s+=c;
        }
        return s;
    }
    return input;
}

string getFilename(){
    if(filename == ""){
        char s[20];
        cin.getline(s,20);
        string fs = "/data/workspace/myshixun/src/step1/";
        return fs + string(s).substr(2,20);
    }
    return filename;
}

int main(){
    // filename = getFilename();
    // input = getInput();
    cin >> input;
    
    string stk;

    for (int i = 0; i < input.size(); i++) {
        char c = input[i];
        if (c == '(') {
            stk += c;
        } else if (c >= '0' && c <= '9') {
            cout << "F->n" << "\n";
            input[i] = 'F';
            i--;
            continue;
            
        } else if (c == ')') {
            int n = stk.size();
            if (stk.substr(n - 2, 2) == "(E") {
                cout << "F->(E)" << "\n";
                stk.pop_back();
                stk.pop_back();
            } else if (stk.substr(n - 2, 2) == "(F") {
                cout << "T->F" << "\n";
                cout << "E->T" << "\n";
                cout << "F->(E)" << "\n";
                stk.pop_back();
                stk.pop_back();
            } else if (stk.substr(n - 2, 2) == "(T") {
                cout << "E->T" << "\n";
                cout << "F->(E)" << "\n";
                stk.pop_back();
                stk.pop_back();
            }
            input[i] = 'F';
            i--;
        } else if (c == '+') {
            if (stk.back() == 'F') {
                cout << "T->F" << "\n";
                stk.back() = 'T';
            }
            if (stk.back() == 'T') {
                cout << "E->T" << "\n";
                stk.back() = 'E';
            }
            stk += c;
        } else if (c == '-') {
            if (stk.back() == 'F') {
                cout << "T->F" << "\n";
                stk.back() = 'T';
            }
            if (stk.back() == 'T') {
                cout << "E->T" << "\n";
                stk.back() = 'E';
            }
            stk += c;
        } else if (c == '/' || c == '*') {
            if (stk.back() == 'F') {
                cout << "T->F" << "\n";
                stk.back() = 'T';
            }
            stk += c;
        } else if (c == 'F') {
            if (!stk.empty() && stk.back() == '+') {
                if (i != input.size() - 1 && (input[i + 1] == '/' || input[i + 1] == '*')) {
                    stk += 'F';
                    continue;
                }
                cout << "T->F" << "\n";
                cout << "E->E+T" << "\n";
                stk.pop_back();
                stk.pop_back();
                stk += "E";
            } else if (!stk.empty() && stk.back() == '-') {
                if (i != input.size() - 1 && (input[i + 1] == '/' || input[i + 1] == '*')) {
                    stk += 'F';
                    continue;
                }
                cout << "T->F" << "\n";
                cout << "E->E-T" << "\n";
                stk.pop_back();
                stk.pop_back();
                stk += "E";
            } else if (!stk.empty() && stk.back() == '*') {
                cout << "T->T*F" << "\n";
                stk.pop_back();
                stk.pop_back();
                input[i] = 'T';
                i--;
            } else if (!stk.empty() && stk.back() == '/') {
                cout << "T->T/F" << "\n";
                stk.pop_back();
                stk.pop_back();
                input[i] = 'T';
                i--;
            } else {
                stk += "F";
            }
        } else if (c == 'T') {
            if (!stk.empty() && stk.back() == '+') {
                if (i != input.size() - 1 && (input[i + 1] == '/' || input[i + 1] == '*')) {
                    stk += 'T';
                    continue;
                }
                cout << "E->E+T" << "\n";
                stk.pop_back();
                stk.pop_back();
                stk += "E";
            } else if (!stk.empty() && stk.back() == '-') {
                if (i != input.size() - 1 && (input[i + 1] == '/' || input[i + 1] == '*')) {
                    stk += 'T';
                    continue;
                }
                cout << "E->E-T" << "\n";
                stk.pop_back();
                stk.pop_back();
                stk += "E";
            } else if (!stk.empty() && stk.back() == '*') {
                cout << "T->T*F" << "\n";
                stk.pop_back();
                stk.pop_back();
                input[i] = 'T';
                i--;
            } else if (!stk.empty() && stk.back() == '/') {
                cout << "T->T/F" << "\n";
                stk.pop_back();
                stk.pop_back();
                input[i] = 'T';
                i--;
            } else {
                stk += "T";
            }
        } 
        // cerr << stk << "\n";
    }
    if (stk.back() == 'F') {
        cout << "T->F" << "\n";
        stk.back() = 'T';
    }
    if (stk.back() == 'T') {
        cout << "E->T" << "\n";
        stk.back() = 'E';
    }
    
    return 0;
}
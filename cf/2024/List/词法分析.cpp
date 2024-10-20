#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
string filename = "";
string input = "";

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
        string fs = "/data/workspace/myshixun/词法分析C/src/step1/";
        return fs + string(s).substr(2,20);
    }
    return filename;
}

int main(){
    filename = getFilename();
    string s = getInput();
    
    int n = s.size();
    int row = 1;
    int tot = 0;
    int word = 0;
    int keyWord = 0;
    int constNumber = 0;
    int assign = 0;
    int operation = 0;
    int iso = 0;

    
    set<string> KeyWord = {
        "int",
        "for",
        "while",
        "char",
        "float",
        "char",
        "return",
        "void",
        "if",
        "else"
    };
    set<string> Assign = {
        "=",
        "+=",
        "/=",
        "*=",
        "-="
    };
    set<char> ISO = {
        ';',
        '(',
        ')',
        '[',
        ']',
        '{',
        '}'
    };
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') continue;
        else if (s[i] == '\n') {
            row++;
        } else if (s[i] == '/' && i + 1 < n && s[i + 1] == '/') {
            while (s[i] != '\n') {
                i++;
            }
            row++;
        } else if (s[i] == '/' && i + 1 < n && s[i + 1] == '*') {
            i += 2;
            while (!(s[i] == '*' && s[i + 1] == '/')) i++;
            i++;
        } else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            string now;
            while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                now += s[i];
                i++;
            }
            if (KeyWord.count(now)) {
                keyWord++;
                cout << now << "关键字\n";
            } else {
                word++;
                cout << now << "标识符\n";
            } 
            i--;
            tot++;
        } else if (s[i] >= '0' && s[i] <= '9') {
            string now;
            while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
                now += s[i];
                i++;
            }
            i--;
            constNumber++;
            cout << now << "常数\n";
            tot++;
        } else if (ISO.count(s[i])) {
            iso++;
            cout << s[i] << "分隔符\n";
            tot++;
        } else {
            string now = "";
            now += s[i];
            if (i + 1 < n && s[i + 1] == '=') {
                i++;
                now += s[i];
                if (now == "+=" || now == "-=" || now == "/=" || now == "*=") {
                    assign++;
                    cout << now << "赋值\n";
                } else {
                    operation++;
                    cout << now << "运算符\n";
                }
            } else if (i + 1 < n && s[i + 1] == s[i]) {
                i++;
                now += s[i];
                operation++;
                cout << now << "运算符\n";
            } else {
                if (s[i] == '=') {
                    assign++;
                    cout << s[i] << "赋值\n";
                } else {
                    operation++;
                    cout << s[i] << "运算符\n";
                }
            }
            tot++;
        }
    }
    
    cout << row << "行\n";
    cout << tot << "个词语\n";
    cout << keyWord << "关键字\n";
    cout << word << "标识符\n";
    cout << constNumber << "常数\n";
    cout << assign << "赋值\n";
    cout << operation << "运算符\n";
    cout << iso << "分隔符\n";
    return 0;
}
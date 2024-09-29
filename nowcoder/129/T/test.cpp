#include <bits/stdc++.h>
using namespace std;

int main() {
    system("g++ -o rand.exe rand.cpp");
    system("g++ -o my.exe my.cpp");
    system("g++ -o std.exe std.cpp");
    while (true) {
        system("rand.exe > data.in");
        system("std.exe < data.in > std.out");
        system("my.exe < data.in > my.out");
        if (system("fc std.out my.out")) {
            system("pause");
            cout << "exit ? (y or n)?" << endl;
            string s;
            cin >> s;
            if (s == "y") return 0;
        }
    }
    return 0;
}
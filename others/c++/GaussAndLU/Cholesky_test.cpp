#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        system("rand.exe > data.in");
        system("cholesky.exe < data.in > cholesky.out");
        if (system("fc cholesky.out wrong.out")) {
            system("pause");
            cout << "exit ? (y or n)?" << endl;
            string s;
            cin >> s;
            if (s == "y") return 0;
        }
    }
    return 0;
}
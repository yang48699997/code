#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (b == 0) {
        if (c == 0) {
            for (int i = 0; i < a; i++) cout << '1';
            cout << "\n";
            for (int i = 0; i < a; i++) cout << '1';
            cout << "\n";
        } else {
            cout << "-1\n";
        }
        return;
    } else if (a == 0) {
        if (c == 0) {
            for (int i = 0; i < b; i++) cout << '0';
            cout << "\n";
            for (int i = 0; i < b; i++) cout << '0';
            cout << "\n";
        } else {
            cout << "-1\n";
        }
        return;
    }
    if (c >= a + b) {
        cout << "-1\n";
        return;
    }
    string x;
    for (int i = 0; i < a + b; i++) {
        if (i < a) x += '1';
        else x += '0';
    }
    if (x[c] == '1') {
        x[c] = '0';
        x.back() = '1';
    }
    
    string y = "0";
    int lef = a;
    for (int i = 1; i < a + b; i++) {
        if (x[i] == '1' && lef) {
            y += '1';
            lef--;
        } else if (i == c) {
            y += '1';
            lef--;
        } else y += '0';
    }
    cout << x << "\n";
    cout << y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
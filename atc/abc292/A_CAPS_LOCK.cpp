#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for (char c : s) {
        c ^= 32;
        cout << c;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
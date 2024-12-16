#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (auto c : s) {
        if (c >= 'a' && c <= 'z') cout << c;
    }
    for (auto c : s) {
        if (c >= '0' && c <= '9') cout << c;
    }
    for (auto c : s) {
        if (c >= 'A' && c <= 'Z') cout << c;
    }
    


    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
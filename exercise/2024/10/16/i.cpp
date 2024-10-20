#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 5; i++) {
        if (s.substr(i, 6) == "bitset") {
            cout << "7as\n";
            return;
        }
    }
    cout << "no 7as for you today\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}